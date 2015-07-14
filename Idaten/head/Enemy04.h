#pragma once
#include "Enemy.h"

//敵番号　４
//プレイヤーが近づくと移動をやめてその場所にとどまる。（壁のようなもの

class Enemy04 :	public Enemy{

	int init();
	int move_enemy();

public:
	Enemy04(int,int);
	~Enemy04();
};

