#include "common.h"


extern void keyboard_example(void);

static lv_obj_t* bgObj;
static lv_obj_t* keyboard;
static lv_obj_t* namearea;
static lv_obj_t* pwdarea;

static void keyboard_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e); /* ��ȡ�¼����� */
    lv_obj_t *target = lv_event_get_target(e); /* ��ȡ����Դ */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        /* ��ȡ���̰�ť���� */
         uint16_t id = lv_btnmatrix_get_selected_btn(target);
        /* ��ȡ��ť�ı� */
         const char *btntxt = lv_btnmatrix_get_btn_text(target, id);
         if(strcmp(btntxt, LV_SYMBOL_KEYBOARD) == 0) /* �ж��ǲ��Ǽ���ͼ�걻���� */
         {
            /* ��ȡ��ǰ����ģʽ���ж��Ƿ�Ϊ����ģʽ */
            if(lv_keyboard_get_mode(target) == LV_KEYBOARD_MODE_NUMBER)
            {
                /* ���������ģʽ�����л�ΪСд��ĸģʽ */
                lv_keyboard_set_mode(target, LV_KEYBOARD_MODE_TEXT_LOWER);
            }
            else
            {
                /* ��������ģʽ�����л�Ϊ����ģʽ */
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
    lv_obj_t *target = lv_event_get_target(e); /* ��ȡ����Դ */
    lv_event_code_t code = lv_event_get_code(e); /* ��ȡ�¼����� */


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
    /* ���岢�������� */
    keyboard = lv_keyboard_create(lv_scr_act());
    /* ���� LV_PART_MAIN ���ֱ�����ɫ */
    lv_obj_set_style_bg_color(keyboard,lv_palette_main(LV_PALETTE_GREY),LV_PART_MAIN|LV_STATE_DEFAULT);
    /* ���� LV_PART_ITEMS ���ֱ�����ɫ */
    lv_obj_set_style_bg_color(keyboard, lv_palette_main(LV_PALETTE_RED),LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(keyboard, keyboard_event_cb,LV_EVENT_VALUE_CHANGED, NULL);


    namearea = lv_textarea_create(lv_scr_act());
    lv_obj_set_width(namearea, WEIGHT - 40);
    lv_obj_set_height(namearea, HEIGHT/10);
    lv_obj_align(namearea,LV_ALIGN_TOP_MID,0,HEIGHT/12);
    /* �����ı����� */
    lv_textarea_set_align(namearea, LV_TEXT_ALIGN_CENTER);
    /* �����ı�����ģʽ */
    lv_textarea_set_one_line(namearea, true);
    lv_obj_set_style_text_font(namearea, &lv_font_montserrat_30 , LV_STATE_DEFAULT);
    /* ������ʾ�� */
    lv_textarea_set_placeholder_text(namearea, "Enter Wifi Ssid");
    lv_obj_add_event_cb(namearea, textarea_event_cb, LV_EVENT_PRESSED, NULL);


    pwdarea = lv_textarea_create(lv_scr_act());
    lv_obj_set_width(pwdarea, WEIGHT - 40);
    lv_obj_set_height(pwdarea, HEIGHT/10);
    lv_obj_align_to(pwdarea,namearea,LV_ALIGN_OUT_BOTTOM_MID,0,HEIGHT/12);
    lv_textarea_set_align(pwdarea, LV_TEXT_ALIGN_CENTER);
    /* ��������ģʽ */
//    lv_textarea_set_password_mode(pwdarea, true);
    lv_textarea_set_one_line(pwdarea, true);
    lv_obj_set_style_text_font(pwdarea, &lv_font_montserrat_30 , LV_STATE_DEFAULT);
    /* ������ʾ�� */
    lv_textarea_set_placeholder_text(pwdarea, "Enter Wifi Password");

    lv_obj_add_event_cb(pwdarea, textarea_event_cb, LV_EVENT_PRESSED, NULL);
}
