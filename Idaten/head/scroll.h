#include <windows.h>
#include"player_info.h"
#include"debugmsg.h"
#include"Option.h"


class Scroll{

	HBITMAP hb_all = (HBITMAP)LoadImage(NULL, TEXT("bg.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル
	int stageNum;
	
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
		BackMoveX = 0;
		BackMoveY = 0;
		Backimg_x = 0;
		Backimg_y = 0;

	}

	~Scroll(){
		DeleteObject(hb_all);
	}
	
	float scroll_kansu(HDC);

	void toPoint(player_info *st);
	int BackMoveX, BackMoveY;		//スクロール
	int Backimg_x, Backimg_y;


};





