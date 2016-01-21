#include <windows.h>
#include"player_info.h"
#include"debugmsg.h"
#include"Option.h"


class Scroll{

	HBITMAP hb_all;	// ビットマップハンドル
	int stageNum;
	int blMaxvol_x;
	int blMaxvol_y;
public:

	player_info *plstats;
//	player_info player;

	Scroll(){
	//	plstats = &player;
		BackMoveX = 0;
		BackMoveY = 0;
		Backimg_x = 0;
		Backimg_y = 0;
		stageNum = 0;
	};

	Scroll(int sNum){
		stageNum = sNum;
		if (sNum == Stage1) {
			Backimg_x = 0;
			Backimg_y = -(30 * CHIP_SIZE - 350);
			blMaxvol_x = MAP_WIDTH * CHIP_SIZE - BLOCK_PAINT_X * CHIP_SIZE - 30;
			blMaxvol_y = MAP_HEIGHT * CHIP_SIZE - BLOCK_PAINT_Y * CHIP_SIZE - 90;
			hb_all = (HBITMAP)LoadImage(NULL, TEXT("res/bgImage/背景.bmp"), IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		}
		else if (sNum == Stage2) {
			Backimg_x = 0;
			Backimg_y = -(48 * CHIP_SIZE - 350);
			blMaxvol_x = STAGE2_WIDTH * CHIP_SIZE - BLOCK_PAINT_X * CHIP_SIZE - 30;
			blMaxvol_y = STAGE2_HEIGHT * CHIP_SIZE - BLOCK_PAINT_Y * CHIP_SIZE;
			hb_all = (HBITMAP)LoadImage(NULL, TEXT("res/bgImage/背景2.bmp"), IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		}
		else if (sNum == Boss){
			Backimg_x = 0;
			Backimg_y = -(30 * CHIP_SIZE - 350);
			blMaxvol_x = MAP_WIDTH * CHIP_SIZE - BLOCK_PAINT_X * CHIP_SIZE - 30;
			blMaxvol_y = MAP_HEIGHT * CHIP_SIZE - BLOCK_PAINT_Y * CHIP_SIZE - 90;
			hb_all = (HBITMAP)LoadImage(NULL, TEXT("res/bgImage/sky.bmp"), IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		}

	}

	~Scroll(){
		DeleteObject(hb_all);
	}
	
	float scroll_kansu(HDC);

	void toPoint(player_info *st);
	int BackMoveX, BackMoveY;		//スクロール
	int Backimg_x, Backimg_y;


};





