#pragma once

#include<Windows.h>
#include<math.h>
#include<time.h>
#include"../player_info.h"
#include"../Option.h"

class AtackClass
{
protected:
	HDC atackhdc;

	HBITMAP atack_hb;

	int DEADflg = 0;

	player_info *plstats;

	int atackID;

	struct atack_info{
		float x, y;
		int width, height;
		int onactive;

	}atack;


public:
	int Atack_Paint(HDC atack_hb);

	int chara_strc(player_info *tp);

	int hit_atackcheck();

	int get_deadflg(int){ return DEADflg; }
	int get_atack_active(){ return atack.onactive; }

	void AtackID(int a) { atackID = a; }
	int AtackID() { return atackID; }

	int atack_scroll(int, int);

	float Atack_x();
	float Atack_y();

	virtual int init(){ return 0; }
	virtual int move(){ return 0; }

	AtackClass();
	~AtackClass();
};

