#pragma once

#include<Windows.h>

#include"../Charactor/player_info.h"
#include"../_Option/Option.h"
class AttackWind
{
public:
	AttackWind();
	AttackWind(int, int);
	~AttackWind() = default;

	void Draw(HDC);
	void Scroll(int, int);
	int IsHit();
	bool Update();

	int GetDeadflg(){
		return DEADflg;
	}
	void GetDeadflg(int a){
		DEADflg = a;
	}
	void chara_strc(player_info *tp){
		plstats = tp;
	}
private:
	HBITMAP wind_hb;
	int DEADflg = 0;	//“G‚ÆƒLƒƒƒ‰ƒNƒ^[‚ªÚG‚µ‚½ê‡‚É^i-‚PjƒQ[ƒW‚ğ’¼Ú‚¢‚¶‚é‚Ì‚Å|‚P

private:
	player_info *plstats;
	struct wind_info{
		int x, y;
		int dx;
		int width, height;
		int active;
	}s_wind;

};

