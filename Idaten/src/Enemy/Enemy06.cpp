#include "Enemy06.h"


Enemy06::Enemy06(int x,int y)
{
	enemy.x = x;
	enemy.y = y;
	init();
	enemy_hb = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy_H/bucket/1.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	enemy_hbList = new HBITMAP[4];

	enemy_hbList[0] = enemy_hb;
	enemy_hbList[1] = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy_H/bucket/2.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	enemy_hbList[2] = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy_H/bucket/3.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	enemy_hbList[3] = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy_H/bucket/4.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	flg = 0;
}


Enemy06::~Enemy06()
{
	DeleteObject(enemy_hb);
	DeleteObject(enemy_hbList);
}

int Enemy06::init(){
	srand((int)time(NULL));
	
	enemy.base_y = enemy.y;
	enemy.dx = 0;
	enemy.dy = 0;


	enemy.width = 50;
	enemy.height = 50;
	enemy.step_x = 2;
	Jump = (rand() % 30 + 1) * 10;
	enemy.MAX_Tcnt = 300;
	enemy.actioncnt = 0;
	enemy.timecnt = 0;

	enemy.onActive = 1;

	return 0;
}

int Enemy06::move_enemy(){
	srand((int)time(NULL));
	if (enemy.onActive == 1){	//移動ルーチン	//ランダムでジャンプします
		if (enemy.actioncnt == Jump){
			enemy.base_y = enemy.y;
			Jump = 1;
			enemy.dy -= 15;
		}
		if (Jump == 1){
			enemy.dy += 0.8;
			if (enemy.y > enemy.base_y){
				enemy.y = enemy.base_y;
				enemy.dy = 0;
				Jump = (rand() % 50 + 1) * 10;
				enemy.actioncnt = 0;
			}
		}
		if (Jump != 1){
			//最大値以上
			if (enemy.timecnt >= enemy.MAX_Tcnt){
				enemy.timecnt = 0;
			}
			else if (enemy.timecnt <= enemy.MAX_Tcnt / 2){
				enemy.dx = -enemy.step_x;

			}
			else if (enemy.timecnt > 0){
				enemy.dx = enemy.step_x;
			}
		}
		enemy.timecnt++;
		enemy.actioncnt++;
	}
	enemy.x += enemy.dx;
	enemy.y += enemy.dy;

	enemy.anim_count++;
	if (enemy.anim_count > 10) {
		enemy_hb = enemy_hbList[enemy.anim_flg];
		enemy.anim_count = 0;
		enemy.anim_flg++;

		if (enemy.anim_flg > 3) {
			enemy.anim_flg = 0;
		}

	}

	hit_enemycheck();
	return 0;
}