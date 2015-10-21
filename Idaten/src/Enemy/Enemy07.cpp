#include "Enemy07.h"


Enemy07::Enemy07(int x,int y)
{
	
	enemy.x = x;
	enemy.y = y;
	init();
	
	enemy_hb = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy/mop/1.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	enemy_hbList = new HBITMAP [2];
	enemy_hbList[0] = enemy_hb;
	enemy_hbList[1] = (HBITMAP)LoadImage(NULL, TEXT("res/Enemy/mop/2.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

}


Enemy07::~Enemy07()
{
	DeleteObject(enemy_hb);
	DeleteObject(enemy_hbList);
}


int Enemy07::init(){
	srand((int)time(NULL));
	enemy.y += 50;
	enemy.base_y = enemy.y;
	enemy.dx = 0;
	enemy.dy = 0;

	enemy.width = 50;
	enemy.height = 70;
	enemy.step_y = 2;
	Jump = (rand() % 30 + 1) * 10;
	enemy.onActive = 1;
	enemy.actioncnt = 0;

	return 0;
}

int Enemy07::move_enemy(){
	srand((int)time(NULL));
	if (enemy.onActive == 1){	//移動ルーチン	//ランダムで地面から突き出てきます
		if (enemy.actioncnt == Jump){
			enemy.base_y = enemy.y;
			Jump = 1;
			enemy.y -= 60;
		}
		if (Jump == 1){
			enemy.dy += 0.1;
			if (enemy.y > enemy.base_y){
				enemy.y = enemy.base_y;
				enemy.dy = 0;
				Jump = (rand() % 50 + 1) * 10;
				enemy.actioncnt = 0;
			}
		}
		enemy.actioncnt++;
	}
	enemy.x += enemy.dx;
	enemy.y += enemy.dy;
	enemy.anim_count++;

	if (enemy.anim_count > 10) {
		enemy_hb = enemy_hbList[enemy.anim_flg];
		enemy.anim_count = 0;
		if (enemy.anim_flg) enemy.anim_flg = 0;
		else enemy.anim_flg = 1;
		
	}	


	hit_enemycheck();
	return 0;
}