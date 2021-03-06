#include "Enemy01.h"

Enemy01::Enemy01(int x,int y){
	init();
	enemy.x = x;
	enemy.y = y;
	enemy_hb = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy/shot/1.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	bullet_hb = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy/shot/bullet.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
Enemy01::~Enemy01(){
	DeleteObject(enemy_hb);
	DeleteObject(bullet_hb);
	DeleteObject(enemy_hbList);
}

int Enemy01::init(){
	//座標は後で修正する
	enemy.base_y = enemy.y;
	enemy.width = 60;
	enemy.height = 60;
	enemy_bullet.width = 45;
	enemy_bullet.height = 45;
	enemy.onActive = 1;

	return 0;
}

int Enemy01::move_enemy(){
	srand((int)time(NULL));
			if (enemy.onActive == 1){
				//二点間　視野内にいるかどうか
				int ex = (int)enemy.x;
				int ey = (int)enemy.y;
				int px = (int)plstats->x;
				int py = (int)plstats->y;
				if ((ex - px)*(ex - px) + (ey - py)*(ey - py) <= (300)*(300)){
					enemy.onActive = 3;
					//弾の発生
					enemy_bullet.x = enemy.x;
					enemy_bullet.y = enemy.y;
					enemy_bullet.dx = rand() % 5 + 10;
					enemy_bullet.dy = rand() % 5 + 20;
					enemy_bullet.onActive = 1;
				}
			}
			else if (enemy.onActive == 3){
				enemy_bullet.dx *= 0.97;
				enemy_bullet.dy -= 1.1;

				enemy_bullet.x -= enemy_bullet.dx;
				enemy_bullet.y -= enemy_bullet.dy;


				if (enemy_bullet.y > enemy.y + 100) {
					enemy.onActive = 1;
					enemy_bullet.onActive = 0;
				}
			}

			


			hit_bulletcheck();
			hit_enemycheck();
			enemyPaintBullet();
			return 0;
}

int Enemy01::hit_bulletcheck(){
	if (enemy_bullet.onActive & 1){
		//当たり判定　四角形
		//玉だけの判定なのでプレイヤーがあたっても敵は消さない
		int ex = enemy_bullet.x;
		int ey = enemy_bullet.y;
		int ew = ex + enemy_bullet.width;
		int eh = ey + enemy_bullet.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			if (plstats->c_flg == 3 || plstats->c_flg == 2){}
			else
				DEADflg = -1;		//あたったら死亡

			enemy_bullet.onActive = 0;
		}
		
	}
	else
		DEADflg = 0;
	return 0;
}
