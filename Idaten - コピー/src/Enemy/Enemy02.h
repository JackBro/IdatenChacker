#pragma once
#include "Enemy.h"
class Enemy02 : public Enemy{
	int init();
	int move_enemy();
public:
	Enemy02(int,int);
	~Enemy02();
};



