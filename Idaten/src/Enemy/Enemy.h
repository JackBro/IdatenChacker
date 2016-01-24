#pragma once


#include <windows.h>
#include <math.h>	
#include <time.h>   

#include"../Charactor/player_info.h"

//#include"../debugmsg.h"
#include"../_Option/Option.h"

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")



/*
敵の親のクラス。
構造体の宣言や、派生するのに必要な宣言が書いてある。



ここで取り扱うメソッド


*/

class Enemy{
protected:

	int DEADflg = 0;	//敵とキャラクターが接触した場合に真（-１）ゲージを直接いじるので－１
	int Jump = 0;		//ここでのみ使用する

	int enemyID;		//敵の番号
	

	//敵のデバイスコンテキストハンドル
	HDC enemyhdc;

	//敵のBitmapハンドル
	HBITMAP enemy_hb;
	HBITMAP bullet_hb;

	player_info *plstats;

							//キャラのステータスを一部分保存しておく構造体
							//敵のステータスの構造体

	struct bullet_info{
		float x, y;
		float dx, dy;
		int width, height;
		int onActive;
	}enemy_bullet;				//敵が使う弾の構造体。

	struct enemy_info {
		float x, y;
		float dx, dy;
		float rad_x, rad_y;
		int step_x, step_y;
		int width, height;
		int onActive;
		int base_y;
		int	anim_count, timecnt, actioncnt;
		int MAX_Tcnt;
		int anim_flg;
	}enemy;
	HBITMAP *enemy_hbList;
public :

	


	//共有メソッド
	int Enemy_paint(HDC enemy_hdc);
	int enemyPaintBullet();
	int chara_strc(player_info *tp);	//マネージャからキャラのステータスを格納する

	int hit_enemycheck();		//敵との当たり判定
	int hit_enemycheckN();		//敵との当たり判定だが敵を消去しない。
	int hit_enemycheckRide();		//敵との当たり判定だが敵の上に乗れる。


	int get_deadflg(){ return DEADflg;	}
	int get_onActive(){ return enemy.onActive; }
	
	int enemy_scroll(int, int);
	int bullet_scroll(int, int);

	void EnemyID(int a) { enemyID = a; }
	int EnemyID() { return enemyID; }

	float Enemy_x();
	float Enemy_y();

	//派生するメソッド 中身は空でいい
	virtual int init(){ return 0; }
	virtual int move_enemy(){ return 0; }


//デストラクタは仮想
	Enemy();
	virtual ~Enemy(){
	};
};

