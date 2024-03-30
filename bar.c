#include "bar.h"


static lv_obj_t* bar;
static lv_obj_t* obj1;
static lv_obj_t* obj2;
static lv_obj_t* label;

uint32_t value  = 40;
static void button_event_cb(lv_event_t* event)
{
    lv_obj_t *target = lv_event_get_target(event);    /*获取触发部件类型*/
    lv_event_code_t code = lv_event_get_code(event);  /*获取触发事件类型*/

    if(target == obj1)
    {
        value += 5;
        lv_bar_set_value(bar, value, LV_ANIM_ON);
        printf("obj1\r\n");
    }else if(target == obj2)
    {
        value -= 5;
        lv_bar_set_value(bar, value, LV_ANIM_ON);
        printf("obj2\r\n");
    }
}


void bar_example(void)
{

    obj1 = lv_btn_create(lv_scr_act());
    lv_obj_set_size(obj1, LV_PCT(10), LV_PCT(10));
    lv_obj_align(obj1, LV_ALIGN_LEFT_MID, 20, 40);
    lv_obj_t* label = lv_label_create(obj1);
    lv_label_set_text_fmt(label, "+");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj1, button_event_cb, LV_EVENT_CLICKED, NULL);


    obj2 = lv_btn_create(lv_scr_act());
    lv_obj_set_size(obj2, LV_PCT(10), LV_PCT(10));
    lv_obj_align(obj2, LV_ALIGN_LEFT_MID, 20, -40);
    label = lv_label_create(obj2);
    lv_label_set_text_fmt(label, "-");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj2, button_event_cb, LV_EVENT_CLICKED, NULL);


    bar = lv_bar_create(lv_scr_act());
    lv_obj_set_size(bar, 10, 300);
    lv_obj_align(bar, LV_ALIGN_RIGHT_MID, -30, 0);

    lv_bar_set_range(bar, 0, 100);
    lv_bar_set_start_value(bar, 6, LV_ANIM_ON);

    lv_obj_set_style_anim_time(bar, 200, LV_STATE_DEFAULT);

    lv_bar_set_value(bar, value, LV_ANIM_ON);

}
