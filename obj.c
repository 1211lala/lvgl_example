#include "obj.h"
//lv_obj_create(lv_scr_act());  ����ĻΪ�����󴴽�һ������
//lv_obj_del(lv_obj_t * obj);   ɾ��һ��������ô�ö��������һ��ɾ��(����ɾ��)��
// lv_obj_clean(lv_obj_t * obj);    ɾ��һ�������ȫ������(����ɾ��)��
// lv_obj_del_delayed(lv_obj_t * obj, uint32_t delay_ms);   ��ʱ������ɾ������(�ȴ�ɾ��)��


#define HIGH    280
#define WEIGHT  240

#define black 0x0b0b0b
void obj_init(void)
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


