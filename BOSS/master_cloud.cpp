#include "master_cloud.h"

master_cloud::master_cloud(int x,int y)
{
	init();
	boss.x = x;
	boss.y = y;

	boss_hb = (HBITMAP)LoadImage(NULL, TEXT("マスタークラウド.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}


master_cloud::~master_cloud()
{
	DeleteObject(boss_hb);
}

int master_cloud::init(){

	boss.step_y = 2;
	
	boss.width = 150;
	boss.height = 180;

	boss.max_cnt = 150;
	boss.move_cnt = 0;

	boss.active = 1;
	boss.durability = 3;
	return 0;
}

int  master_cloud::move_boss(){

	if (boss.active == 1){

		if (boss.move_cnt >= boss.max_cnt){
			boss.move_cnt = 0;
		}
		else if (boss.move_cnt <= boss.max_cnt / 2){
			boss.dy = boss.step_y;
		}
		else if (boss.move_cnt > 0){
			boss.dy = -boss.step_y;
		}
		boss.move_cnt++;
	}
	boss.y += boss.dy;
	if (boss.durability <= 0){
		boss.active = 0;
	}
	hit_bosscheck();
	return 0;
}
