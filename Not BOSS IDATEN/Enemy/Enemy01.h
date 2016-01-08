#pragma once
#include "Enemy.h"


class Enemy01 :	public Enemy
{
private:
	//何か物を投げてくる敵

	int init();		//初期化（オーバーライド）
	int move_enemy();		//移動関数（オーバーライド）
	int hit_bulletcheck();


public:
	Enemy01(int,int);
	~Enemy01();
};

