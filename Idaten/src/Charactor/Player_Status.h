#pragma once
#include<Windows.h>
#pragma comment(lib,"msimg32.lib")


class OIL{
	
	//キャラ状態(体型)
#define DEBU     0
#define POTYA    1
#define HUTHU    2
#define TYOIYASE 3
#define GARI     4

	int Power_w;//オイルゲージのwidth
	int gage;//オイルゲージのwidthを変更するための値
	HBITMAP hb_OilGage = (HBITMAP)LoadImage(NULL, TEXT("res/Charactor/Oil.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_OilGageback = (HBITMAP)LoadImage(NULL, TEXT("res/Charactor/Oilgauge.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_OilPower = (HBITMAP)LoadImage(NULL, TEXT("res/Charactor/OilPower.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

public:
	
	int Paint_Gage(HDC);
	int Paint_Oil(HDC);
	int Player_Sts();
	int Oil_Sts();
	void Item(int);

	int Oil_Gage;//オイルゲージ管理
	int c_sts;//キャラステタース切り替え
	OIL(){
		c_sts = 2;
		Oil_Gage = 3;
	}
	~OIL(){
		DeleteObject(hb_OilGage);
		DeleteObject(hb_OilPower);
	}
};


