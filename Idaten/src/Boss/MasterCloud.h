#pragma once
#include"BOSS.h"
#include"AttackWind.h"
#include<memory>

class MasterCloud:public BOSS
{
	int init();
	int move_boss(HDC);
	std::unique_ptr < AttackWind > m_wind;
	int m_attackCnt;
public:

	MasterCloud(int, int);
	~MasterCloud();
};

