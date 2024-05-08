
#ifndef _COMMON_H_
#define _COMMON_H_

#include "lvgl.h"


#define loginfo     printf

#define LCD_W  480
#define LCD_H  480

#define randNum()  (rand()%(470 - 10) + 10)

#define LCD_BLACK       0x000000 // 黑色
#define LCD_WHITE       0xFFFFFF // 白色
#define LCD_RED         0xFF0000 // 红色
#define LCD_GREEN       0x00FF00 // 绿色
#define LCD_BLUE        0x0000FF // 蓝色
#define LCD_YELLOW      0xFFFF00 // 黄色
#define LCD_CYAN        0x00FFFF // 青色（蓝绿）
#define LCD_MAGENTA     0xFF00FF // 品红色（紫红）
#define LCD_GRAY        0x808080 // 灰色（50%）
#define LCD_LIGHT_GRAY  0xC0C0C0 // 浅灰色
#define LCD_DARK_GRAY   0x404040 // 深灰色

#endif
