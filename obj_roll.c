
#include "common.h"

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
    lv_obj_set_style_bg_color(container, lv_color_hex(BLACK), LV_PART_MAIN);
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





