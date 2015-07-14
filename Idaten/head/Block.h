#pragma once
#include<Windows.h>
#include"player_info.h"
#include "block_info.h"
#include<memory>
#include"debugmsg.h"
#include"Option.h"



/******それぞれのブロックの種類を定義してるブロッククラス*********
*もっと言えばその他ビットマップも全部ここで定義してしまっても動く*
*                                                                *
*         ある意味このclassはビットマップハンドル宣言クラス      *
*****************************************************************/

class Block{
	HDC blockhdc;
	//床とか壁に使うブロック
	BYTE key_buff[256];
	HBITMAP hb_block = (HBITMAP)LoadImage(NULL, TEXT("sozai01.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル
		//破壊できるブロック
	HBITMAP hc_block = (HBITMAP)LoadImage(NULL, TEXT("sozai02.bmp"), IMAGE_BITMAP,
	0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル
	     
	//ゴールテープ
	HBITMAP gorl = (HBITMAP)LoadImage(NULL, TEXT("Sikaku.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル
	//フラッグ（スタート地点）
	HBITMAP flag = (HBITMAP)LoadImage(NULL, TEXT("flag.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル

	char MAPDATA[MAP_HEIGHT][MAP_WIDTH];
	
	float MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
	float DrawMapChipX, DrawMapChipY;	// 描画するマップチップの数

public:
	int Hit_Check(HDC);
	int Init_block();

	block_info block;  //block_info型の構造体   :ブロック作成用オブジェクト


	Block(){
		Init_block();
		
	};

	int block_scroll(int, int);

	~Block(){
		DeleteObject(hb_block);
		DeleteObject(hc_block);
		DeleteObject(gorl);
	

	}
	player_info *plstats;
	float block_kansu(HDC);
	void CharMove();
	Block(BYTE * key){
		key_buff[0] = *key;
	}
	void toPoint(player_info *st);
	int BackMoveX, BackMoveY;		//スクロール

	//ブロック（ステージの座標を取得）
	int get_block_X();
	int get_block_Y();
	    
};


