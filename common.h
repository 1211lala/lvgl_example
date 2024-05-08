
#ifndef _COMMON_H_
#define _COMMON_H_

#include "lvgl.h"


#define loginfo     printf

#define LCD_W  480
#define LCD_H  480

#define randNum()  (rand()%(470 - 10) + 10)

#define LCD_BLACK       0x000000 // ��ɫ
#define LCD_WHITE       0xFFFFFF // ��ɫ
#define LCD_RED         0xFF0000 // ��ɫ
#define LCD_GREEN       0x00FF00 // ��ɫ
#define LCD_BLUE        0x0000FF // ��ɫ
#define LCD_YELLOW      0xFFFF00 // ��ɫ
#define LCD_CYAN        0x00FFFF // ��ɫ�����̣�
#define LCD_MAGENTA     0xFF00FF // Ʒ��ɫ���Ϻ죩
#define LCD_GRAY        0x808080 // ��ɫ��50%��
#define LCD_LIGHT_GRAY  0xC0C0C0 // ǳ��ɫ
#define LCD_DARK_GRAY   0x404040 // ���ɫ

#endif
