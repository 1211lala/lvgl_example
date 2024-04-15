#include "common.h"


extern void create_keyboard(void);
extern void connect_wifi(void);

static lv_obj_t* bgObj;
static lv_obj_t* obj_1;
static lv_obj_t* obj_2;

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

void create_keyboard(void)
{

    /* ���岢�������� */
    keyboard = lv_keyboard_create(lv_scr_act());
    /* ���� LV_PART_MAIN ���ֱ�����ɫ */
    lv_obj_set_style_bg_color(keyboard,lv_color_hex(0x1b1b1b),LV_PART_MAIN|LV_STATE_DEFAULT);
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
    lv_obj_set_style_text_color(namearea,  lv_color_hex(0xff0000), LV_STATE_DEFAULT);
    /* ������ʾ�� */
    lv_obj_set_style_bg_color(namearea, lv_color_hex(0x1b1b1b), LV_STATE_DEFAULT);
    lv_textarea_set_placeholder_text(namearea, "Enter Wifi Ssid");
    lv_obj_add_event_cb(namearea, textarea_event_cb, LV_EVENT_PRESSED, NULL);


    pwdarea = lv_textarea_create(lv_scr_act());
    lv_obj_set_width(pwdarea, WEIGHT - 40);
    lv_obj_set_height(pwdarea, HEIGHT/10);
    lv_obj_align_to(pwdarea,namearea,LV_ALIGN_OUT_BOTTOM_MID,0,HEIGHT/12);
    lv_textarea_set_align(pwdarea, LV_TEXT_ALIGN_CENTER);
    lv_obj_set_style_bg_color(pwdarea, lv_color_hex(0x1b1b1b), LV_STATE_DEFAULT);
    /* ��������ģʽ */
//    lv_textarea_set_password_mode(pwdarea, true);
    lv_textarea_set_one_line(pwdarea, true);
    lv_obj_set_style_text_font(pwdarea, &lv_font_montserrat_30 , LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(pwdarea,  lv_color_hex(0xff0000), LV_STATE_DEFAULT);
    /* ������ʾ�� */
    lv_textarea_set_placeholder_text(pwdarea, "Enter Wifi Password");
    lv_keyboard_set_textarea(keyboard, namearea);

    lv_obj_add_event_cb(pwdarea, textarea_event_cb, LV_EVENT_PRESSED, NULL);
}


static void btn_calback(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* ��ȡ����Դ */
    lv_event_code_t code = lv_event_get_code(e); /* ��ȡ�¼����� */


    if(target == obj_1)
    {
        /* ����Ч�� */
    }else if(target == obj_2)
    {
        create_keyboard();
        lv_obj_del(obj_1);
        lv_obj_del(obj_2);
    }
}
void connect_wifi(void)
{
    lv_obj_t* wifiLabel = NULL;
    lv_obj_t* otherLabel = NULL;

    bgObj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(bgObj, LV_PCT(100), LV_PCT(100));
    lv_obj_align(bgObj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(bgObj, lv_color_hex(0x1b1b1b), LV_STATE_DEFAULT);


    obj_1 = lv_obj_create(bgObj);
    lv_obj_set_size(obj_1, LV_PCT(60), LV_PCT(10));
    lv_obj_align(obj_1, LV_ALIGN_TOP_MID, 0, HEIGHT/6);
    lv_obj_set_style_bg_color(obj_1,  lv_color_hex(0x1b1b1b), LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(obj_1, LV_SCROLLBAR_MODE_OFF);


    wifiLabel = lv_label_create(obj_1);
    lv_label_set_text_fmt(wifiLabel, "reset esp32 board");
    lv_obj_set_style_text_color(wifiLabel, lv_color_hex(0xff0000), LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(wifiLabel, &lv_font_montserrat_22, LV_STATE_DEFAULT);
    lv_obj_set_align(wifiLabel, LV_ALIGN_CENTER);


    obj_2 = lv_obj_create(bgObj);
    lv_obj_set_size(obj_2, LV_PCT(60), LV_PCT(10));
    lv_obj_align_to(obj_2, obj_1,  LV_ALIGN_OUT_BOTTOM_MID, 0, HEIGHT/8);
    lv_obj_set_style_bg_color(obj_2,  lv_color_hex(0x1b1b1b), LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(obj_2, LV_SCROLLBAR_MODE_OFF);

    otherLabel = lv_label_create(obj_2);
    lv_label_set_text_fmt(otherLabel, "connect wifi ...");
    lv_obj_set_style_text_color(otherLabel, lv_color_hex(0xff0000), LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(otherLabel, &lv_font_montserrat_22, LV_STATE_DEFAULT);
    lv_obj_set_align(otherLabel, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(obj_1, btn_calback, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(obj_2, btn_calback, LV_EVENT_PRESSED, NULL);
}
