#pragma once
#include<Windows.h>
#pragma comment(lib,"msimg32.lib")


class OIL{
	
	//�L�������(�̌^)
#define DEBU     0
#define POTYA    1
#define HUTHU    2
#define TYOIYASE 3
#define GARI     4

	int Power_w;//�I�C���Q�[�W��width
	int gage;//�I�C���Q�[�W��width��ύX���邽�߂̒l
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

	int Oil_Gage;//�I�C���Q�[�W�Ǘ�
	int c_sts;//�L�����X�e�^�[�X�؂�ւ�
	OIL(){
		c_sts = 2;
		Oil_Gage = 3;
	}
	~OIL(){
		DeleteObject(hb_OilGage);
		DeleteObject(hb_OilPower);
	}
};


