#define bj_width 64
#define bj_height 64
static char bj_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
  0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x3E, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 
  0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xEF, 
  0xF7, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE7, 0xE7, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0xE7, 0xE7, 0x03, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE3, 
  0xC7, 0x03, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE3, 0xC7, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0xF0, 0xE1, 0x87, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xE0, 
  0x07, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xE0, 0x07, 0x1F, 0x00, 0x00, 
  0x00, 0x00, 0x78, 0xE0, 0x07, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x7C, 0xE0, 
  0x07, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x3C, 0xE0, 0x07, 0x3C, 0x00, 0x00, 
  0x00, 0x00, 0x1E, 0xE0, 0x07, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xE0, 
  0x07, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xE0, 0x07, 0xF0, 0x00, 0x00, 
  0x00, 0x80, 0x0F, 0xC0, 0x03, 0xF0, 0x01, 0x00, 0x00, 0x80, 0x07, 0x00, 
  0x00, 0xE0, 0x01, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0xE0, 0x03, 0x00, 
  0x00, 0xE0, 0x03, 0xC0, 0x03, 0xC0, 0x07, 0x00, 0x00, 0xE0, 0x01, 0xE0, 
  0x07, 0x80, 0x07, 0x00, 0x00, 0xF0, 0x01, 0xE0, 0x07, 0x80, 0x0F, 0x00, 
  0x00, 0xF0, 0x00, 0xE0, 0x07, 0x00, 0x0F, 0x00, 0x00, 0xF8, 0x00, 0x00, 
  0x00, 0x00, 0x1F, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 
  0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 
  0xFF, 0xFF, 0x3F, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 
  0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };