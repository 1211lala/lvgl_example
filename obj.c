
// lv_obj_create(lv_scr_act());     以屏幕为父对象创建一个对象
// lv_obj_del(lv_obj_t * obj);      删除一个对象，那么该对象的子类一并删除(立刻删除)。
// lv_obj_clean(lv_obj_t * obj);    删除一个对象的全部子类(立刻删除)。
// lv_obj_del_delayed(lv_obj_t * obj, uint32_t delay_ms);   延时毫秒再删除对象(等待删除)。

#include "common.h"


extern void obj_example(void);


static lv_obj_t * objArray[3];
static bg_color[] = {0xff0000, 0x00ff00, 0x0000ff};
static lv_obj_t * label[3];
static lv_obj_t * btn;

static void button_event_cb(lv_event_t* event)
{
    lv_obj_t *target = lv_event_get_target(event);    /*获取触发部件类型*/
    lv_event_code_t code = lv_event_get_code(event);  /*获取触发事件类型*/

    if(target == btn)
    {
        if(code == LV_EVENT_SHORT_CLICKED)
        {
            lv_obj_set_pos(objArray[0], Rand(), Rand());
            lv_obj_clear_flag(objArray[0], LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(objArray[1], LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(objArray[2], LV_OBJ_FLAG_HIDDEN);
        }else if(code == LV_EVENT_LONG_PRESSED)
        {
            lv_obj_set_pos(objArray[1], Rand(), Rand());
            lv_obj_add_flag(objArray[0], LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(objArray[1], LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(objArray[2], LV_OBJ_FLAG_HIDDEN);
            loginfo("LV_EVENT_LONG_PRESSED\r\n");
        }
    }
}


void obj_example(void)
{
    for(uint8_t i=0; i< 3 ;i++)
    {
        objArray[i] = lv_obj_create(lv_scr_act());
        lv_obj_set_size(objArray[i], LV_PCT(30), LV_PCT(30));
        lv_obj_set_style_bg_color(objArray[i], lv_color_hex(bg_color[i]), LV_STATE_DEFAULT);
        lv_obj_align(objArray[i], LV_ALIGN_CENTER, 0, -HIGH/5);

        lv_obj_add_flag(objArray[i], LV_OBJ_FLAG_HIDDEN);

        label[i] = lv_label_create(objArray[i]);
        lv_label_set_text_fmt(label[i], "OBJ%d", i);
        lv_obj_align(label[i], LV_ALIGN_CENTER, 0,0);
    }

    btn = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn, LV_PCT(15), LV_PCT(8));
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, HIGH/3);
    lv_obj_add_event_cb(btn, button_event_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(btn, button_event_cb, LV_EVENT_LONG_PRESSED, NULL);
}


//#include "common.h"
//
//lv_obj_t* container;
//
//static void button_event_cb(lv_event_t* event);
//
//void desktop_init(void)
//{
//    /* 新建一个 OBJ 容器 */
//    container = lv_obj_create(lv_scr_act());
//    /* 设置容器大小，这里设置全屏*/
//    lv_obj_set_size(container, LV_PCT(100), LV_PCT(100));
//    /* 设置容器的滚动条隐藏 */
//    lv_obj_set_scrollbar_mode(container, LV_SCROLLBAR_MODE_OFF);
//    /* 设置子容器中的对象的排列方式 默认从左到右 */
//    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
//    /* 设置子容器中的对象的对齐方式 */
//    lv_obj_set_flex_align(container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//    /* ？？？？？？？？？？？？？ */
//    lv_obj_set_scroll_snap_x(container, LV_SCROLL_SNAP_CENTER);
//    /* 设置容器的透明度 */
//    lv_obj_set_style_bg_opa(container, LV_OPA_100, LV_PART_MAIN);
//    /* 设置容器的背景颜色 */
//    lv_obj_set_style_bg_color(container, lv_color_hex(BLACK), LV_PART_MAIN);
//    /* 设置容器边距宽度 */
//    lv_obj_set_style_border_width(container, 0, LV_PART_MAIN);
//    /* 设置容器子对象的间隔 */
//    lv_obj_set_style_pad_column(container, 60, LV_PART_MAIN);
//
//    /* 生成子对象 */
//    for (int i = 0; i < 19; i++)
//    {
//        lv_obj_t* btn = lv_btn_create(container);
//        lv_obj_set_size(btn, LV_PCT(20), LV_PCT(20));
//        lv_obj_add_event_cb(btn, button_event_cb, LV_EVENT_ALL, NULL);
//
//        lv_obj_t* label = lv_label_create(btn);
//        lv_label_set_text_fmt(label, "%d", i);
//        lv_obj_center(label);
//    }
//
//    uint32_t mid_btn_index = (lv_obj_get_child_cnt(container) - 1) / 2;
//    for (uint32_t i = 0; i < mid_btn_index; i++)
//    {
//        lv_obj_move_to_index(lv_obj_get_child(container, -1), 0);
//    }
//    /*当按钮数为偶数时，确保按钮居中*/
//    lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index), LV_ANIM_OFF);
//}
//
//
///**
// * @brief 处理按钮事件的回调函数
// * @param event
//*/
//static void button_event_cb(lv_event_t* event)
//{
//    lv_obj_t* current_btn = lv_event_get_current_target(event);
//
//    uint32_t current_btn_index = lv_obj_get_index(current_btn);
//
//    uint32_t mid_btn_index = (lv_obj_get_child_cnt(container) - 1) / 2;
//
//    if (event->code == LV_EVENT_FOCUSED)
//    {
//        if (current_btn_index > mid_btn_index)
//        {
//            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index - 1), LV_ANIM_OFF);
//            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index), LV_ANIM_ON);
//            lv_obj_move_to_index(lv_obj_get_child(container, 0), -1);
//        }
//        else if (current_btn_index < mid_btn_index)
//        {
//            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index + 1), LV_ANIM_OFF);
//            lv_obj_scroll_to_view(lv_obj_get_child(container, mid_btn_index), LV_ANIM_ON);
//            lv_obj_move_to_index(lv_obj_get_child(container, -1), 0);
//        }
//    }
//    else if (event->code == LV_EVENT_CLICKED)
//    {
//        /**/
//    }
//}







