#pragma once
#include "Enemy.h"
class Enemy06 :	public Enemy{

	int init();
	int move_enemy();
	int flg;

public:
	Enemy06(int,int);
	~Enemy06();
};

