#pragma once

#include<Windows.h>
#include<math.h>
#include<time.h>

#include"../Charactor/player_info.h"

#include"../_Option/Option.h"

#include"../_Option/debugmsg.h"

class BOSS
{
protected:
	HDC bosshdc;

	HBITMAP boss_hb;
	HBITMAP wind_hb;

	int DEADflg = 0;	//“G‚ÆƒLƒƒƒ‰ƒNƒ^[‚ªÚG‚µ‚½ê‡‚É^i-‚PjƒQ[ƒW‚ğ’¼Ú‚¢‚¶‚é‚Ì‚Å|‚P
	int bossID;
	int stageID;

	player_info *plstats;

	struct wind_info{

		int x,y;
		int dx;
		int width, height;
		int active;
	}wind;

	struct boss_info{
		int x, y;
		int dx, dy;
		int step_y;
		int width, height;
		
		int move_cnt;
		int max_cnt;
		int hit_cnt;

		int durability;
		int active;
	}boss;



public:

	int BOSS_paint(HDC boss_hb);
	int Wind_paint();
	int chara_strc(player_info *tp);

	int hit_bosscheck();
	int nohit_bosscheck();

	void BOSSID(int a) { bossID = a; }
	int BOSSID() { return bossID; }

	int get_deadflg(){ return DEADflg; }
	int get_boss_active(){ return boss.active; }

	int boss_scroll(int, int);
	int wind_scroll(int, int);

	float Boss_x();
	float Boss_y();

	virtual int init(){ return 0; }
	virtual int move_boss(HDC){ return 0; }
	//int move_atack(){ return 0; }

	BOSS();
	~BOSS();
};

