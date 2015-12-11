#pragma once
#include"BOSS.h"

class master_cloud:public BOSS
{
	int sel;
public:
	int init();
	int move_boss();
	master_cloud(int,int);
	~master_cloud();
};

