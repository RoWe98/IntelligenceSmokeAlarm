#include <DHT.h>
#include "bj.h"
#include<ESP8266WiFi.h>
#include<U8g2lib.h>
#include <PubSubClient.h>
#include<Adafruit_NeoPixel.h>
#include <ArduinoJson.h>
Adafruit_NeoPixel ring(8, D8);
WiFiClient tcp;
PubSubClient mqtt(tcp);
DHT sensor(D1, DHT11);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C xianshi(U8G2_R0, D3, D4);
int t;
int flag = 1;  //手动开关标志位
int ff = 1; //手机端标志位
int fff = 1; //报警系统总开关
int s = 0;
int requestId;
int ttt;
void ICACHE_RAM_ATTR isr_handler(void) {
  if (millis() - t < 30)
  {
    return;
  }
  t = millis();
}
void mqtt_callback(const char* topic, byte* payload, unsigned int length)
{
  Serial.println(topic);
  payload[length] = 0;
  Serial.println((char*)payload);
  if (String(topic) == "$baidu/iot/shadow/NodeMcu/delta")
  {
    const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 70;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, payload, length);
    boolean sw = doc["desired"]["switch"];
    Serial.println(sw);
    if (sw)
    {
      ff = 1;    //手机端开
    }
    else
    {
      ff = 0;   //手机端关
    }
    const size_t capacity1 = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(1) + 40;
    DynamicJsonDocument reported_doc(capacity1);
    reported_doc["requestId"] = String(requestId++);
    JsonObject reported = reported_doc.createNestedObject("reported");
    reported["switch"] = (fff == 1) ? true : false;
    String msg;
    serializeJson(reported_doc, msg);
    mqtt.publish("$baidu/iot/shadow/NodeMcu/update", msg.c_str());
    Serial.println(msg);
  }
}
void setup() {
  sensor.begin();
  Serial.begin(74880);
  ring.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin("yz", "41609030208yz");
  while (!WiFi.isConnected())
  {
    delay(100);
  }
  configTime(8 * 3600, 0, "pool.ntp.org");

  pinMode(A0, INPUT_PULLUP);
  pinMode(D2, OUTPUT);
  pinMode(D5, INPUT_PULLUP);//开关
  attachInterrupt(digitalPinToInterrupt(D2), isr_handler, FALLING);
  mqtt.setServer("71pip6f.mqtt.iot.gz.baidubce.com", 1883);
  mqtt.setCallback(mqtt_callback);
}

void loop() {

  if (!mqtt.connected())
  {
    Serial.println("connect to MQTT server");
    mqtt.connect("NodeMCU", "71pip6f/NodeMcu", "d720ue1pz1g7nbtn");
    mqtt.subscribe("$baidu/iot/shadow/NodeMcu/delta", 1);
  }
  mqtt.loop();
  if (millis() - ttt > 1000)
  {
    ttt = millis();
    float temp = sensor.readTemperature();//温度
    float humi = sensor.readHumidity();//湿度
    Serial.println(String(temp) + ',' + String(humi));
    Serial.println(analogRead(A0));
    time_t tt = time(nullptr);
    struct tm * lt = localtime(&tt);
    char buffer[80];
    strftime(buffer, 80, "%H:%M:%S", lt);
    Serial.println(buffer);
    xianshi.begin();//初始化
    xianshi.setFont(u8g2_font_wqy16_t_gb2312);
    xianshi.clearBuffer();//清空
    int i = analogRead(A0);
    xianshi.drawUTF8(0, 16, "北京时间:");
    xianshi.drawUTF8(70, 16, buffer);
    xianshi.drawUTF8(0, 32, "室内温度:");
    xianshi.drawUTF8(70, 32, String(temp).c_str());
    xianshi.drawUTF8(112, 32, "℃");
    xianshi.drawUTF8(0, 48, "室内湿度:");
    xianshi.drawUTF8(70, 48, String(humi).c_str());
    xianshi.drawUTF8(117, 48, "%");
    xianshi.drawUTF8(0, 64, "煤气浓度:");
    xianshi.drawUTF8(70, 64, String(i).c_str());
    xianshi.drawUTF8(105, 64, "LEL");
    xianshi.sendBuffer();

    if (digitalRead(D5) == LOW)
    {
      s++;
    }

    if (s % 2 || s == 0)
    {
      flag = 1;
    }
    else
      flag = 0;
    if (flag == 1 && ff == 1)
    {
      fff = 1;
    }
    else
      fff = 0;
    if (i > 90 && fff == 1)
    {
      tone(D2, 500  );
      for (int j = 0; j < 8; j++)
      {
        ring.setPixelColor(j, 255, 0, 0);
      }
      ring.show();
       delay(1000);
      xianshi.clearBuffer();//清空
      xianshi.drawXBM(30, 0, bj_width, bj_height, (uint8_t*)bj_bits);
      xianshi.sendBuffer();
      delay(1000);
    }
    else
    {
      noTone(D2);
      for (int j = 0; j < 8; j++)
      {
        ring.setPixelColor(j, 0, 0, 0);
      }
      ring.show();
    }
    const size_t capacity = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + 40;
    DynamicJsonDocument doc(capacity);
    doc["requestId"] = String(requestId++);
    JsonObject reported = doc.createNestedObject("reported");
    reported["temp"] = temp;
    reported["humi"] = humi;
    reported["iii"] = i;
    reported["switch"] = (fff == 1) ? true : false;
    String msg;
    serializeJson(doc, msg);
    mqtt.publish("$baidu/iot/shadow/NodeMcu/update", msg.c_str());
    Serial.println(msg);
  }
}
