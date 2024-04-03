
// lv_obj_create(lv_scr_act());     以屏幕为父对象创建一个对象
// lv_obj_del(lv_obj_t * obj);      删除一个对象，那么该对象的子类一并删除(立刻删除)。
// lv_obj_clean(lv_obj_t * obj);    删除一个对象的全部子类(立刻删除)。
// lv_obj_del_delayed(lv_obj_t * obj, uint32_t delay_ms);   延时毫秒再删除对象(等待删除)。

#include "common.h"


extern void obj_example(void);
extern void style_general(void);
extern void local_style(void);




void obj_example(void)
{
    lv_obj_t * bgObj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(bgObj, WEIGHT, HIGH);
    lv_obj_align(bgObj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(bgObj, lv_color_hex(BLACK), LV_STATE_DEFAULT );


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



static lv_style_t style_btn;

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





