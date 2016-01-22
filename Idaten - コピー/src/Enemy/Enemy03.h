#pragma once
#include "Enemy.h"
class Enemy03 :	public Enemy{

	int init();
	int move_enemy();

public:
	Enemy03(int,int);
	~Enemy03();
};

