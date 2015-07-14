#include "Enemy03.h"


Enemy03::Enemy03(int x,int y)
{
	init();
	enemy.x = x;
	enemy.y = y;
	enemy_hb = (HBITMAP)LoadImage(NULL, TEXT("enemy.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

}


Enemy03::~Enemy03()
{
}

int Enemy03::init(){
	enemy.base_y = enemy.y;
	enemy.dx = 0;
	enemy.dy = 0;

	enemy.width = 60;
	enemy.height = 30;
	enemy.step_x = 2;
	enemy.step_y = 2;
	enemy.onActive = 1;
	return 0;
}

int Enemy03::move_enemy(){
	srand((int)time(NULL));
	if (enemy.onActive == 1){
		//“ñ“_ŠÔ@Ž‹–ì“à‚É‚¢‚é‚©‚Ç‚¤‚©
		int ex = (int)enemy.x;
		int ey = (int)enemy.y;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		if ((ex - px)*(ex - px) + (ey - py)*(ey - py) <= (400)*(400)){
			enemy.onActive = 3;
			enemy.timecnt = -10;
			enemy.dx = -1;
		}
	}
	else if (enemy.onActive == 3){
		enemy.dx *= 1.065;
	}
	if (enemy.dx < -30){
		enemy.dx = -30;
	}
	enemy.x += enemy.dx;
	enemy.y += enemy.dy;
	if (enemy.x < -1000){
		enemy.onActive = 0;
	}


	hit_enemycheck();
	return 0;
}