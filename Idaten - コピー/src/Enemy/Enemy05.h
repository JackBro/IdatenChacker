#pragma once
#include "Enemy.h"
class Enemy05 :	public Enemy{
	
	int init();
	int move_enemy();

public:
	Enemy05(int,int);
	~Enemy05();
};

