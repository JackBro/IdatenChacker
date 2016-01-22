#pragma once
#include <Windows.h>
#include"player_info.h"
#include"Player_Status.h"

#include"../_Option/debugmsg.h"




class MOVE{
	
	//アニメーション用

#define A_WALK3_Right    0
#define A_WALK5_Right    1
#define A_WALK8_Right    2
#define A_WALK12_Right   3
#define A_WALK14_Right   4
#define A_WALK3_Left     6
#define A_WALK5_Left     7
#define A_WALK8_Left     8
#define A_WALK12_Left    9
#define A_WALK14_Left   10
#define A_JUMP          11
#define A_JUMP_Left     12
#define A_TACKLE        13
#define A_TACKLE_Left   14
#define A_STAND1        15
#define A_STAND1_Left    16


	int STAND = 0;
	int WALK = 1;
	int TACKLE = 2;
	int TACKLE_STOP = 3;
	int JUMP = 4;
	int JUMPDOWN = 5;


	int c_sts;
	int *Oil;
	int houkou; //0:左  1:右

	////体型別移動関数
	int Move_DEBU();
	int Move_POTYA();
	int Move_HUTHU();
	int Move_TYOIYASE();
	int Move_GARI();

public:
	int Move();//メイン移動関数
	void C_sts(int,int*);//c_sts,Oil_Gage
	int a_flg;//アニメーションフラグ
	int a_cnt = 0;//アニメーションカウント
	int a_cnt2 = 0;//立ちのアイドリング用カウント
	int x;	//タックルのフラグ(０：無効（OFF）１：有効（ON）
	int grv;  //重力

	player_info player;

	

	MOVE(){
		player.x = 250;
		player.y = 200;
		player.vy = 0;
		player.width = 30;
		player.height = 60;
		player.attack_x = 30;
		player.attack_mukou = 90;

		//以下状態
		player.c_flg = STAND;
	
		//キャラクターアニメーション
		a_flg = A_STAND1;
		a_cnt = 0;
		a_cnt2 = 0;
		//タックルのフラグ
		x = 0;
		grv = 1.1;
	}

};

