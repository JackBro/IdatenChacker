#pragma once

#include<Windows.h>
#include<math.h>
#include<time.h>
#include"../Charactor/player_info.h"
#include"../_Option/Option.h"

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
		int onActive;

	}atack;


public:
	int Atack_Paint(HDC atack_hb);

	int chara_strc(player_info *tp);

	int hit_atackcheck();

	int get_deadflg(){ return DEADflg; }
	void get_deadflg(int a){ DEADflg = a; }

	int get_atack_active(){ return atack.onActive; }

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

