#pragma once
#include <Windows.h>
#include"player_info.h"
#include"Player_Status.h"

#include"debugmsg.h"








class MOVE{
	
	//アニメーション用
#define A_WALK1_Right  0
#define A_WALK2_Right  1
#define A_WALK3_Right  2
#define A_WALK4_Right  3
#define A_WALK5_Right  4
#define A_WALK6_Right  5
#define A_WALK7_Right  6
#define A_WALK8_Right  7
#define A_WALK9_Right  8
#define A_WALK10_Right  9
#define A_WALK11_Right  10
#define A_WALK12_Right  11
#define A_WALK13_Right  12
#define A_WALK14_Right  13
#define A_WALK15_Right  14
#define A_WALK1_Left   15
#define A_WALK2_Left   16
#define A_WALK3_Left   17
#define A_WALK4_Left   18
#define A_WALK5_Left   19
#define A_WALK6_Left   20
#define A_WALK7_Left   21
#define A_WALK8_Left   22
#define A_WALK9_Left   23
#define A_WALK10_Left   24
#define A_WALK11_Left   25
#define A_WALK12_Left   26
#define A_WALK13_Left   27
#define A_WALK14_Left   28
#define A_WALK15_Left   29
#define A_JUMP         30
#define A_JUMP_Left     31
#define A_TACKLE        32
#define A_STAND1       33
#define A_STAND2       34
#define A_STAND3       35
#define A_STAND4       36
#define A_STAND5       37
#define A_STAND6       38
#define A_STAND7       39
#define A_STAND8       40
#define A_STAND9       41
#define A_STAND10      42

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
		player.x = 240;
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

