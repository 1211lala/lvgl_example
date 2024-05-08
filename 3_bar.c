#include "common.h"



extern void bar_example(void);


static int defValue  = 40;
static int value = 40;
static int animTime = 200;

static const int rangeMin = 0;
static const int rangeMax = 100;


static lv_obj_t* bar;
static lv_obj_t* btnup;
static lv_obj_t* btndown;
static lv_obj_t* label;


static void button_event_cb(lv_event_t* event)
{
    lv_obj_t *target = lv_event_get_target(event);    /*获取触发部件类型*/
    lv_event_code_t code = lv_event_get_code(event);  /*获取触发事件类型*/

    if(target == btnup)
    {
        value += 5;
        if(value >= rangeMax)
        {
            value = rangeMax;
        }
        lv_bar_set_value(bar, value, LV_ANIM_ON);
        loginfo("btnup\r\n");
    }else if(target == btndown)
    {
        value -= 5;
        if(value <= rangeMin)
        {
            value = rangeMin;
        }
        lv_bar_set_value(bar, value, LV_ANIM_ON);
        loginfo("btndown\r\n");
    }
}


void bar_example(void)
{
    value = defValue;

    btnup = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btnup, LV_PCT(10), LV_PCT(10));
    lv_obj_align(btnup, LV_ALIGN_LEFT_MID, 20, -40);
    lv_obj_t* label = lv_label_create(btnup);
    lv_label_set_text_fmt(label, "+");
    lv_obj_center(label);
    lv_obj_add_event_cb(btnup, button_event_cb, LV_EVENT_CLICKED, NULL);


    btndown = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btndown, LV_PCT(10), LV_PCT(10));
    lv_obj_align(btndown, LV_ALIGN_LEFT_MID, 20, 40);
    label = lv_label_create(btndown);
    lv_label_set_text_fmt(label, "-");
    lv_obj_center(label);
    lv_obj_add_event_cb(btndown, button_event_cb, LV_EVENT_CLICKED, NULL);


    bar = lv_bar_create(lv_scr_act());
    lv_obj_set_size(bar, 10, 300);
    lv_obj_align(bar, LV_ALIGN_RIGHT_MID, -30, 0);

    lv_bar_set_range(bar, rangeMin, rangeMax);
    lv_bar_set_start_value(bar, value, LV_ANIM_ON);
    lv_bar_set_value(bar, value, LV_ANIM_ON);

    lv_obj_set_style_anim_time(bar, animTime, LV_STATE_DEFAULT);
}
