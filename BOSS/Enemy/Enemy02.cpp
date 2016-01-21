#include "Enemy02.h"


Enemy02::Enemy02(int x,int y)
{
	init();
	enemy.x = x;
	enemy.y = y;
	enemy_hb = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy_H/bomb/1.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	enemy_hbList = new HBITMAP[3];
	enemy_hbList[0] = enemy_hb;
	enemy_hbList[1] = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy_H/bomb/2.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	enemy_hbList[2] = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy_H/bomb/3.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


}


Enemy02::~Enemy02()
{
	DeleteObject(enemy_hb);
	DeleteObject(enemy_hbList);
}

int Enemy02::init(){
	enemy.base_y = enemy.y;
	enemy.dx = 0;
	enemy.dy = 0;
	enemy.width = 60;
	enemy.height = 60;
	enemy.step_x = 4;
	enemy.step_y = 4;
	enemy.onActive = 1;
	return 0;
}

int Enemy02::move_enemy(){

	srand((int)time(NULL));
	//DebugStringVal("%d", enemy.onActive, enemyhdc, enemy.x, enemy.y, 20);

//	DebugStringFloat("%d", enemy.x, enemyhdc, 200, 40, 20);
	if (enemy.onActive == 1){
		//二点間　視野内にいるかどうか
		int ex = (int)enemy.x;
		int ey = (int)enemy.y;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		if ((ex - px)*(ex - px) + (ey - py)*(ey - py) <= (200)*(200)){
			enemy.onActive = 3;
			enemy.timecnt = -10;
		}
	}
	else if (enemy.onActive == 3){
		//予備動作
		enemy_hb = enemy_hbList[1];
		enemy.timecnt++;
		if (enemy.timecnt > 15){
			enemy.timecnt = 0;
			enemy.onActive = 5;
			enemy.dx = 0;
			return 0;
		}
		enemy.step_x *= -1;
		enemy.dx = enemy.step_x;
	}
	else if (enemy.onActive == 5){
		//爆発アニメーション？
		enemy.timecnt++;
		enemy_hb = enemy_hbList[2];
		enemy.x -= 15;
		enemy.y -= 15;
		enemy.width += 30;
		enemy.height += 30;

		if (enemy.timecnt > 5){
			enemy.onActive = -1;
			enemy.timecnt = 0;
		}
	}
	enemy.x += enemy.dx;
	enemy.y += enemy.dy;

	if (enemy.onActive == 5){
		hit_enemycheckN();
	}else
		hit_enemycheck();
	return 0;
}