#include "AttackWind.h"
#include<time.h>
#include<iostream>

AttackWind::AttackWind()
{
	srand((unsigned int)time(NULL));
	SecureZeroMemory(&s_wind, sizeof(wind_info));
	s_wind.x = WINDOW_WIDTH;
	s_wind.y = rand() % WINDOW_HEIGHT;
	s_wind.width = 30;
	s_wind.height = 30;

	s_wind.active = 1;
	wind_hb = (HBITMAP)LoadImage(NULL, TEXT("res/BOSS/Wind2.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

}

AttackWind::AttackWind(int x, int y){
	SecureZeroMemory(&s_wind, sizeof(wind_info));
	s_wind.x = x;
	s_wind.y = y;
	s_wind.width = 90;
	s_wind.height = 120;

	s_wind.active = 1;
	wind_hb = (HBITMAP)LoadImage(NULL, TEXT("res/BOSS/Wind2.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

}


void AttackWind::Draw(HDC hdc){
	std::cout << s_wind.x << std::endl;
	std::cout << s_wind.y << std::endl;
	std::cout << std::endl;

	if (s_wind.active & 1){
		HDC hdc_work;
		hdc_work = CreateCompatibleDC(hdc);
		SelectObject(hdc_work, wind_hb);
		TransparentBlt(hdc, (int)s_wind.x, (int)s_wind.y, s_wind.width, s_wind.height, hdc_work, 0, 0, 90, 120, RGB(0, 0, 0));
		DeleteDC(hdc_work);
	}
	return;
}

void AttackWind::Scroll(int x, int y){
	s_wind.x += x;
	s_wind.y += y;
}

bool AttackWind::Update(){
	s_wind.dx = 15;
	s_wind.x -= s_wind.dx;
	if (s_wind.x < 0){
		return false;
	}
	return true;
}


int AttackWind::IsHit(){

	if (s_wind.active & 1 && s_wind.active>0){

		int ex = s_wind.x;
		int ey = s_wind.y;
		int ew = ex + s_wind.width;
		int eh = ey + s_wind.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			if (plstats->c_flg == 3 || plstats->c_flg == 2){
			}
			else{
				DEADflg = -1;
				plstats->x -= 15;
			}
		}

	}
	return 0;
}
