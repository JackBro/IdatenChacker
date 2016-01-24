#pragma once

#include<vector>
#include<memory>
#include"BOSS.h"

#include"MasterCloud.h"

#include"../Charactor/player_info.h"
#include"../_Option/Option.h"

#include"../_Option/debugmsg.h"

class BossManager
{
	HDC bosshdc;

	player_info *plstats;

	int ex, ey;
	int scroll_x, scroll_y;
	int maps_x, maps_y;

	int deadflg;
	bool AlreadySpawn;
	int POP_BOSS();
	int GET_POINT(int a);
	void SET_POINT();

	int POPPOINT[2];
	std::vector<std::vector<int>>DESINATE; //ç¿ïWÇäiî[Ç∑ÇÈÇΩÇﬂ

public:

	std::unique_ptr<BOSS> bsobj;

	int chara_strc(player_info *tp);

	int BOSS_SCROLL(int, int);
	int STAGE_COOD(int, int);

	int MAIN(HDC);

	int GetDeadflag();
	int GetDeadflag(int);
	BossManager();
	~BossManager();
};