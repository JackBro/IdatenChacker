#include "Enemy04.h"


Enemy04::Enemy04(int x,int y)
{
	init();
	enemy.x = x;
	enemy.y = y;
	enemy_hb = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy/wall/1.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

}


Enemy04::~Enemy04()
{
	DeleteObject(enemy_hb);
	DeleteObject(enemy_hbList);
}

int Enemy04::init(){
	enemy.base_y = enemy.y;
	enemy.dx = 0;
	enemy.dy = 0;

	enemy.y -= 150;
	enemy.width = 80;
	enemy.height = 80;
	enemy.step_x = 2;
	enemy.step_y = 2;
	enemy.onActive = 1;
	enemy.timecnt = 0;
	return 0;
}

int Enemy04::move_enemy(){
	srand((int)time(NULL));
	if (enemy.onActive == 3){
		enemy.dx = 0;
		enemy.dy = 0;

		//二点間　視野外に出ているかどうか
		//方向は関係なく一定距離離れることにより元のルーチンへ戻る
		int ex = (int)enemy.x;
		int ey = (int)enemy.y;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		if ((ex - px)*(ex - px) + (ey - py)*(ey - py) >= (400)*(400)){
			enemy.onActive = 1;
		}
	}
	else if (enemy.onActive == 1){	//移動ルーチン	//ランダムで停止ステップがあっても面白そう（休憩みたいな感じで）
		if (enemy.timecnt > 0){
			enemy.dx = enemy.step_x;

			if (plstats->width + plstats->x > enemy.x){
				//二点間　視野内にいるかどうか
				int ex = (int)enemy.x;
				int ey = (int)enemy.y;
				int px = (int)plstats->x;
				int py = (int)plstats->y;
				if ((ex - px)*(ex - px) + (ey - py)*(ey - py) <= (200)*(200)){
					enemy.onActive = 3;
				}
			}
			if (enemy.timecnt >= 100){
				enemy.timecnt = -100;
			}
		}
		else if (enemy.timecnt <= 0){
			enemy.dx = -enemy.step_x;

			if (enemy.width + enemy.x > plstats->x){
				//二点間　視野内にいるかどうか
				int ex = (int)enemy.x;
				int ey = (int)enemy.y;
				int px = (int)plstats->x;
				int py = (int)plstats->y;
				if ((ex - px)*(ex - px) + (ey - py)*(ey - py) <= (200)*(200)){
					enemy.onActive = 3;
				}
			}
		}
	
		enemy.timecnt++;


	}
	enemy.x += enemy.dx;
	enemy.y += enemy.dy;
	

	hit_enemycheckRide();
	return 0;
}