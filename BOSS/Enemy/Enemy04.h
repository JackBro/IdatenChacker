#pragma once
#include "Enemy.h"

//�G�ԍ��@�S
//�v���C���[���߂Â��ƈړ�����߂Ă��̏ꏊ�ɂƂǂ܂�B�i�ǂ̂悤�Ȃ���

class Enemy04 :	public Enemy{

	int init();
	int move_enemy();

public:
	Enemy04(int,int);
	~Enemy04();
};

