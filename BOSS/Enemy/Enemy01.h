#pragma once
#include "Enemy.h"


class Enemy01 :	public Enemy
{
private:
	//�������𓊂��Ă���G

	int init();		//�������i�I�[�o�[���C�h�j
	int move_enemy();		//�ړ��֐��i�I�[�o�[���C�h�j
	int hit_bulletcheck();


public:
	Enemy01(int,int);
	~Enemy01();
};

