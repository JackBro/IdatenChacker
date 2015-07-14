#include "Enemy05.h"


Enemy05::Enemy05(int x,int y)
{
	init();
	enemy.x = x;
	enemy.y = y;
	enemy_hb = (HBITMAP)LoadImage(NULL, TEXT("enemy.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

}


Enemy05::~Enemy05()
{
}

int Enemy05::init(){
	
	enemy.base_y = enemy.y;
	enemy.width = 40;
	enemy.height = 50;
	enemy.step_x = 5;
	enemy.step_y = 5;
	enemy.rad_x = 0;
	enemy.rad_y = 0;
	enemy.onActive = 1;
	return 0;
}

int Enemy05::move_enemy(){
	srand((int)time(NULL));
	if (enemy.onActive == 3){

		//X軸　追尾
		if (enemy.x > plstats->x + plstats->width * 2){
			enemy.dx = -enemy.step_x / 1.5;
		}
		else if (enemy.x + enemy.width < plstats->x + plstats->width){
			enemy.dx = enemy.step_x*1.5;
		}
		else
			enemy.dx = 0;

		//Y軸　追尾
		if (enemy.y > plstats->y){
			enemy.dy = -enemy.step_y / 2;
		}
		else if (enemy.y + enemy.height < plstats->y + plstats->height / 2){
			enemy.dy = enemy.step_y / 2;
		}
		else
			enemy.dy = 0;

		//二点間　視野外に出ているかどうか
		int ex = (int)enemy.x;
		int ey = (int)enemy.y;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		if ((ex - px)*(ex - px) + (ey - py)*(ey - py) >= (300)*(300)){
			enemy.onActive = 1;
		}


	}
	else if (enemy.onActive == 1){	//主な移動。波を描くように左右へ移動する。
		enemy.dx = -sin(enemy.rad_x) * 5;
		enemy.rad_x += 0.03;
		enemy.rad_y += 0.1;
		enemy.dy = -cos(enemy.rad_y) * 1;


		//二点間、視野内に入った場合。（方向は残念ながら判断できない)
		int ex = (int)enemy.x;
		int ey = (int)enemy.y;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		if ((ex - px)*(ex - px) + (ey - py)*(ey - py) <= (300)*(300)){
			enemy.onActive = 3;
		}
	}
	enemy.x += enemy.dx;
	enemy.y += enemy.dy;


	hit_enemycheck();
	return 0;
}
