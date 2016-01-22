#pragma once
#include"AtackClass.h"
class BossAtack:public AtackClass
{
public:
	int init();
	int move();
	BossAtack(int,int);
	~BossAtack();
};