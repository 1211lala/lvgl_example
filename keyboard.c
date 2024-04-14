#include "common.h"


extern void keyboard_example(void);

static lv_obj_t* bgObj;
static lv_obj_t* keyboard;
static lv_obj_t* namearea;
static lv_obj_t* pwdarea;

static void keyboard_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e); /* 获取事件类型 */
    lv_obj_t *target = lv_event_get_target(e); /* 获取触发源 */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        /* 获取键盘按钮索引 */
         uint16_t id = lv_btnmatrix_get_selected_btn(target);
        /* 获取按钮文本 */
         const char *btntxt = lv_btnmatrix_get_btn_text(target, id);
         if(strcmp(btntxt, LV_SYMBOL_KEYBOARD) == 0) /* 判断是不是键盘图标被按下 */
         {
            /* 获取当前键盘模式，判断是否为数字模式 */
            if(lv_keyboard_get_mode(target) == LV_KEYBOARD_MODE_NUMBER)
            {
                /* 如果是数字模式，则切换为小写字母模式 */
                lv_keyboard_set_mode(target, LV_KEYBOARD_MODE_TEXT_LOWER);
            }
            else
            {
                /* 不是数字模式，则切换为数字模式 */
                lv_keyboard_set_mode(target, LV_KEYBOARD_MODE_NUMBER);
            }
         }
        else if(strcmp(btntxt, LV_SYMBOL_OK) == 0)
        {
            const char * namedata = lv_textarea_get_text(namearea);
            const char * pwddata = lv_textarea_get_text(pwdarea);
            printf("\r\nssid: %s \r\n", namedata);
            printf("pwd : %s \r\n", pwddata);
        }
    }
}


static void textarea_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* 获取触发源 */
    lv_event_code_t code = lv_event_get_code(e); /* 获取事件类型 */


    if(target == namearea)
    {
        printf("namearea");
        lv_keyboard_set_textarea(keyboard, namearea);
    }else if(target == pwdarea)
    {
        printf("pwdarea");
        lv_keyboard_set_textarea(keyboard, pwdarea);
    }

}

void keyboard_example(void)
{

//    bgObj = lv_obj_create(lv_scr_act());
//    lv_obj_set_size(bgObj, LV_PCT(100), LV_PCT(100));
//    lv_obj_set_style_bg_color(bgObj, lv_color_hex(0x1b1b1b), LV_STATE_DEFAULT);
//    lv_obj_set_align(bgObj);
    /* 定义并创建键盘 */
    keyboard = lv_keyboard_create(lv_scr_act());
    /* 设置 LV_PART_MAIN 部分背景颜色 */
    lv_obj_set_style_bg_color(keyboard,lv_palette_main(LV_PALETTE_GREY),LV_PART_MAIN|LV_STATE_DEFAULT);
    /* 设置 LV_PART_ITEMS 部分背景颜色 */
    lv_obj_set_style_bg_color(keyboard, lv_palette_main(LV_PALETTE_RED),LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(keyboard, keyboard_event_cb,LV_EVENT_VALUE_CHANGED, NULL);


    namearea = lv_textarea_create(lv_scr_act());
    lv_obj_set_width(namearea, WEIGHT - 40);
    lv_obj_set_height(namearea, HEIGHT/10);
    lv_obj_align(namearea,LV_ALIGN_TOP_MID,0,HEIGHT/12);
    /* 设置文本对齐 */
    lv_textarea_set_align(namearea, LV_TEXT_ALIGN_CENTER);
    /* 设置文本单行模式 */
    lv_textarea_set_one_line(namearea, true);
    lv_obj_set_style_text_font(namearea, &lv_font_montserrat_30 , LV_STATE_DEFAULT);
    /* 设置提示语 */
    lv_textarea_set_placeholder_text(namearea, "Enter Wifi Ssid");
    lv_obj_add_event_cb(namearea, textarea_event_cb, LV_EVENT_PRESSED, NULL);


    pwdarea = lv_textarea_create(lv_scr_act());
    lv_obj_set_width(pwdarea, WEIGHT - 40);
    lv_obj_set_height(pwdarea, HEIGHT/10);
    lv_obj_align_to(pwdarea,namearea,LV_ALIGN_OUT_BOTTOM_MID,0,HEIGHT/12);
    lv_textarea_set_align(pwdarea, LV_TEXT_ALIGN_CENTER);
    /* 设置密码模式 */
//    lv_textarea_set_password_mode(pwdarea, true);
    lv_textarea_set_one_line(pwdarea, true);
    lv_obj_set_style_text_font(pwdarea, &lv_font_montserrat_30 , LV_STATE_DEFAULT);
    /* 设置提示语 */
    lv_textarea_set_placeholder_text(pwdarea, "Enter Wifi Password");

    lv_obj_add_event_cb(pwdarea, textarea_event_cb, LV_EVENT_PRESSED, NULL);
}
