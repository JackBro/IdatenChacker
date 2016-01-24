#pragma once
#include"Player_Status.h"
#pragma comment(lib,"msimg32.lib")


void OIL::Item(int a)
{
	if (a == 1 || a == -1 || a == -2){
		Oil_Gage += a;
	}
	if (Oil_Gage > 5){
		Oil_Gage = 5;
	}
	if (Oil_Gage < 0){
		Oil_Gage = 0;
	}

}

/////ステータス管理////////
int OIL::Player_Sts()
{
	if (Oil_Gage == 0 || Oil_Gage == 1){
		c_sts = GARI;
		if (Oil_Gage == 0){
			gage = 0;
		}
		if (Oil_Gage == 1){
			gage = 1;
		}
		
	}
	if (Oil_Gage == 2){
		c_sts = TYOIYASE;
		gage = 2;
	}
	if (Oil_Gage == 3){
		c_sts = HUTHU;
		gage = 3;
	}
	if (Oil_Gage == 4){
		c_sts = POTYA;
		gage = 4;
	}
	if (Oil_Gage == 5){
		c_sts = DEBU;
		gage = 5;
	}
	return 0;
}

/////オイルのパワー管理/////////
int OIL::Oil_Sts()
{
	Power_w = 50;
	if (gage == 0){
		Power_w = Power_w * gage;
	}
	if (gage == 1){
		Power_w = Power_w * gage;
	}
	if (gage == 2){
		Power_w = Power_w * gage;
	}
	if (gage == 3){
		Power_w = Power_w * gage;
	}
	if (gage == 4){
		Power_w = Power_w * gage;
	}
	if (gage == 5){
		Power_w = Power_w * gage;
	}
	return 0;
}

/////ゲージ描画/////////
int OIL::Paint_Gage(HDC hdc)
{
	HDC hdc_work;
	hdc_work = CreateCompatibleDC(hdc);

	

	SelectObject(hdc_work, hb_OilGage);
	TransparentBlt(hdc, 10, 20, 254, 35, hdc_work, 0, 0, 254, 35, RGB(255, 255, 255));

	DeleteDC(hdc_work);
	return 0;
}


//////オイルパワーの描画////////////
int OIL::Paint_Oil(HDC hdc)
{
	HDC hdc_work;
	hdc_work = CreateCompatibleDC(hdc);

	SelectObject(hdc_work, hb_OilGageback);
	TransparentBlt(hdc, 10, 11, 320, 50, hdc_work, 0, 0, 320, 50, RGB(0, 0, 255));

	SelectObject(hdc_work, hb_OilPower);
	BitBlt(hdc, 10, 20, Power_w, 35, hdc_work, 0, 0, SRCCOPY);

	DeleteDC(hdc_work);
	return 0;
}

