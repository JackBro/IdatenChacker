#pragma once

#include<Windows.h>
#include<memory>
#include<vector>
#include<thread>

#include"Enemy.h"//スーパークラス

//以下サブ
#include"Enemy01.h"
#include"Enemy02.h"
#include"Enemy03.h"
#include"Enemy04.h"
#include"Enemy05.h"
#include"Enemy06.h"
#include"Enemy07.h"


//キャラのクラス（仮	値をどう受け取るかはまだ不明なので（仮）
#include"../Charactor/player_info.h"
#include"../_Option/Option.h"
//debug用
#include"../_Option/debugmsg.h"




/*
このクラスでは主に

敵の生成。
現在のマップ番号
出現座標の指定

スクロール値の受け渡し（敵クラスへ）
敵クラスからキャラと接触したという判定を得る。

などを管理,取得する
*///他に必要なことがあれば順次追加


/*		//導入する場合は　下の様にやっておくと動くよ
/Enemy
//-----------------------------
eobj->chara_strc(player);
eobj->enemy_scroll(obj1.BackMoveX, obj1.BackMoveY);
eobj->stage_coord(obj2.get_block_X(), obj2.get_block_Y());
eobj->MainLoop(hdc);
*/




class EnemyManager
{



private:
	const int TYPE_MAX = 7;	//敵のタイプの最大数

	HDC enemyhdc;	//デバイスコンテキストハンドル(Mainloopによりその都度更新される)

	player_info *plstats;	//敵に渡すキャラのデータ(Main->EnemyManager->Enemy)

	int scroll_x, scroll_y;		//スクロール量を敵の座標に反映させる
	int maps_x, maps_y;			//ステージの座標を格納しておく。　スクロールによって可変される座標値を取るため
	int MaxEnemy;				//敵の最大数
	int deadflg;				//キャラクターが死亡したという情報をもつ。（関数でI/Oする）


	//出現座標格納用配列
	int spawnpoint[2];
	std::vector<std::vector<int>>Stage_Spawnpoint;			//ステージ上の出現座標を格納しておく
	
	int stageID;											//コンストラクタからステージの番号を取得する

	int SpawnEnemy();		//敵の生成
	int GetSpawnPoint(int);	//敵の出現ポイントを指定する。
	void SetSpawnPoint();	//敵の出現ポイントを初期化しておく。

	const int SpawnInterval = ENEMY_SPAWN_INTERVAL;		//リスポーンするまでのインターバル

	std::vector<int>SpawnList;							//どこの敵を次に出現させるかを入れておくオーダーリスト

public:

	std::vector<std::unique_ptr<Enemy>>eobj;
//std::unique_ptr<Enemy>*eobj;

int chara_strc(player_info *tp);	//マネージャからキャラのステータスを格納する

int enemy_scroll(int, int);		//敵がスクロールに対応するため値を渡す
int stage_coord(int, int);		//スポーンする座標値が画面からの座標になるためグローバルの座標がひつよう


int GetDeadflag();			//値を取るだけ
int GetDeadflag(int);		//値をセットするが０か１のみ(deadflgへ)代入可能

void MainThread(HDC);

	void MainLoop(HDC);
	EnemyManager();
	EnemyManager(int);
	~EnemyManager();
};




