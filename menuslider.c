#include "lvgl.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include "touch.h"
//#include "sys.h"
//#include "delay.h"
//#include "usart.h"
//#include "led.h"
//#include "lcd.h"
//#include "key.h"
//#include "touch.h"
//#include "lvgl.h"
//#include "lvgltest1.h"
//#include "lv_port_disp.h"
//#include "lv_port_indev.h"
//#include "ballgame.h"
//#include "key.h"
//#include "delay.h"
//#include "cubegame.h"
//#include "flygame.h"
//#include "pvz.h"
//#include "txtsend_test.h"


static int move=0;

static lv_anim_timeline_t * animline;
static lv_timer_t * t1;
static lv_timer_t * t2;
static lv_timer_t * t3;
static lv_obj_t * lable1;
static lv_obj_t * lable2;
static lv_obj_t * lable3;
static lv_obj_t * lable4;
static lv_obj_t * obj1;
static lv_obj_t * obj2;
static lv_obj_t * obj3;
static lv_obj_t * obj4;
static lv_obj_t * obj5;
static lv_obj_t * obj6;
static lv_obj_t * obj7;
static lv_obj_t * obj8;
static lv_obj_t * obj11;
static lv_obj_t * obj22;
static lv_obj_t * obj33;
static lv_obj_t * obj44;
static lv_obj_t * obj55;
static lv_obj_t * obj66;
static lv_obj_t * obj77;
static lv_obj_t * obj88;
static lv_obj_t * tile;
static lv_obj_t * tile0;
static lv_obj_t * tile1;
static void timer_cb1(lv_timer_t * t);
static void timer_cb2(lv_timer_t * t);
static void timer_cb3(lv_timer_t * t);
static lv_obj_t * botton_left;
static lv_obj_t * botton_right;

static void botton_left_event_cb(lv_event_t * e);
static void botton_right_event_cb(lv_event_t * e);
static void event_cb(lv_event_t * e);
static void event_cb1(lv_event_t * e);
static void event_cb2(lv_event_t * e);
static void event_cb3(lv_event_t * e);
static void event_cb4(lv_event_t * e);
static void event_cb5(lv_event_t * e);
static void event_cb6(lv_event_t * e);
static void event_cb7(lv_event_t * e);
static void tile0_pressing_cb(lv_event_t * e);






void menuslider()
{
	lv_obj_set_style_bg_color(lv_scr_act(),lv_color_hex(0x000020), LV_PART_MAIN);
	lv_obj_clear_flag(lv_scr_act(), LV_OBJ_FLAG_SCROLLABLE);
	tile= lv_tileview_create(lv_scr_act());
	lv_obj_set_style_bg_color(tile,lv_color_hex(0x000000), LV_PART_MAIN);

	tile0= lv_tileview_add_tile(tile, 0,0,LV_DIR_VER);
	tile1= lv_tileview_add_tile(tile, 0,1,LV_DIR_VER);
	lv_obj_set_style_bg_color(tile0,lv_color_hex(0x000000), LV_PART_MAIN);
	lv_obj_set_style_bg_color(tile1,lv_color_hex(0x000000), LV_PART_MAIN);


	obj1=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj1,20,LV_PART_MAIN);
	lv_obj_align(obj1,LV_ALIGN_CENTER, 0, -50);
	lv_obj_set_style_bg_color(obj1,lv_color_hex(0xff0020), LV_PART_MAIN);
	lv_obj_set_size(obj1,80,80);

	lable1=lv_label_create(obj1);
	lv_label_set_text(lable1, "TERIS");
	lv_obj_set_align(lable1, LV_ALIGN_OUT_BOTTOM_MID);

	lv_obj_add_event_cb(obj1,event_cb1,LV_EVENT_CLICKED,0);



	obj2=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj2,20,LV_PART_MAIN);
	lv_obj_align(obj2,LV_ALIGN_CENTER, 150, -50);
	lv_obj_set_style_bg_color(obj2,lv_color_hex(0xff00ff), LV_PART_MAIN);
	lv_obj_set_size(obj2,80,80);

	lable2=lv_label_create(obj2);
	lv_label_set_text(lable2, "PINBALL");
	lv_obj_set_align(lable2, LV_ALIGN_OUT_BOTTOM_MID);

	lv_obj_add_event_cb(obj2,event_cb2,LV_EVENT_CLICKED,0);



	obj3=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj3,20,LV_PART_MAIN);
	lv_obj_align(obj3,LV_ALIGN_CENTER, 300, -50);
	lv_obj_set_style_bg_color(obj3,lv_color_hex(0x0000ff), LV_PART_MAIN);
	lv_obj_set_size(obj3,80,80);

	lable3=lv_label_create(obj3);
	lv_label_set_text(lable3, "FLY");
	lv_obj_set_align(lable3, LV_ALIGN_OUT_BOTTOM_MID);

	lv_obj_add_event_cb(obj3,event_cb3,LV_EVENT_CLICKED,0);



	obj4=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj4,20,LV_PART_MAIN);
	lv_obj_align(obj4,LV_ALIGN_CENTER, 450, -50);
	lv_obj_set_style_bg_color(obj4,lv_color_hex(0x00ffff), LV_PART_MAIN);
	lv_obj_set_size(obj4,80,80);

	lable4=lv_label_create(obj4);
	lv_label_set_text(lable4, "PvZ");
	lv_obj_set_align(lable4, LV_ALIGN_OUT_BOTTOM_MID);

	lv_obj_add_event_cb(obj4,event_cb4,LV_EVENT_CLICKED,0);


	obj5=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj5,20,LV_PART_MAIN);
	lv_obj_align(obj5,LV_ALIGN_CENTER, 600,-50);
	lv_obj_set_style_bg_color(obj5,lv_color_hex(0x00ff00), LV_PART_MAIN);
	lv_obj_set_size(obj5,80,80);

	lv_obj_add_event_cb(obj5,event_cb5,LV_EVENT_CLICKED,0);

	obj6=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj6,20,LV_PART_MAIN);
	lv_obj_align(obj6,LV_ALIGN_CENTER, 750, -50);
	lv_obj_set_style_bg_color(obj6,lv_color_hex(0xffff00), LV_PART_MAIN);
	lv_obj_set_size(obj6,80,80);
	lv_obj_add_event_cb(obj6,event_cb6,LV_EVENT_CLICKED,0);


	obj7=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj7,20,LV_PART_MAIN);
	lv_obj_align(obj7,LV_ALIGN_CENTER, 900, -50);
	lv_obj_set_style_bg_color(obj7,lv_color_hex(0x8080ff), LV_PART_MAIN);
	lv_obj_set_size(obj7,80,80);
	lv_obj_add_event_cb(obj7,event_cb7,LV_EVENT_CLICKED,0);


	obj8=lv_obj_create(tile0);
	lv_obj_set_style_radius(obj8,20,LV_PART_MAIN);
	lv_obj_align(obj8,LV_ALIGN_CENTER, 1050, -50);
	lv_obj_set_style_bg_color(obj8,lv_color_hex(0xff8000), LV_PART_MAIN);
	lv_obj_set_size(obj8,80,80);



	obj11=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj11,20,LV_PART_MAIN);
	lv_obj_align(obj11,LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_bg_color(obj11,lv_color_hex(0xff0020), LV_PART_MAIN);
	lv_obj_set_size(obj11,80,80);

	obj22=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj22,20,LV_PART_MAIN);
	lv_obj_align(obj22,LV_ALIGN_CENTER, 150, 0);
	lv_obj_set_style_bg_color(obj22,lv_color_hex(0xff00ff), LV_PART_MAIN);
	lv_obj_set_size(obj22,80,80);

	obj33=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj33,20,LV_PART_MAIN);
	lv_obj_align(obj33,LV_ALIGN_CENTER, 300, 0);
	lv_obj_set_style_bg_color(obj33,lv_color_hex(0x0000ff), LV_PART_MAIN);
	lv_obj_set_size(obj33,80,80);

	obj44=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj44,20,LV_PART_MAIN);
	lv_obj_align(obj44,LV_ALIGN_CENTER, 450, 0);
	lv_obj_set_style_bg_color(obj44,lv_color_hex(0x00ffff), LV_PART_MAIN);
	lv_obj_set_size(obj44,80,80);

	obj55=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj55,20,LV_PART_MAIN);
	lv_obj_align(obj55,LV_ALIGN_CENTER, 600,0);
	lv_obj_set_style_bg_color(obj55,lv_color_hex(0x00ff00), LV_PART_MAIN);
	lv_obj_set_size(obj55,80,80);

	obj66=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj66,20,LV_PART_MAIN);
	lv_obj_align(obj66,LV_ALIGN_CENTER, 750,0);
	lv_obj_set_style_bg_color(obj66,lv_color_hex(0xffff00), LV_PART_MAIN);
	lv_obj_set_size(obj66,80,80);

	obj77=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj77,20,LV_PART_MAIN);
	lv_obj_align(obj77,LV_ALIGN_CENTER, 900,0);
	lv_obj_set_style_bg_color(obj77,lv_color_hex(0x8080ff), LV_PART_MAIN);
	lv_obj_set_size(obj77,80,80);

	obj88=lv_obj_create(tile1);
	lv_obj_set_style_radius(obj88,20,LV_PART_MAIN);
	lv_obj_align(obj88,LV_ALIGN_CENTER, 1050,0);
	lv_obj_set_style_bg_color(obj88,lv_color_hex(0xff8000), LV_PART_MAIN);
	lv_obj_set_size(obj88,80,80);



  lv_obj_add_event_cb(tile0,event_cb,LV_EVENT_SCROLL_END,0);
  //lv_obj_add_event_cb(tile0,tile0_pressing_cb,LV_EVENT_SCROLL,0);


//
	t1=lv_timer_create(timer_cb1, 0, 0);
//	t2=lv_timer_create(timer_cb2, 30, 0);

//	lv_obj_add_event_cb(obj1,event_cb,LV_EVENT_RELEASED,0);
//	lv_obj_add_event_cb(obj2,event_cb,LV_EVENT_RELEASED,0);
//	lv_obj_add_event_cb(obj3,event_cb,LV_EVENT_RELEASED,0);
//	lv_obj_add_event_cb(obj4,event_cb,LV_EVENT_RELEASED,0);
//	lv_obj_add_event_cb(obj5,event_cb,LV_EVENT_RELEASED,0);
//	lv_obj_add_event_cb(obj6,event_cb,LV_EVENT_RELEASED,0);
//	lv_obj_add_event_cb(obj7,event_cb,LV_EVENT_RELEASED,0);
//	lv_obj_add_event_cb(obj7,event_cb,LV_EVENT_RELEASED,0);
//lv_obj_refr_size(obj2);


}



void botton_left_event_cb(lv_event_t * e)
{

	move-=150;

lv_obj_scroll_to_x(lv_scr_act(),move, LV_ANIM_ON);
}


void botton_right_event_cb(lv_event_t * e)
{
	move+=150;

lv_obj_scroll_to_x(lv_scr_act(),move, LV_ANIM_ON);
}




//void timer_cb2(lv_timer_t * t)
//{
//
////	if(KEY0)
////	{while(KEY0);
////	move-=150;}
////
////	if(WK_UP)
////	{while(WK_UP);
////	move+=150;}
////
////	lv_obj_scroll_to_x(lv_scr_act(),move, LV_ANIM_ON);
//
//}


//void tile0_pressing_cb(lv_event_t * e)
void timer_cb1(lv_timer_t * t)
{
	int move;

	move=lv_obj_get_scroll_x(tile0);
	if(move<=150&&move>=0)
	{
		lv_obj_set_width(obj1,130-move/3);
	  lv_obj_set_height(obj1,130-move/3);
		lv_obj_set_y(obj1,-move/3);

		lv_obj_set_width(obj2,80+move/3);
	  lv_obj_set_height(obj2,80+move/3);
		lv_obj_set_y(obj2,move/3-50);
	}


	if(move<=300&&move>=150)
	{
		lv_obj_set_width(obj2,130-(move-150)/3);
	  lv_obj_set_height(obj2,130-(move-150)/3);
		lv_obj_set_y(obj2,-(move-150)/3);

    lv_obj_set_width(obj3,80+(move-150)/3);
	  lv_obj_set_height(obj3,80+(move-150)/3);
		lv_obj_set_y(obj3,(move-150)/3-50);
	}


		if(move<=450&&move>=300)
	{
		lv_obj_set_width(obj3,130-(move-300)/3);
	  lv_obj_set_height(obj3,130-(move-300)/3);
    lv_obj_set_y(obj3,-(move-300)/3);

		lv_obj_set_width(obj4,80+(move-300)/3);
	  lv_obj_set_height(obj4,80+(move-300)/3);
		lv_obj_set_y(obj4,(move-300)/3-50);
	}


		if(move<=600&&move>=450)
	{
		lv_obj_set_width(obj4,130-(move-450)/3);
	  lv_obj_set_height(obj4,130-(move-450)/3);
    lv_obj_set_y(obj4,-(move-450)/3);

		lv_obj_set_width(obj5,80+(move-450)/3);
	  lv_obj_set_height(obj5,80+(move-450)/3);
    lv_obj_set_y(obj5,(move-450)/3-50);
	}

		if(move<=750&&move>=600)
	{
		lv_obj_set_width(obj5,130-(move-600)/3);
	  lv_obj_set_height(obj5,130-(move-600)/3);
		lv_obj_set_y(obj5,-(move-600)/3);

		lv_obj_set_width(obj6,80+(move-600)/3);
	  lv_obj_set_height(obj6,80+(move-600)/3);
		lv_obj_set_y(obj6,(move-600)/3-50);
	}

		if(move<=900&&move>=750)
	{
		lv_obj_set_width(obj6,130-(move-750)/3);
	  lv_obj_set_height(obj6,130-(move-750)/3);
    lv_obj_set_y(obj6,-(move-750)/3);

		lv_obj_set_width(obj7,80+(move-750)/3);
	  lv_obj_set_height(obj7,80+(move-750)/3);
		lv_obj_set_y(obj7,(move-750)/3-50);
	}

			if(move<=1050&&move>=900)
	{
		lv_obj_set_width(obj7,130-(move-900)/3);
	  lv_obj_set_height(obj7,130-(move-900)/3);
		lv_obj_set_y(obj7,-(move-900)/3);

		lv_obj_set_width(obj8,80+(move-900)/3);
	  lv_obj_set_height(obj8,80+(move-900)/3);
		lv_obj_set_y(obj8,(move-900)/3-50);
	}




}




static void event_cb(lv_event_t * e)
{

	move=lv_obj_get_scroll_x(tile0);

	if(move%150!=0)
	{
		if(move%150<75){lv_obj_scroll_to_x(tile0, move-(move%150), LV_ANIM_ON);}
	  if(move%150>74){lv_obj_scroll_to_x(tile0, move+150-(move%150), LV_ANIM_ON);}
	}
}


static void anim_cb1(void * var, int32_t v)
{
	lv_obj_t * xxx=(lv_obj_t *)var;

	lv_obj_set_width(xxx,130+v);
	lv_obj_set_height(xxx,130+v);
}


void event_cb1(lv_event_t * e)
{
	//cube_game_start();
}

void event_cb2(lv_event_t * e)
{
  //ballgame_start();
}


void event_cb3(lv_event_t * e)
{
  //fly_game_start();
}


void event_cb4(lv_event_t * e)
{
  //pvz_start();
}


void event_cb5(lv_event_t * e)
{
 // test1();
}

void event_cb6(lv_event_t * e)
{
  //touch_move();
}

void event_cb7(lv_event_t * e)
{
  //txtsend_test();
}


