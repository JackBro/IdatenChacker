#pragma once
typedef struct{
	
	float x, y;				// 位置
	float step_x, step_y;	// 移動量
	float jump_power;
	int   width, height;	// 幅、高さ

	//キャラの攻撃（タックルに関する値）					＊NEW
	int vx, vy;
	int attack_mukou;
	int attack_x, attack_y;

	//キャラのフラグ
	//０立ち	１歩き	　2タックル　3タックルストップ 4ジャンプ　5落下？
	int c_flg;              
	

	//
	bool jump;
	bool Tackle;
	//
}player_info;