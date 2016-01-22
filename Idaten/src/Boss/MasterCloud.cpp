#pragma once
#include "MasterCloud.h"

MasterCloud::MasterCloud(int x, int y)
{
	init();
	boss.x = x;
	boss.y = y;

	boss_hb = (HBITMAP)LoadImage(NULL, TEXT("res/BOSS/MasterCloud.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	wind_hb = (HBITMAP)LoadImage(NULL, TEXT("res/BOSS/Wind2.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}


MasterCloud::~MasterCloud()
{
	DeleteObject(boss_hb);
}

int MasterCloud::init(){

	boss.step_y = 2;


	boss.dx = 0;
	boss.dy = 0;

	boss.width = 150;
	boss.height = 180;

	boss.max_cnt = 150;
	boss.move_cnt = 0;

	boss.active = 1;
	boss.durability = 3;
	return 0;
}

int  MasterCloud::move_boss(HDC hdc){
		
	
	boss.move_cnt++;
	DebugStringVal("%d", boss.move_cnt, hdc, 200, 250, 20);
		 if (boss.move_cnt > boss.max_cnt)
		{
				boss.move_cnt = 0;
		}
		else if (boss.move_cnt <= boss.max_cnt / 2)
		{
			boss.dy = boss.step_y;
			/*boss.move_cnt++;
			DebugStringVal("%d", boss.move_cnt, hdc, 200, 250, 20);*/
		}
		else if (boss.move_cnt > 0)
		{
			boss.dy = -boss.step_y;
		}

		
		boss.y += boss.dy;
		
	hit_bosscheck();
	return 0;
}

int MasterCloud::hit_windcheck()
{
	if (wind.active & 1){

		int ex = wind.x;
		int ey = wind.y;
		int ew = ex + wind.width;
		int eh = ey + wind.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			if (plstats->c_flg != 3 && plstats->c_flg != 2){

			}
			else{
				DEADflg = -1;
				wind.active = 0;
			}
		}
	}
	else
		DEADflg = 0;
	return 0;
}
