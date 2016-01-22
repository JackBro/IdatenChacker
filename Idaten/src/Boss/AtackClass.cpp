#include "AtackClass.h"


AtackClass::AtackClass()
{
	atack.x = 0;
	atack.y = 0;
	atack.width = 0;
	atack.height = 0;
	atack.onactive = 0;
	atackID = 0;
}


AtackClass::~AtackClass()
{
}


int AtackClass::Atack_Paint(HDC hdc){

	atackhdc = hdc;

	if (atack.onactive & 1){
		HDC hdc_work;
		hdc_work = CreateCompatibleDC(hdc);
		SelectObject(hdc_work, atack_hb);
		int ex = atack.x;
		int ey = atack.y;
		TransparentBlt(hdc, ex, ey, atack.width, atack.height, hdc_work, 0, 0, 50, 120, RGB(0, 0, 0));
		DeleteDC(hdc_work);
	}
	return 0;
}

int AtackClass::chara_strc(player_info *tp)
{
	plstats = tp;
	return 0;
}

int AtackClass::hit_atackcheck()
{
	if (atack.onactive & 1 && atack.onactive > 0){
		int ex = atack.x;
		int ey = atack.y;
		int ew = ex + atack.width;
		int eh = ey + atack.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			if (plstats->c_flg != 3 && plstats->c_flg != 2){
				if (ey <= ph - 10){
					atack.onactive = 0;
					DEADflg = -2;
				}
			}
		}
	}
	return 0;
}

int AtackClass::atack_scroll(int x,int y)
{
	atack.x = x;
	atack.y = y;
	return 0;
}

float AtackClass::Atack_x()
{
	return atack.x;
}

float AtackClass::Atack_y()
{
	return atack.y;
}