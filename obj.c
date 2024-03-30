
//lv_obj_create(lv_scr_act());  以屏幕为父对象创建一个对象
//lv_obj_del(lv_obj_t * obj);   删除一个对象，那么该对象的子类一并删除(立刻删除)。
// lv_obj_clean(lv_obj_t * obj);    删除一个对象的全部子类(立刻删除)。
// lv_obj_del_delayed(lv_obj_t * obj, uint32_t delay_ms);   延时毫秒再删除对象(等待删除)。

#include "obj.h"


#define HIGH    480
#define WEIGHT  480

static const uint32_t black = 0x0b0b0b;



void obj_example(void)
{

    lv_obj_t * bgObj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(bgObj, WEIGHT, HIGH);
    lv_obj_align(bgObj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(bgObj, lv_color_hex(black), LV_STATE_DEFAULT );


    lv_obj_t * rootObj = lv_obj_create(bgObj);
    lv_obj_set_size(rootObj, WEIGHT/2, HIGH/2);
    lv_obj_align(rootObj, LV_ALIGN_CENTER, -40, 0);
    lv_obj_set_style_bg_color(rootObj, lv_palette_main(LV_PALETTE_DEEP_PURPLE), LV_STATE_DEFAULT );

    lv_obj_t* branchObj = lv_obj_create(rootObj);
    lv_obj_set_size(branchObj,  WEIGHT/4, HIGH/4);
    lv_obj_align(branchObj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(branchObj, lv_palette_main(LV_PALETTE_RED), LV_STATE_DEFAULT );


    lv_obj_t * rootObj1 = lv_obj_create(bgObj);
    lv_obj_set_size(rootObj1, WEIGHT/2, HIGH/2);
    lv_obj_align(rootObj1, LV_ALIGN_CENTER, 40, 0);
    lv_obj_set_style_bg_color(rootObj1, lv_palette_main(LV_PALETTE_DEEP_PURPLE), LV_STATE_DEFAULT );


    lv_obj_move_foreground(rootObj);

    lv_obj_del_delayed(rootObj, 3000);
}



lv_style_t style_btn;

void style_general(void)
{
    lv_style_init(&style_btn);
    lv_style_set_bg_color(&style_btn, lv_color_hex(0XDF0000));  /* 设置背景 */
    lv_style_set_bg_opa(&style_btn, LV_OPA_80);                 /* 设置背景透明度 */
    lv_style_set_border_width(&style_btn, 1);                   /* 设置边框的宽度 */
    lv_style_set_border_color(&style_btn, lv_color_hex(0XDF0000));    /* 设置边框的颜色 */


    lv_obj_t * Obj1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(Obj1, WEIGHT/2.8, HIGH/6);
    lv_obj_align(Obj1, LV_ALIGN_TOP_LEFT, WEIGHT/48, HIGH/48);
    lv_obj_add_style(Obj1, &style_btn, LV_STATE_DEFAULT);      /* 设置对象 1 的样式 */


    lv_obj_t * Obj2 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(Obj2, WEIGHT/6, HIGH/2.8);
    lv_obj_align(Obj2, LV_ALIGN_TOP_RIGHT, -WEIGHT/48, HIGH/48);
    lv_obj_add_style(Obj2, &style_btn, LV_STATE_PRESSED);      /* 设置对象 1 的样式 */
}




void local_style(void)
{
    lv_obj_t * obj = lv_obj_create(lv_scr_act());

    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000),LV_STATE_DEFAULT);

}







lv_obj_t* container;

static void button_event_cb(lv_event_t* event);

void desktop_init(void)
{
    /* 新建一个 OBJ 容器 */
    container = lv_obj_create(lv_scr_act());
    /* 设置容器大小，这里设置全屏*/
    lv_obj_set_size(container, LV_PCT(100), LV_PCT(100));
    /* 设置容器的滚动条隐藏 */
    lv_obj_set_scrollbar_mode(container, LV_SCROLLBAR_MODE_OFF);
    /* 设置子容器中的对象的排列方式 默认从左到右 */
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
    /* 设置子容器中的对象的对齐方式 */
    lv_obj_set_flex_align(container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    /* ？？？？？？？？？？？？？ */
    lv_obj_set_scroll_snap_x(container, LV_SCROLL_SNAP_CENTER);
    /* 设置容器的透明度 */
    lv_obj_set_style_bg_opa(container, LV_OPA_100, LV_PART_MAIN);
    /* 设置容器的背景颜色 */
    lv_obj_set_style_bg_color(container, lv_color_hex(black), LV_PART_MAIN);
    /* 设置容器边距宽度 */
    lv_obj_set_style_border_width(container, 0, LV_PART_MAIN);
    /* 设置容器子对象的间隔 */
    lv_obj_set_style_pad_column(container, 60, LV_PART_MAIN);

    /* 生成子对象 */
    for (int i = 0; i < 19; i++)
    {
        lv_obj_t* btn = lv_btn_create(container);
        lv_obj_set_size(btn, LV_PCT(20), LV_PCT(20));
        lv_obj_add_event_cb(btn, button_event_cb, LV_EVENT_ALL, NULL);

        lv_obj_t* label = lv_label_create(btn);
        lv_label_set_text_fmt(label, "%d", i);
        lv_obj_center(label);
    }

    uint32_t mid_btn_index = (lv_obj_get_child_cnt(container) - 1) / 2;
    for (uint32_t i = 0; i < mid_btn_index; i++)
    {
        lv_obj_move_to_index(lv_obj_get_child(container, -1), 0);
    }
    /*当按钮数为偶数时，确保按钮居中*/
    lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index), LV_ANIM_OFF);
}


/**
 * @brief 处理按钮事件的回调函数
 * @param event
*/
static void button_event_cb(lv_event_t* event)
{
    lv_obj_t* current_btn = lv_event_get_current_target(event);

    uint32_t current_btn_index = lv_obj_get_index(current_btn);

    uint32_t mid_btn_index = (lv_obj_get_child_cnt(container) - 1) / 2;

    if (event->code == LV_EVENT_FOCUSED)
    {
        if (current_btn_index > mid_btn_index)
        {
            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index - 1), LV_ANIM_OFF);
            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index), LV_ANIM_ON);
            lv_obj_move_to_index(lv_obj_get_child(container, 0), -1);
        }
        else if (current_btn_index < mid_btn_index)
        {
            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index + 1), LV_ANIM_OFF);
            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index), LV_ANIM_ON);
            lv_obj_move_to_index(lv_obj_get_child(container, -1), 0);
        }
    }
    else if (event->code == LV_EVENT_CLICKED)
    {
        /**/
    }
}





