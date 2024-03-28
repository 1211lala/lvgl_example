#include "lvglstart.h"
#include "lvgl.h"




void lvgl_init(void)
{
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 50, 50);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
}
