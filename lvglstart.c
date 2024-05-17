#include "lvglstart.h"
#include "stdio.h"


#define rgb_to_hex(r, g, b)      ((r << 16)|(g << 8)|(b))

LV_FONT_DECLARE(font_80)
LV_FONT_DECLARE(font_24)
LV_FONT_DECLARE(font_14)

lv_obj_t *bgObj = NULL;
lv_obj_t *tileLeft = NULL;
lv_obj_t *tileRight = NULL;
lv_timer_t * timer;

lv_obj_t * switch0;
lv_obj_t * switch1;
lv_obj_t * switch2;
lv_obj_t * switch3;
lv_obj_t * label00;
lv_obj_t * label11;
lv_obj_t * label22;
lv_obj_t * label33;

struct tDate
{
    uint8_t shi;
    uint8_t fen;
    uint8_t miao;
};
struct tDate date =
{
    .shi = 10,
    .fen = 34,
    .miao = 45,
};
struct LV_OBJ
{
    lv_obj_t *obj;
    lv_obj_t *btn;
    lv_obj_t *label;
};

struct LV_OBJ time;


struct lv_obj_t *taskObj[5];

void menu_demo(void)
{
    lv_obj_set_style_bg_color(lv_scr_act(),lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    bgObj= lv_scr_act();
    lv_obj_clear_flag(bgObj, LV_OBJ_FLAG_SCROLLABLE);

    tileLeft= lv_tileview_create(bgObj);
    lv_obj_set_style_bg_color(tileLeft,lv_color_hex(0x1f1f1f), LV_PART_MAIN|LV_STATE_DEFAULT);

    time.obj = lv_obj_create(tileLeft);
    lv_obj_set_size(time.obj, LCD_W-1, LCD_H-1);
    lv_obj_set_style_bg_color(time.obj,lv_color_hex(0x1f1f1f), LV_PART_MAIN);
    lv_obj_align(time.obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_border_width(time.obj, 0, LV_STATE_DEFAULT);

    time.label = lv_label_create(time.obj);
    lv_obj_set_style_text_font(time.obj, &font_80, LV_STATE_DEFAULT);
    lv_obj_align(time.label, LV_ALIGN_CENTER, 0, -100);
    lv_obj_set_style_text_color(time.obj, lv_color_hex(rgb_to_hex(248,220,135)), LV_STATE_DEFAULT);
    timer = lv_timer_create(timer_cb, 1000, NULL);



    tileRight= lv_tileview_add_tile(tileLeft, 1, 0, LV_DIR_HOR);
    lv_obj_set_style_bg_color(tileRight,lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);

    taskObj[0] = lv_obj_create(tileRight);
    lv_obj_align(taskObj[0], LV_ALIGN_TOP_MID, -120, 120);
    lv_obj_set_size(taskObj[0], 200, 150);
    lv_obj_set_style_bg_color(taskObj[0],lv_color_hex(rgb_to_hex(1,114,254)), LV_PART_MAIN);
    lv_obj_set_style_border_width(taskObj[0], 0, LV_STATE_DEFAULT);

    switch0 = lv_switch_create(taskObj[0]);
    lv_obj_align(switch0, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_obj_t * label0 = lv_label_create(taskObj[0]);
    lv_obj_align(label0, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(label0, &font_24, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label0, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label0, "卧室灯");

    label00 = lv_label_create(taskObj[0]);
    lv_obj_align_to(label00, label0, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_obj_set_style_text_font(label00, &font_14, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label00, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label00, "OFF");


    taskObj[1] = lv_obj_create(tileRight);
    lv_obj_align(taskObj[1],LV_ALIGN_TOP_MID, 120, 120);
    lv_obj_set_size(taskObj[1], 200, 150);
    lv_obj_set_style_bg_color(taskObj[1],lv_color_hex(rgb_to_hex(0,52,164)), LV_PART_MAIN);
    lv_obj_set_style_border_width(taskObj[1], 0, LV_STATE_DEFAULT);

    switch1 = lv_switch_create(taskObj[1]);
    lv_obj_align(switch1, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_obj_t * label1 = lv_label_create(taskObj[1]);
    lv_obj_align(label1, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(label1, &font_24, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label1, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label1, "风扇");

    label11 = lv_label_create(taskObj[1]);
    lv_obj_align_to(label11, label1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_obj_set_style_text_font(label11, &font_14, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label11, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label11, "OFF");

    taskObj[2] = lv_obj_create(tileRight);
    lv_obj_align(taskObj[2],LV_ALIGN_BOTTOM_MID, -120, -40);
    lv_obj_set_size(taskObj[2], 200, 150);
    lv_obj_set_style_bg_color(taskObj[2],lv_color_hex(rgb_to_hex(11,150,158)), LV_PART_MAIN);
    lv_obj_set_style_border_width(taskObj[2], 0, LV_STATE_DEFAULT);


    switch2 = lv_switch_create(taskObj[2]);
    lv_obj_align(switch2, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_obj_t * label2 = lv_label_create(taskObj[2]);
    lv_obj_align(label2, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(label2, &font_24, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label2, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label2, "窗帘");
    label22 = lv_label_create(taskObj[2]);
    lv_obj_align_to(label22, label2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_obj_set_style_text_font(label22, &font_14, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label22, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label22, "OFF");


    taskObj[3] = lv_obj_create(tileRight);
    lv_obj_align(taskObj[3],LV_ALIGN_BOTTOM_MID, 120, -40);
    lv_obj_set_size(taskObj[3], 200, 150);
    lv_obj_set_style_bg_color(taskObj[3],lv_color_hex(rgb_to_hex(166,63,147)), LV_PART_MAIN);
    lv_obj_set_style_border_width(taskObj[3], 0, LV_STATE_DEFAULT);

    switch3 = lv_switch_create(taskObj[3]);
    lv_obj_align(switch3, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_obj_t * label3 = lv_label_create(taskObj[3]);
    lv_obj_align(label3, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(label3, &font_24, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label3, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label3, "厕所灯");
    label33 = lv_label_create(taskObj[3]);
    lv_obj_align_to(label33, label3, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_obj_set_style_text_font(label33, &font_14, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label33, lv_color_hex(rgb_to_hex(0xff, 0xff, 0xff)), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(label33, "OFF");

    lv_obj_add_event_cb(switch0, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL); /* 添加事件 */
    lv_obj_add_event_cb(switch1, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL); /* 添加事件 */
    lv_obj_add_event_cb(switch2, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL); /* 添加事件 */
    lv_obj_add_event_cb(switch3, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL); /* 添加事件 */

}


void switch_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    uint8_t status = lv_obj_has_state(target, LV_STATE_CHECKED);
    if(target == switch0)
    {
        if(status)
        {
            lv_label_set_text_fmt(label00, "ON");
        }
        else
        {
            lv_label_set_text_fmt(label00, "OFF");
        }
    }
    else if(target == switch1)
    {
        if(status)
        {
            lv_label_set_text_fmt(label11, "ON");
        }
        else
        {
            lv_label_set_text_fmt(label11, "OFF");
        }
    }
    else if(target == switch2)
    {
        if(status)
        {
            lv_label_set_text_fmt(label22, "ON");
        }
        else
        {
            lv_label_set_text_fmt(label22, "OFF");
        }
    }
    else if(target == switch3)
    {
        if(status)
        {
            lv_label_set_text_fmt(label33, "ON");
        }
        else
        {
            lv_label_set_text_fmt(label33, "OFF");
        }
    }
}
void timer_cb(lv_timer_t * t)
{
    date.miao += 1;
    if(date.miao > 59)
    {
        date.miao = 0;
        date.fen += 1;
    }
    if(date.fen > 59)
    {
        date.fen = 0;
        date.shi += 1;
    }
    if(date.shi > 23)
    {
        date.shi = 0;
    }
    lv_label_set_text_fmt(time.label, "%02d:%02d", date.shi, date.fen);
}

//lv_obj_t *bgObj;
//lv_obj_t * tile;
//lv_obj_t * tile0;
//lv_obj_t * tile1;
//lv_timer_t *t1;
//int move = 0;
//
//
//lv_obj_t *obj[objNum];
//lv_obj_t *label[objNum];
//char * label_str[objNum] = {"BTN", "BAR", "ARC", "NULL", "NULL", "NULL", "NULL"};
//uint32_t color[objNum] = {0xff0020, 0xff00ff, 0x0000ff, 0x00ffff, 0x00ff00,0xffff00, 0x000000};
//
//void menu_slider(void)
//{
//    bgObj= lv_scr_act();
//    lv_obj_clear_flag(bgObj, LV_OBJ_FLAG_SCROLLABLE);
//    lv_obj_set_style_bg_color(lv_scr_act(),lv_color_hex(0x8f8f8f), LV_PART_MAIN|LV_STATE_DEFAULT);
//
//    tile= lv_tileview_create(bgObj);
//    lv_obj_set_style_bg_color(tile,lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
//
//    tile0= lv_tileview_add_tile(tile, 0, 0, LV_DIR_VER);
//    lv_obj_set_style_bg_color(tile0,lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
//    for(uint16_t i = 0; i< objNum; i++)
//    {
//        if(objNum == i+1)
//        {
//            obj[i] = lv_obj_create(tile0);
//            lv_obj_align(obj[i],LV_ALIGN_CENTER, i * 250 , -50);
//            lv_obj_set_size(obj[i], 80, 80);
//            lv_obj_set_style_bg_color(obj[i],lv_color_hex(0x000000), LV_PART_MAIN);
//            lv_obj_set_style_border_width(obj[i], 0, LV_STATE_DEFAULT);
//
//        }
//        else
//        {
//            obj[i] = lv_btn_create(tile0);
//            lv_obj_set_style_radius(obj[i],20,LV_PART_MAIN);
//            lv_obj_align(obj[i],LV_ALIGN_CENTER, i * 250, -50);
//            lv_obj_set_style_bg_color(obj[i],lv_color_hex(color[i]), LV_PART_MAIN);
//            lv_obj_set_size(obj[i], 120, 120);
//            lv_obj_add_event_cb(obj[i], obj_event_cb, LV_EVENT_LONG_PRESSED, NULL);
//            label[i] = lv_label_create(obj[i]);
//            lv_label_set_text_fmt(label[i], "%s", label_str[i]);
//            lv_obj_set_style_text_color(label[i], lv_color_hex(0xffffffff), LV_STATE_DEFAULT);
//            lv_obj_set_style_text_font(label[i], &lv_font_montserrat_16, LV_STATE_DEFAULT);
//            lv_obj_set_align(label[i], LV_ALIGN_CENTER);
//        }
//    }
//    // lv_obj_add_event_cb(tile0,scroll_event_cb,LV_EVENT_SCROLL_END, NULL);
//    // t1=lv_timer_create(timer_cb1,10, NULL);
//
//    tile1= lv_tileview_add_tile(tile, 0, 1, LV_DIR_VER);
//    lv_obj_set_style_bg_color(tile0,lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
//
//
//
//
//    lv_obj_t *timeObj =  lv_obj_create(tile1);
//    lv_obj_set_size(timeObj, 320, 320);
//    lv_obj_align(timeObj, LV_ALIGN_BOTTOM_LEFT, 20, -20);
//    lv_obj_set_style_bg_color(timeObj, lv_color_hex(0xff0000), LV_STATE_DEFAULT);
//    lv_obj_set_style_border_width(timeObj, 0, LV_STATE_DEFAULT);
//
//    lv_obj_t *wifiObj = lv_obj_create(tile1);
//    lv_obj_align_to(wifiObj, timeObj, LV_ALIGN_OUT_TOP_MID, 20, 20);
//    lv_obj_align(wifiObj, LV_ALIGN_TOP_LEFT, 20 ,20 );
//    lv_obj_set_size(wifiObj, 300, 100);
//    lv_obj_set_style_bg_color(wifiObj, lv_color_hex(0x0ff000), LV_STATE_DEFAULT);
//    lv_obj_set_style_border_width(wifiObj, 0, LV_STATE_DEFAULT);
//
//    lv_obj_t *wifi_label = lv_label_create(wifiObj);
//    lv_label_set_text_fmt(wifi_label, "WIFI: %s\n\n  IP : %s", "Kean.2023", "192.168.8.22");
//    lv_obj_set_style_text_font(wifi_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
//    lv_obj_align(wifi_label, LV_ALIGN_CENTER, 0 ,0 );
//
//    lv_obj_t *sramObj = lv_obj_create(tile1);
//    lv_obj_align_to(sramObj,timeObj, LV_ALIGN_OUT_RIGHT_TOP, 5, -(20 + 100));
//    lv_obj_set_size(sramObj, 120, 120);
//    lv_obj_set_style_bg_color(sramObj, lv_color_hex(0x00FF00), LV_STATE_DEFAULT);
//    lv_obj_set_style_border_width(sramObj, 0, LV_STATE_DEFAULT);
//
//    lv_obj_t *pramObj = lv_obj_create(tile1);
//    lv_obj_set_size(pramObj, 120, 120);
//    lv_obj_align_to(pramObj, timeObj, LV_ALIGN_OUT_RIGHT_TOP, 5, 20);
//    lv_obj_set_style_bg_color(pramObj, lv_color_hex(0x000FF0), LV_STATE_DEFAULT);
//    lv_obj_set_style_border_width(pramObj, 0, LV_STATE_DEFAULT);
//}
//
//
//void obj_event_cb(lv_event_t *e)
//{
//    lv_obj_t *target = lv_event_get_target(e);
//    lv_event_code_t  code = lv_event_get_code(e);
//    if(target == obj[0])
//    {
//        lv_obj_add_flag(tile, LV_OBJ_FLAG_HIDDEN);
//        obj_example();
//    }
//    if(target == obj[1])
//    {
//        lv_obj_add_flag(tile, LV_OBJ_FLAG_HIDDEN);
//        example_bar();
//    }
//    if(target == obj[2])
//    {
//        lv_obj_add_flag(tile, LV_OBJ_FLAG_HIDDEN);
//        arc_example();
//    }
//    if(target == obj[3])
//    {
//        printf("obj4 long pressing \r\n");
//    }
//    if(target == obj[4])
//    {
//        printf("obj5 long pressing \r\n");
//    }
//    if(target == obj[5])
//    {
//        printf("obj6 long pressing \r\n");
//    }
//}
//
//
//
//
//void scroll_event_cb(lv_event_t * e)
//{
//    move=lv_obj_get_scroll_x(tile0);
//
//    if(move%150!=0)
//    {
//        if(move%150<75)
//        {
//            lv_obj_scroll_to_x(tile0, move-(move%150), LV_ANIM_ON);
//        }
//        if(move%150>74)
//        {
//            lv_obj_scroll_to_x(tile0, move+150-(move%150), LV_ANIM_ON);
//        }
//    }
//}
//
//
//
//void timer_cb1(lv_timer_t * t)
//{
//    int move;
//    move=lv_obj_get_scroll_x(tile0);
//    if(move<=150&&move>=0)
//    {
//        lv_obj_set_width(obj[0],130-move/3);
//        lv_obj_set_height(obj[0],130-move/3);
//        lv_obj_set_y(obj[0],-move/3);
//
//        lv_obj_set_width(obj[1],80+move/3);
//        lv_obj_set_height(obj[1],80+move/3);
//        lv_obj_set_y(obj[1],move/3-50);
//    }
//
//    if(move<=300&&move>=150)
//    {
//        lv_obj_set_width(obj[1],130-(move-150)/3);
//        lv_obj_set_height(obj[1],130-(move-150)/3);
//        lv_obj_set_y(obj[1],-(move-150)/3);
//
//        lv_obj_set_width(obj[2],80+(move-150)/3);
//        lv_obj_set_height(obj[2],80+(move-150)/3);
//        lv_obj_set_y(obj[2],(move-150)/3-50);
//    }
//
//    if(move<=450&&move>=300)
//    {
//        lv_obj_set_width(obj[2],130-(move-300)/3);
//        lv_obj_set_height(obj[2],130-(move-300)/3);
//        lv_obj_set_y(obj[2],-(move-300)/3);
//
//        lv_obj_set_width(obj[3],80+(move-300)/3);
//        lv_obj_set_height(obj[3],80+(move-300)/3);
//        lv_obj_set_y(obj[3],(move-300)/3-50);
//    }
//
//    if(move<=600&&move>=450)
//    {
//        lv_obj_set_width(obj[3],130-(move-450)/3);
//        lv_obj_set_height(obj[3],130-(move-450)/3);
//        lv_obj_set_y(obj[3],-(move-450)/3);
//
//        lv_obj_set_width(obj[4],80+(move-450)/3);
//        lv_obj_set_height(obj[4],80+(move-450)/3);
//        lv_obj_set_y(obj[4],(move-450)/3-50);
//    }
//
//    if(move<=750&&move>=600)
//    {
//        lv_obj_set_width(obj[4],130-(move-600)/3);
//        lv_obj_set_height(obj[4],130-(move-600)/3);
//        lv_obj_set_y(obj[4],-(move-600)/3);
//
//        lv_obj_set_width(obj[5],80+(move-600)/3);
//        lv_obj_set_height(obj[5],80+(move-600)/3);
//        lv_obj_set_y(obj[5],(move-600)/3-50);
//    }
//
//    if(move<=900&&move>=750)
//    {
//        lv_obj_set_width(obj[5],130-(move-750)/3);
//        lv_obj_set_height(obj[5],130-(move-750)/3);
//        lv_obj_set_y(obj[5],-(move-750)/3);
//
//        lv_obj_set_width(obj[6],80+(move-750)/3);
//        lv_obj_set_height(obj[6],80+(move-750)/3);
//        lv_obj_set_y(obj[6],(move-750)/3-50);
//    }
//
//    if(move<=1050&&move>=900)
//    {
//        lv_obj_set_width(obj[6],130-(move-900)/3);
//        lv_obj_set_height(obj[6],130-(move-900)/3);
//        lv_obj_set_y(obj[6],-(move-900)/3);
//    }
//}
//
//
//
//
//
//
//
