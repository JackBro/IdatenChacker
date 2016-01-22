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

		//��_�ԁ@����O�ɏo�Ă��邩�ǂ���
		//�����͊֌W�Ȃ���苗������邱�Ƃɂ�茳�̃��[�`���֖߂�
		int ex = (int)enemy.x;
		int ey = (int)enemy.y;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		if ((ex - px)*(ex - px) + (ey - py)*(ey - py) >= (400)*(400)){
			enemy.onActive = 1;
		}
	}
	else if (enemy.onActive == 1){	//�ړ����[�`��	//�����_���Œ�~�X�e�b�v�������Ă��ʔ������i�x�e�݂����Ȋ����Łj
		if (enemy.timecnt > 0){
			enemy.dx = enemy.step_x;

			if (plstats->width + plstats->x > enemy.x){
				//��_�ԁ@������ɂ��邩�ǂ���
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
				//��_�ԁ@������ɂ��邩�ǂ���
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