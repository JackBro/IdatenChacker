#pragma once
#include"Player_Move.h"




/////移動関数//////////////
int MOVE::Move()
{
	switch (c_sts)//キャラのステータスでそれぞれの体型の移動を管理
	{
	case DEBU:

		Move_DEBU();
		break;

	case POTYA:

		Move_POTYA();
		break;

	case HUTHU:

		Move_HUTHU();
		break;

	case TYOIYASE:

		Move_TYOIYASE();
		break;

	case GARI:

		Move_GARI();
		break;
	}

	return 0;
}

/////体型別移動//////////////
int MOVE::Move_DEBU()
{
	player.vy += grv;//重力を与える
	player.vx *= 0.8;
	/******立ち********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******タックルへ*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
		}
	}
	/*****************************************/

	/******歩き********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -6;
		a_flg = A_WALK13_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 6;
		a_flg = A_WALK13_Right;
		a_cnt++;
		houkou = 1;
	}

	//右のアニメーション

	if (a_flg == A_WALK13_Right && a_cnt >= 7){
		a_flg = A_WALK14_Right;
	}
	if (a_flg == A_WALK14_Right && a_cnt >= 9){
		a_flg = A_WALK1_Right;
	}
	if (a_flg == A_WALK1_Right && a_cnt >= 11){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 13){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 15){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 17){
		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 19){
		a_flg = A_WALK6_Right;
	}
	if (a_flg == A_WALK6_Right && a_cnt >= 21){
		a_flg = A_WALK7_Right;
	}
	if (a_flg == A_WALK7_Right && a_cnt >= 23){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 25){
		a_flg = A_WALK9_Right;
	}
	if (a_flg == A_WALK9_Right && a_cnt >= 27){
		a_flg = A_WALK10_Right;
	}
	if (a_flg == A_WALK10_Right && a_cnt >= 29){
		a_flg = A_WALK11_Right;
	}
	if (a_flg == A_WALK11_Right && a_cnt >= 31){
		a_flg = A_WALK12_Right;
		a_cnt = 0;
	}



	//左のアニメーション
	if (a_flg == A_WALK13_Left && a_cnt >= 7){
		a_flg = A_WALK14_Left;
	}
	if (a_flg == A_WALK14_Left && a_cnt >= 9){
		a_flg = A_WALK1_Left;
	}
	if (a_flg == A_WALK1_Left && a_cnt >= 11){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 13){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 15){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 17){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 19){
		a_flg = A_WALK6_Left;
	}
	if (a_flg == A_WALK6_Left && a_cnt >= 21){
		a_flg = A_WALK7_Left;
	}
	if (a_flg == A_WALK7_Left && a_cnt >= 23){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 25){
		a_flg = A_WALK9_Left;
	}
	if (a_flg == A_WALK9_Left && a_cnt >= 27){
		a_flg = A_WALK10_Left;
	}
	if (a_flg == A_WALK10_Left && a_cnt >= 29){
		a_flg = A_WALK11_Left;
	}
	if (a_flg == A_WALK11_Left && a_cnt >= 31){
		a_flg = A_WALK12_Left;
		a_cnt = 0;
	}

	//a_flgをA_STANDに戻す処理

	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK5_Right || a_flg == A_WALK6_Right || a_flg == A_WALK7_Right || a_flg == A_WALK8_Right ||
		a_flg == A_WALK9_Right || a_flg == A_WALK10_Right || a_flg == A_WALK11_Right || a_flg == A_WALK12_Right || a_flg == A_WALK13_Right || a_flg == A_WALK14_Right || a_flg == A_WALK15_Right ||
		a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left || a_flg == A_WALK5_Left || a_flg == A_WALK6_Left || a_flg == A_WALK7_Left || a_flg == A_WALK8_Left ||
		a_flg == A_WALK9_Left || a_flg == A_WALK10_Left || a_flg == A_WALK11_Left || a_flg == A_WALK12_Left || a_flg == A_WALK13_Left || a_flg == A_WALK14_Left || a_flg == A_WALK15_Left || a_flg == A_JUMP || a_flg == A_JUMP_Left || a_flg == A_TACKLE){
		if (player.vx <= 1 && player.vx >= -1){
			a_flg = A_STAND1;

		}
	}
	/*****************************************/

	/******ジャンプ(離陸)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 12;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******ジャンプ(空中)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -6;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 6;
			houkou = 1;
		}
		else{
			houkou = 2;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		if (houkou == 2){
			a_flg = A_JUMP;
		}
	}
	/*****************************************/

	/******タックル***************************/
	if (x == 1){      //Xキーが押されたら
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //値のセット	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}
	/*****タックルの終了*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
		player.attack_mukou -= 3;//次のXキーの入力待ち時間
		player.attack_x -= 5;	//タックルの減速値

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//Xキーの再入力が可能
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}
		a_flg = A_TACKLE;
	}
	/****************************************/

	//横移動時A_STANDの描画を消す
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK5_Right && a_flg != A_WALK6_Right && a_flg != A_WALK7_Right && a_flg != A_WALK8_Right &&
		a_flg != A_WALK9_Right && a_flg != A_WALK10_Right && a_flg != A_WALK11_Right && a_flg != A_WALK12_Right && a_flg != A_WALK13_Right && a_flg != A_WALK14_Right && a_flg != A_WALK15_Right &&
		a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_WALK5_Left && a_flg != A_WALK6_Left && a_flg != A_WALK7_Left && a_flg != A_WALK8_Left &&
		a_flg != A_WALK9_Left && a_flg != A_WALK10_Left && a_flg != A_WALK11_Left && a_flg != A_WALK12_Left && a_flg != A_WALK13_Left && a_flg != A_WALK14_Left && a_flg != A_WALK15_Left && a_flg != A_TACKLE && a_flg != A_JUMP && a_flg != A_JUMP_Left){
		a_cnt2 = 0;
	}
	return 0;
}

int MOVE::Move_POTYA()
{
	player.vy += grv;//重力を与える
	player.vx *= 0.8;
	/******立ち********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******タックルへ*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
		}
	}
	/*****************************************/

	/******歩き********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -8;
		a_flg = A_WALK13_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 8;
		a_flg = A_WALK13_Right;
		a_cnt++;
		houkou = 1;
	}

	//右のアニメーション

	if (a_flg == A_WALK13_Right && a_cnt >= 7){
		a_flg = A_WALK14_Right;
	}
	if (a_flg == A_WALK14_Right && a_cnt >= 9){
		a_flg = A_WALK1_Right;
	}
	if (a_flg == A_WALK1_Right && a_cnt >= 11){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 13){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 15){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 17){
		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 19){
		a_flg = A_WALK6_Right;
	}
	if (a_flg == A_WALK6_Right && a_cnt >= 21){
		a_flg = A_WALK7_Right;
	}
	if (a_flg == A_WALK7_Right && a_cnt >= 23){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 25){
		a_flg = A_WALK9_Right;
	}
	if (a_flg == A_WALK9_Right && a_cnt >= 27){
		a_flg = A_WALK10_Right;
	}
	if (a_flg == A_WALK10_Right && a_cnt >= 29){
		a_flg = A_WALK11_Right;
	}
	if (a_flg == A_WALK11_Right && a_cnt >= 31){
		a_flg = A_WALK12_Right;
		a_cnt = 0;
	}



	//左のアニメーション
	if (a_flg == A_WALK13_Left && a_cnt >= 7){
		a_flg = A_WALK14_Left;
	}
	if (a_flg == A_WALK14_Left && a_cnt >= 9){
		a_flg = A_WALK1_Left;
	}
	if (a_flg == A_WALK1_Left && a_cnt >= 11){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 13){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 15){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 17){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 19){
		a_flg = A_WALK6_Left;
	}
	if (a_flg == A_WALK6_Left && a_cnt >= 21){
		a_flg = A_WALK7_Left;
	}
	if (a_flg == A_WALK7_Left && a_cnt >= 23){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 25){
		a_flg = A_WALK9_Left;
	}
	if (a_flg == A_WALK9_Left && a_cnt >= 27){
		a_flg = A_WALK10_Left;
	}
	if (a_flg == A_WALK10_Left && a_cnt >= 29){
		a_flg = A_WALK11_Left;
	}
	if (a_flg == A_WALK11_Left && a_cnt >= 31){
		a_flg = A_WALK12_Left;
		a_cnt = 0;
	}

	//a_flgをA_STANDに戻す処理

	//a_flgをA_STANDに戻す処理
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK5_Right || a_flg == A_WALK6_Right || a_flg == A_WALK7_Right || a_flg == A_WALK8_Right ||
		a_flg == A_WALK9_Right || a_flg == A_WALK10_Right || a_flg == A_WALK11_Right || a_flg == A_WALK12_Right || a_flg == A_WALK13_Right || a_flg == A_WALK14_Right || a_flg == A_WALK15_Right ||
		a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left || a_flg == A_WALK5_Left || a_flg == A_WALK6_Left || a_flg == A_WALK7_Left || a_flg == A_WALK8_Left ||
		a_flg == A_WALK9_Left || a_flg == A_WALK10_Left || a_flg == A_WALK11_Left || a_flg == A_WALK12_Left || a_flg == A_WALK13_Left || a_flg == A_WALK14_Left || a_flg == A_WALK15_Left || a_flg == A_JUMP || a_flg == A_JUMP_Left || a_flg == A_TACKLE){
		if (player.vx <= 1 && player.vx >= -1){
			a_flg = A_STAND1;

		}
	}
	/*****************************************/

	/******ジャンプ(離陸)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 14;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******ジャンプ(空中)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -8;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 8;
			houkou = 1;
		}
		else{
			houkou = 2;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		if (houkou == 2){
			a_flg = A_JUMP;
		}
	}
	/*****************************************/

	/******タックル***************************/
	if (x == 1){      //Xキーが押されたら
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //値のセット	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}
	/*****タックルの終了*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
		player.attack_mukou -= 5;//次のXキーの入力待ち時間
		player.attack_x -= 5;	//タックルの減速値

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//Xキーの再入力が可能
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}


		a_flg = A_TACKLE;
	}
	/****************************************/


	//横移動時A_STANDの描画を消す
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK5_Right && a_flg != A_WALK6_Right && a_flg != A_WALK7_Right && a_flg != A_WALK8_Right &&
		a_flg != A_WALK9_Right && a_flg != A_WALK10_Right && a_flg != A_WALK11_Right && a_flg != A_WALK12_Right && a_flg != A_WALK13_Right && a_flg != A_WALK14_Right && a_flg != A_WALK15_Right &&
		a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_WALK5_Left && a_flg != A_WALK6_Left && a_flg != A_WALK7_Left && a_flg != A_WALK8_Left &&
		a_flg != A_WALK9_Left && a_flg != A_WALK10_Left && a_flg != A_WALK11_Left && a_flg != A_WALK12_Left && a_flg != A_WALK13_Left && a_flg != A_WALK14_Left && a_flg != A_WALK15_Left && a_flg != A_TACKLE && a_flg != A_JUMP && a_flg != A_JUMP_Left){
		a_cnt2 = 0;
	}

	return 0;
}

int MOVE::Move_HUTHU()
{
	player.vy += grv;//重力を与える
	player.vx *= 0.8;
	/******立ち********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******タックルへ*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
		}
	}
	/*****************************************/

	/******歩き********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -10;
		a_flg = A_WALK13_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 10;
		a_flg = A_WALK13_Right;
		a_cnt++;
		houkou = 1;
	}

	//右のアニメーション

	if (a_flg == A_WALK13_Right && a_cnt >= 7){
		a_flg = A_WALK14_Right;
	}
	if (a_flg == A_WALK14_Right && a_cnt >= 9){
		a_flg = A_WALK1_Right;
	}
	if (a_flg == A_WALK1_Right && a_cnt >= 11){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 13){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 15){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 17){
		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 19){
		a_flg = A_WALK6_Right;
	}
	if (a_flg == A_WALK6_Right && a_cnt >= 21){
		a_flg = A_WALK7_Right;
	}
	if (a_flg == A_WALK7_Right && a_cnt >= 23){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 25){
		a_flg = A_WALK9_Right;
	}
	if (a_flg == A_WALK9_Right && a_cnt >= 27){
		a_flg = A_WALK10_Right;
	}
	if (a_flg == A_WALK10_Right && a_cnt >= 29){
		a_flg = A_WALK11_Right;
	}
	if (a_flg == A_WALK11_Right && a_cnt >= 31){
		a_flg = A_WALK12_Right;
		a_cnt = 0;
	}



	//左のアニメーション
	if (a_flg == A_WALK13_Left && a_cnt >= 7){
		a_flg = A_WALK14_Left;
	}
	if (a_flg == A_WALK14_Left && a_cnt >= 9){
		a_flg = A_WALK1_Left;
	}
	if (a_flg == A_WALK1_Left && a_cnt >= 11){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 13){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 15){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 17){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 19){
		a_flg = A_WALK6_Left;
	}
	if (a_flg == A_WALK6_Left && a_cnt >= 21){
		a_flg = A_WALK7_Left;
	}
	if (a_flg == A_WALK7_Left && a_cnt >= 23){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 25){
		a_flg = A_WALK9_Left;
	}
	if (a_flg == A_WALK9_Left && a_cnt >= 27){
		a_flg = A_WALK10_Left;
	}
	if (a_flg == A_WALK10_Left && a_cnt >= 29){
		a_flg = A_WALK11_Left;
	}
	if (a_flg == A_WALK11_Left && a_cnt >= 31){
		a_flg = A_WALK12_Left;
		a_cnt = 0;
	}


	//a_flgをA_STANDに戻す処理
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK5_Right || a_flg == A_WALK6_Right || a_flg == A_WALK7_Right || a_flg == A_WALK8_Right ||
		a_flg == A_WALK9_Right || a_flg == A_WALK10_Right || a_flg == A_WALK11_Right || a_flg == A_WALK12_Right || a_flg == A_WALK13_Right || a_flg == A_WALK14_Right || a_flg == A_WALK15_Right ||
		a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left || a_flg == A_WALK5_Left || a_flg == A_WALK6_Left || a_flg == A_WALK7_Left || a_flg == A_WALK8_Left ||
		a_flg == A_WALK9_Left || a_flg == A_WALK10_Left || a_flg == A_WALK11_Left || a_flg == A_WALK12_Left || a_flg == A_WALK13_Left || a_flg == A_WALK14_Left || a_flg == A_WALK15_Left || a_flg == A_JUMP || a_flg == A_JUMP_Left || a_flg == A_TACKLE){
		if (player.vx <= 1 && player.vx >= -1){
			a_flg = A_STAND1;

		}
	}


	//}
	/*****************************************/

	/******ジャンプ(離陸)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 16;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******ジャンプ(空中)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -10;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 10;
			houkou = 1;
		}
		else{
			houkou = 2;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		if (houkou == 2){
			a_flg = A_JUMP;
		}
	}
	/*****************************************/

	/******タックル***************************/
	if (x == 1){      //Xキーが押されたら
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //値のセット	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}
	/*****タックルの終了*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
		player.attack_mukou -= 5;//次のXキーの入力待ち時間
		player.attack_x -= 5;	//タックルの減速値

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//Xキーの再入力が可能
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}


		a_flg = A_TACKLE;
	}
	/****************************************/


	//マップのブロックの上辺に接触したら

	//横移動時A_STANDの描画を消す
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK5_Right && a_flg != A_WALK6_Right && a_flg != A_WALK7_Right && a_flg != A_WALK8_Right &&
		a_flg != A_WALK9_Right && a_flg != A_WALK10_Right && a_flg != A_WALK11_Right && a_flg != A_WALK12_Right && a_flg != A_WALK13_Right && a_flg != A_WALK14_Right && a_flg != A_WALK15_Right &&
		a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_WALK5_Left && a_flg != A_WALK6_Left && a_flg != A_WALK7_Left && a_flg != A_WALK8_Left &&
		a_flg != A_WALK9_Left && a_flg != A_WALK10_Left && a_flg != A_WALK11_Left && a_flg != A_WALK12_Left && a_flg != A_WALK13_Left && a_flg != A_WALK14_Left && a_flg != A_WALK15_Left && a_flg != A_TACKLE && a_flg != A_JUMP && a_flg != A_JUMP_Left){
		a_cnt2 = 0;
	}

	return 0;
}

int MOVE::Move_TYOIYASE()
{
	player.vy += grv;//重力を与える
	player.vx *= 0.8;
	/******立ち********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******タックルへ*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
		}
	}
	/*****************************************/

	/******歩き********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -12;
		a_flg = A_WALK13_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 12;
		a_flg = A_WALK13_Right;
		a_cnt++;
		houkou = 1;
	}

	//右のアニメーション

	if (a_flg == A_WALK13_Right && a_cnt >= 7){
		a_flg = A_WALK14_Right;
	}
	if (a_flg == A_WALK14_Right && a_cnt >= 9){
		a_flg = A_WALK1_Right;
	}
	if (a_flg == A_WALK1_Right && a_cnt >= 11){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 13){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 15){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 17){
		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 19){
		a_flg = A_WALK6_Right;
	}
	if (a_flg == A_WALK6_Right && a_cnt >= 21){
		a_flg = A_WALK7_Right;
	}
	if (a_flg == A_WALK7_Right && a_cnt >= 23){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 25){
		a_flg = A_WALK9_Right;
	}
	if (a_flg == A_WALK9_Right && a_cnt >= 27){
		a_flg = A_WALK10_Right;
	}
	if (a_flg == A_WALK10_Right && a_cnt >= 29){
		a_flg = A_WALK11_Right;
	}
	if (a_flg == A_WALK11_Right && a_cnt >= 31){
		a_flg = A_WALK12_Right;
		a_cnt = 0;
	}



	//左のアニメーション
	if (a_flg == A_WALK13_Left && a_cnt >= 7){
		a_flg = A_WALK14_Left;
	}
	if (a_flg == A_WALK14_Left && a_cnt >= 9){
		a_flg = A_WALK1_Left;
	}
	if (a_flg == A_WALK1_Left && a_cnt >= 11){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 13){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 15){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 17){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 19){
		a_flg = A_WALK6_Left;
	}
	if (a_flg == A_WALK6_Left && a_cnt >= 21){
		a_flg = A_WALK7_Left;
	}
	if (a_flg == A_WALK7_Left && a_cnt >= 23){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 25){
		a_flg = A_WALK9_Left;
	}
	if (a_flg == A_WALK9_Left && a_cnt >= 27){
		a_flg = A_WALK10_Left;
	}
	if (a_flg == A_WALK10_Left && a_cnt >= 29){
		a_flg = A_WALK11_Left;
	}
	if (a_flg == A_WALK11_Left && a_cnt >= 31){
		a_flg = A_WALK12_Left;
		a_cnt = 0;
	}

	//a_flgをA_STANDに戻す処理

	//a_flgをA_STANDに戻す処理
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK5_Right || a_flg == A_WALK6_Right || a_flg == A_WALK7_Right || a_flg == A_WALK8_Right ||
		a_flg == A_WALK9_Right || a_flg == A_WALK10_Right || a_flg == A_WALK11_Right || a_flg == A_WALK12_Right || a_flg == A_WALK13_Right || a_flg == A_WALK14_Right || a_flg == A_WALK15_Right ||
		a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left || a_flg == A_WALK5_Left || a_flg == A_WALK6_Left || a_flg == A_WALK7_Left || a_flg == A_WALK8_Left ||
		a_flg == A_WALK9_Left || a_flg == A_WALK10_Left || a_flg == A_WALK11_Left || a_flg == A_WALK12_Left || a_flg == A_WALK13_Left || a_flg == A_WALK14_Left || a_flg == A_WALK15_Left || a_flg == A_JUMP || a_flg == A_JUMP_Left || a_flg == A_TACKLE){
		if (player.vx <= 1 && player.vx >= -1){
			a_flg = A_STAND1;

		}
	}
	/*****************************************/

	/******ジャンプ(離陸)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 18;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******ジャンプ(空中)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;

		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -12;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 12;
			houkou = 1;
		}
		else{
			houkou = 2;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		if (houkou == 2){
			a_flg = A_JUMP;
		}
	}
	/*****************************************/

	/******タックル***************************/
	if (x == 1){      //Xキーが押されたら
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //値のセット	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}
	/*****タックルの終了*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
		player.attack_mukou -= 5;//次のXキーの入力待ち時間
		player.attack_x -= 5;	//タックルの減速値

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//Xキーの再入力が可能
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}


		a_flg = A_TACKLE;
	}
	/****************************************/


	//マップのブロックの上辺に接触したら

	//横移動時A_STANDの描画を消す
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK5_Right && a_flg != A_WALK6_Right && a_flg != A_WALK7_Right && a_flg != A_WALK8_Right &&
		a_flg != A_WALK9_Right && a_flg != A_WALK10_Right && a_flg != A_WALK11_Right && a_flg != A_WALK12_Right && a_flg != A_WALK13_Right && a_flg != A_WALK14_Right && a_flg != A_WALK15_Right &&
		a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_WALK5_Left && a_flg != A_WALK6_Left && a_flg != A_WALK7_Left && a_flg != A_WALK8_Left &&
		a_flg != A_WALK9_Left && a_flg != A_WALK10_Left && a_flg != A_WALK11_Left && a_flg != A_WALK12_Left && a_flg != A_WALK13_Left && a_flg != A_WALK14_Left && a_flg != A_WALK15_Left && a_flg != A_TACKLE && a_flg != A_JUMP && a_flg != A_JUMP_Left){
		a_cnt2 = 0;
	}

	return 0;
}

int MOVE::Move_GARI()
{
	player.vy += grv;//重力を与える
	player.vx *= 0.8;

	/******立ち********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******タックルへ*************************/
	if (x != 1 && *Oil != 0){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
		}
	}
	/*****************************************/

	/******歩き********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -14;
		a_flg = A_WALK13_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 14;
		a_flg = A_WALK13_Right;
		a_cnt++;
		houkou = 1;
	}

	//右のアニメーション

	if (a_flg == A_WALK13_Right && a_cnt >= 7){
		a_flg = A_WALK14_Right;
	}
	if (a_flg == A_WALK14_Right && a_cnt >= 9){
		a_flg = A_WALK1_Right;
	}
	if (a_flg == A_WALK1_Right && a_cnt >= 11){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 13){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 15){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 17){
		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 19){
		a_flg = A_WALK6_Right;
	}
	if (a_flg == A_WALK6_Right && a_cnt >= 21){
		a_flg = A_WALK7_Right;
	}
	if (a_flg == A_WALK7_Right && a_cnt >= 23){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 25){
		a_flg = A_WALK9_Right;
	}
	if (a_flg == A_WALK9_Right && a_cnt >= 27){
		a_flg = A_WALK10_Right;
	}
	if (a_flg == A_WALK10_Right && a_cnt >= 29){
		a_flg = A_WALK11_Right;
	}
	if (a_flg == A_WALK11_Right && a_cnt >= 31){
		a_flg = A_WALK12_Right;
		a_cnt = 0;
	}



	//左のアニメーション
	if (a_flg == A_WALK13_Left && a_cnt >= 7){
		a_flg = A_WALK14_Left;
	}
	if (a_flg == A_WALK14_Left && a_cnt >= 9){
		a_flg = A_WALK1_Left;
	}
	if (a_flg == A_WALK1_Left && a_cnt >= 11){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 13){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 15){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 17){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 19){
		a_flg = A_WALK6_Left;
	}
	if (a_flg == A_WALK6_Left && a_cnt >= 21){
		a_flg = A_WALK7_Left;
	}
	if (a_flg == A_WALK7_Left && a_cnt >= 23){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 25){
		a_flg = A_WALK9_Left;
	}
	if (a_flg == A_WALK9_Left && a_cnt >= 27){
		a_flg = A_WALK10_Left;
	}
	if (a_flg == A_WALK10_Left && a_cnt >= 29){
		a_flg = A_WALK11_Left;
	}
	if (a_flg == A_WALK11_Left && a_cnt >= 31){
		a_flg = A_WALK12_Left;
		a_cnt = 0;
	}


	//a_flgをA_STANDに戻す処理
	//a_flgをA_STANDに戻す処理
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK5_Right || a_flg == A_WALK6_Right || a_flg == A_WALK7_Right || a_flg == A_WALK8_Right ||
		a_flg == A_WALK9_Right || a_flg == A_WALK10_Right || a_flg == A_WALK11_Right || a_flg == A_WALK12_Right || a_flg == A_WALK13_Right || a_flg == A_WALK14_Right || a_flg == A_WALK15_Right ||
		a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left || a_flg == A_WALK5_Left || a_flg == A_WALK6_Left || a_flg == A_WALK7_Left || a_flg == A_WALK8_Left ||
		a_flg == A_WALK9_Left || a_flg == A_WALK10_Left || a_flg == A_WALK11_Left || a_flg == A_WALK12_Left || a_flg == A_WALK13_Left || a_flg == A_WALK14_Left || a_flg == A_WALK15_Left || a_flg == A_JUMP || a_flg == A_JUMP_Left || a_flg == A_TACKLE){
		if (player.vx <= 1 && player.vx >= -1){
			a_flg = A_STAND1;

		}
	}

	/*****************************************/

	/******ジャンプ(離陸)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 22;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******ジャンプ(空中)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -14;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 14;
			houkou = 1;
		}
		else{
			houkou = 2;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		if (houkou == 2){
			a_flg = A_JUMP;
		}
	}
	/*****************************************/

	/******タックル***************************/
	if (x == 1){      //Xキーが押されたら
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //値のセット	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}
	/*****タックルの終了*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
		player.attack_mukou -= 5;//次のXキーの入力待ち時間
		player.attack_x -= 5;	//タックルの減速値

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//Xキーの再入力が可能
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}


		a_flg = A_TACKLE;
	}
	if (*Oil < 0){  //オイルゲージが0の時はタックルは不可
		*Oil = 0;
		player.attack_x = 0;
	}
	/****************************************/


	//マップのブロックの上辺に接触したら

	//横移動時A_STANDの描画を消す
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK5_Right && a_flg != A_WALK6_Right && a_flg != A_WALK7_Right && a_flg != A_WALK8_Right &&
		a_flg != A_WALK9_Right && a_flg != A_WALK10_Right && a_flg != A_WALK11_Right && a_flg != A_WALK12_Right && a_flg != A_WALK13_Right && a_flg != A_WALK14_Right && a_flg != A_WALK15_Right &&
		a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_WALK5_Left && a_flg != A_WALK6_Left && a_flg != A_WALK7_Left && a_flg != A_WALK8_Left &&
		a_flg != A_WALK9_Left && a_flg != A_WALK10_Left && a_flg != A_WALK11_Left && a_flg != A_WALK12_Left && a_flg != A_WALK13_Left && a_flg != A_WALK14_Left && a_flg != A_WALK15_Left && a_flg != A_TACKLE && a_flg != A_JUMP && a_flg != A_JUMP_Left){
		a_cnt2 = 0;
	}

	return 0;
}


void MOVE::C_sts(int a, int *b){
	c_sts = a;
	Oil = b;
}