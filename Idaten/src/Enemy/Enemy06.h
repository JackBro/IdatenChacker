#pragma once
#include "Enemy.h"
class Enemy06 :	public Enemy{

	int init();
	int move_enemy();

public:
	Enemy06(int,int);
	~Enemy06();
};

