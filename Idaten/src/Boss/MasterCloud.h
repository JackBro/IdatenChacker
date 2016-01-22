#pragma once
#include"BOSS.h"


class MasterCloud:public BOSS
{
	int init();
	int move_boss(HDC);
	int hit_windcheck();
public:

	MasterCloud(int, int);
	~MasterCloud();
};

