#include"scroll.h"


///// scroll関数///////////////////////////////////////////////////////
float Scroll::scroll_kansu(HDC hdc)

{
	BackMoveX = 0;
	BackMoveY = 0;

	int blMaxvol_x;
	int blMaxvol_y;


		if (stageNum == Stage2){
			blMaxvol_x = STAGE2_WIDTH * CHIP_SIZE - BLOCK_PAINT_X * CHIP_SIZE - 30;
			blMaxvol_y = STAGE2_HEIGHT * CHIP_SIZE - BLOCK_PAINT_Y * CHIP_SIZE - 90;

		}
		else{
			blMaxvol_x = MAP_WIDTH * CHIP_SIZE - BLOCK_PAINT_X * CHIP_SIZE - 30;
			blMaxvol_y = MAP_HEIGHT * CHIP_SIZE - BLOCK_PAINT_Y * CHIP_SIZE - 90;
		}
	


		if (plstats->x > 630){
			if (plstats->vx > 0){
				if (-(Backimg_x) >= blMaxvol_x){}
				else{
					plstats->x = 630;
					BackMoveX += (int)-plstats->vx;
				}
			}
		}

		//←　左側
		if (plstats->x < 300){
			if (plstats->vx < 0){
				if (Backimg_x >= 0){}
				else{
					plstats->x = 300;
					BackMoveX += (int)-plstats->vx;
				}

			}
		}
	

			if (plstats->y > 240){
				if (plstats->vy > 0){
					if (-(Backimg_y) >= blMaxvol_y){}
					else{
						plstats->y = 240;
						BackMoveY += (int)-plstats->vy;
					}
				}
			}


			if (plstats->y < 120){
				if (Backimg_y >= 0){}
				else{
					if (plstats->vy < 0){
						plstats->y = 120;
						BackMoveY += (int)-plstats->vy;
					}
				}
			}



	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(NULL);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_all);
	// 画面が最大移動量を超えないように調整
	if (Backimg_x - (-BackMoveX) > 0){
		Backimg_x = 0;
		BackMoveX = 0;
	}
	if (Backimg_y - (-BackMoveY)> 0){
		Backimg_y = 0;
		BackMoveY = 0;
	}
	
	if (-(Backimg_x)-BackMoveX > blMaxvol_x){
		Backimg_x = -(blMaxvol_x);
		BackMoveX = 0;
	}
	if (-(Backimg_y)-BackMoveY > blMaxvol_y){
		Backimg_y = -(blMaxvol_y);
		BackMoveY = 0;
	}


	Backimg_x += BackMoveX;
	Backimg_y += BackMoveY;

	BitBlt(hdc, (int)Backimg_x, (int)Backimg_y, MAP_WIDTH * CHIP_SIZE, MAP_HEIGHT * CHIP_SIZE, hdc_work, 0, 1000, SRCCOPY);

	/*DebugStringVal("A%d", MAP_HEIGHT * CHIP_SIZE, hdc, 100, 200, 20);
	DebugStringVal("A%d", MAP_HEIGHT * CHIP_SIZE - BLOCK_PAINT_Y * CHIP_SIZE-90, hdc, 100, 220, 20);
	DebugStringVal("%d", (int)-Backimg_x, hdc, 160, 200, 20);
	DebugStringVal("%d", (int)-Backimg_y, hdc, 160, 220, 20);*/

	// デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

void Scroll::toPoint(player_info *st){
	plstats = st;
}
