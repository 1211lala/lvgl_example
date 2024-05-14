
// lv_obj_create(lv_scr_act());     以屏幕为父对象创建一个对象
// lv_obj_del(lv_obj_t * obj);      删除一个对象，那么该对象的子类一并删除(立刻删除)。
// lv_obj_clean(lv_obj_t * obj);    删除一个对象的全部子类(立刻删除)。
// lv_obj_del_delayed(lv_obj_t * obj, uint32_t delay_ms);   延时毫秒再删除对象(等待删除)。

#include "lvglstart.h"

extern void obj_example(void);
/********************************************************************************************************************/
static uint32_t bg_color[3] = {LCD_RED, LCD_YELLOW, LCD_GREEN};
static lv_obj_t *objArray[3];
static lv_obj_t *label[3];
static lv_obj_t *btn;
static lv_obj_t *bg1;

static void button_event_cb(lv_event_t *event)
{
    static int8_t flag = 0;
    lv_obj_t *target = lv_event_get_target(event);   /*获取触发部件类型*/
    lv_event_code_t code = lv_event_get_code(event); /*获取触发事件类型*/

    if (target == btn)
    {
        if (code == LV_EVENT_SHORT_CLICKED)
        {
            if (flag == 0)
            {
                lv_obj_clear_flag(objArray[0], LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(objArray[1], LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(objArray[2], LV_OBJ_FLAG_HIDDEN);
            }
            else if (flag == 1)
            {
                lv_obj_add_flag(objArray[0], LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(objArray[1], LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(objArray[2], LV_OBJ_FLAG_HIDDEN);
            }
            else if (flag == 2)
            {
                lv_obj_add_flag(objArray[0], LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(objArray[1], LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(objArray[2], LV_OBJ_FLAG_HIDDEN);
                flag = -1;
            }
            flag += 1;
        }
        else if (code == LV_EVENT_LONG_PRESSED)
        {
            lv_obj_add_flag(bg1, LV_OBJ_FLAG_HIDDEN);

            lv_obj_clear_flag(tile, LV_OBJ_FLAG_HIDDEN);

            lv_obj_del(bg1);
        }
    }
}

void obj_example(void)
{
    bg1 = lv_obj_create(bgObj);
    lv_obj_set_size(bg1, LCD_W, LCD_H);

    for (uint8_t i = 0; i < 3; i++)
    {
        objArray[i] = lv_obj_create(bg1);

        lv_obj_set_size(objArray[i], LV_PCT(60), LV_PCT(30));
        lv_obj_set_style_bg_color(objArray[i], lv_color_hex(bg_color[i]), LV_STATE_DEFAULT);
        lv_obj_align(objArray[i], LV_ALIGN_CENTER, 0, -LCD_H / 5);

        lv_obj_add_flag(objArray[i], LV_OBJ_FLAG_HIDDEN);

        label[i] = lv_label_create(objArray[i]);
        lv_label_set_text_fmt(label[i], "OBJ%d", i);
        lv_obj_align(label[i], LV_ALIGN_CENTER, 0, 0);
    }

    btn = lv_btn_create(bg1);
    lv_obj_set_size(btn, LV_PCT(15), LV_PCT(8));
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, LCD_H / 3);
    lv_obj_add_event_cb(btn, button_event_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(btn, button_event_cb, LV_EVENT_LONG_PRESSED, NULL);
}
