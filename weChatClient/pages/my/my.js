// pages/my/my.js
 //应该在页面加载完以后就应该去连接百度云 并订阅消息
 // mqtt的库
 // 1导入mqtt库
import mqtt from '../../utils/mqtt.js';
 // 通过mqtt协议连接百度云 至少需要的数据  主机名 用户信息
const host = 'wxs://71pip6f.mqtt.iot.gz.baidubce.com/mqtt';
// 订阅消息的地址
const topic ='$baidu/iot/shadow/NodeMcu/update/snapshot';
// 发送消息的指令
const topic2 ='$baidu/iot/shadow/NodeMcu/update';
// 定义一个发送数据的json
var jsonoff = { desired: { switch: false } }; 
var jsonon = { desired: { switch: true } };

     //66 176 56
const options = {
  clientId: "myServerWeChat",
  username: '71pip6f/NodeMcu',
  password: 'd720ue1pz1g7nbtn'

}
Page({
  /**
   * 页面的初始数据
   */
  data: {
    // 先设置一个 连接对象  目前为null
    hidden: false,
    nocancel: false,
    client:null,
    temp:"12",
    humi:"22",
    iii:"100",
    PageCur: 'my',
    progress_txt: '煤气浓度',
    //  和灯相关的字段
    ledvalue: [{
      ledlogo:'/images/LED_gray.png',
      btnvalue:'开灯',
      btnflag:false
    }],
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function () {
    // 存储当前页面的对象
    var that = this;
    // 连接 对象赋值给client
    this.data.client = mqtt.connect(host, options);
    //当连接成功 调用一个回调函数
    that.data.client.on('connect', that.callBack);
    // 回去数据的回到函数
    that.data.client.on('message',that.msgback);
  },
  // 自定义函数  为连接成功的回调
  callBack: function(connack){
    var that = this;
    console.log("连接成功了");
    // 订阅消息
    that.data.client.subscribe(topic,{
      qos:1
    },function(err){
      //判断
      if(!err){
          console.log("订阅成功");
      }
    })
  },
   // 获取消息的回调函数
  msgback: function (topic,message){
    var that = this;
    // 数组
    // console.log( message);
    //转换成字符串
    var strmsg = message.toString();
    console.log(strmsg);
    // 转换成json格式
    var json1 = JSON.parse(strmsg);
    // 给页面设置值
    console.log(json1["reported"]);
    //设置给页面
    that.setData({
      temp: json1["reported"].temp,
      humi: json1["reported"].humi,
      iii: json1["reported"].iii,
    })
    this.onReady(1, (json1["reported"].iii-100)/10);
    console.log(json1["reported"].iii);

  },
  // 点击开关按钮触发函数
  open: function(){
    //
    var that = this;
    // 判断换图
    //if(that.data.ledvalue[0].btnflag){
    that.setData({
       'ledvalue[0].btnvalue': '关闭开关',
       'ledvalue[0].btnflag': false,
       'ledvalue[0].ledlogo': '/images/LED_gray.png'

    })
    // 把switch json变成string
    var str =JSON.stringify(jsonoff);
    console.log(str);
    // 发送指令
    that.data.client.publish(topic2,str,{
      qos:1
    })
   },
   
   /*
   else{
     //切换ui界面
     that.setData({
       'ledvalue[0].btnvalue':'关灯',
       'ledvalue[0].btnflag': false,
       'ledvalue[0].ledlogo':'/images/LED_red.png'

     })

     // 把switch json变成string
     var str = JSON.stringify(jsonon);
     console.log(str);
     // 发送指令
     that.data.client.publish(topic2, str, {
       qos: 1
     })
    */
  onReady: function (start,end) {

    // 页面渲染完成
    var cxt_arc = wx.createCanvasContext('canvasArc');//创建并返回绘图上下文context对象。
    cxt_arc.setLineWidth(10);
    cxt_arc.setStrokeStyle('#d2d2d2');
    cxt_arc.setLineCap('round')
    cxt_arc.beginPath();//开始一个新的路径
    cxt_arc.arc(106, 106, 60, 0, 2 * Math.PI, false);//设置一个原点(106,106)，半径为100的圆的路径到当前路径
    cxt_arc.stroke();//对当前路径进行描边

    cxt_arc.setLineWidth(10);
    cxt_arc.setStrokeStyle('#3ea6ff');
    cxt_arc.setLineCap('round')
    cxt_arc.beginPath();//开始一个新的路径
    cxt_arc.arc(106, 106, 60, -Math.PI * start / 2, Math.PI * end / 5, false);
    cxt_arc.stroke();//对当前路径进行描边

    cxt_arc.draw();

  },
  onShow: function () {
    // 页面显示
  },
  onHide: function () {
    // 页面隐藏
  },
  onUnload: function () {
    // 页面关闭
  },
  NavChange(e) {
    // this.setData({
    //   PageCur: e.currentTarget.dataset.cur
    //})
    wx.redirectTo({
      url: '../index/index',
    })
  },
  cancel: function () {
    this.setData({
      hidden: true
    });
  },
  confirm: function () {
    this.setData({
      nocancel: this.data.nocancel
    });
    console.log("clicked confirm");
    this.open();
  }
  
})