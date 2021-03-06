#pragma once
#include<Windows.h>
#include"../Charactor/player_info.h"
#include "../Block/block_info.h"
#include<memory>
#include"../_Option/debugmsg.h"
#include"../_Option/Option.h"
#include<vector>



/******それぞれのブロックの種類を定義してるブロッククラス*********
*もっと言えばその他ビットマップも全部ここで定義してしまっても動く*
*                                                                *
*         ある意味このclassはビットマップハンドル宣言クラス      *
*****************************************************************/

class Block{
	HDC blockhdc;
	//床とか壁に使うブロック
	BYTE key_buff[256];
	HBITMAP hb_block = (HBITMAP)LoadImage(NULL, TEXT("res/Block/normal.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル
		//破壊できるブロック
	HBITMAP hc_block = (HBITMAP)LoadImage(NULL, TEXT("res/Block/breaker.bmp"), IMAGE_BITMAP,
	0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル
	     
	//ゴールテープ
	HBITMAP gorl = (HBITMAP)LoadImage(NULL, TEXT("res/Block/Sikaku.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル
	//フラッグ（スタート地点）
	HBITMAP flag = (HBITMAP)LoadImage(NULL, TEXT("res/Block/flag.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ビットマップハンドル

	//char MAPDATA[MAP_HEIGHT][MAP_WIDTH];
	//char MAPDATA2[STAGE2_HEIGHT][STAGE2_WIDTH];

	std::vector<std::vector<char>>MAPDATA;
	
	float MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
	float DrawMapChipX, DrawMapChipY;	// 描画するマップチップの数

public:
	int Hit_Check(HDC);
	int Init_block();

	block_info block;  //block_info型の構造体   :ブロック作成用オブジェクト


	Block(){
		Init_block();
		
	};
	Block(int n){
		s1 = n;
		Init_block();
	}
	int block_scroll(int, int);

	~Block(){
		DeleteObject(hb_block);
		DeleteObject(hc_block);
		DeleteObject(gorl);
	

	}
	player_info *plstats;
	float block_kansu(HDC);
	void CharMove();
	int s1;
	Block(BYTE * key){
		key_buff[0] = *key;
	}
	void toPoint(player_info *st);
	int BackMoveX, BackMoveY;		//スクロール

	//ブロック（ステージの座標を取得）
	int get_block_X();
	int get_block_Y();

	    
};


