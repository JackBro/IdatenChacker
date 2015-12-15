#pragma once

#include<vector>
#include<memory>
#include"BOSS.h"

#include"master_cloud.h"

#include"player_info.h"
#include"Option.h"

#include"debugmsg.h"

class bossmanager
{
	HDC bosshdc;

	player_info *plstats;

	int ex, ey;
	int scroll_x, scroll_y;
	int maps_x, maps_y;

	int deadflg;
	int stageID;
	int size;

	int POP_BOSS();
	int GET_POINT(int a);
	void SET_POINT();

	int POPPOINT[2];
	std::vector<std::vector<int>>DESINATE; //ç¿ïWÇäiî[Ç∑ÇÈÇΩÇﬂ

	//std::vector<int>POPLIST;		
	//int POPLIST[1];
public:

	std::unique_ptr<BOSS> bsobj;

	int chara_strc(player_info *tp);

	int BOSS_SCROLL(int, int);
	int STAGE_COOD(int, int);

	void MAIN(HDC);

	int GetDeadflag();			
	int GetDeadflag(int);
	bossmanager();
	bossmanager(int);
	~bossmanager();
};