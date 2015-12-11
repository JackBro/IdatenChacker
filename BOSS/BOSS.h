#pragma once

#include<Windows.h>
#include<math.h>
#include<time.h>

#include"player_info.h"

#include"Option.h"

class BOSS
{
protected:
	HDC bosshdc;

	HBITMAP boss_hb;

	int DEADflg = 0;	//“G‚ÆƒLƒƒƒ‰ƒNƒ^[‚ªÚG‚µ‚½ê‡‚É^i-‚PjƒQ[ƒW‚ğ’¼Ú‚¢‚¶‚é‚Ì‚Å|‚P
	int bossID;
	int atackID;
	int stageID;

	player_info *plstats;
	struct boss_info{
		int x, y;
		int dx, dy;
		int step_y;
		int width, height;
		int move_cnt;
		int max_cnt;
		int durability;
		int active;
	}boss;

  /*struct boss_atack_info{
		float x, y;
		int dx, dy;
		float step_x, step_y;
		int width, height;
		int atk_keep;
		int onactive;
		int t_active;
		int r_active;
		int w_active;

	}atack;*/

public:

	int BOSS_paint(HDC boss_hb);
	//int Atack_paint(HDC);
	int chara_strc(player_info *tp);

	int hit_bosscheck();
	int nohit_bosscheck();

	void BOSSID(int a) { bossID = a; }
	int BOSSID() { return bossID; }

	int get_deadflg(){ return DEADflg; }
	int get_boss_active(){ return boss.active; }

	int boss_scroll(int, int);

	int atack_scroll(int, int);

	/*float Atack_x();
	float Atack_y();*/

	float Boss_x();
	float Boss_y();

	int init(){ return 0; }
	int move_boss(){ return 0; }
	//int move_atack(){ return 0; }

	BOSS();
	~BOSS();
};

