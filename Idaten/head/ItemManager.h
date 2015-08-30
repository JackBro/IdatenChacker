#pragma once
#include<Windows.h>
#include"player_info.h"
#include<memory>
#include<math.h>
#include<time.h>

#include"Itemclass.h"

#include"Itemupper.h"
#include"Itemdowner.h"
#include"debugmsg.h"
#include"Option.h"


/*
******************************************************************************
クラスの説明
------------------------------------------------------------------------------
アイテムを生成するクラス

使用ヘッダ（クラス）
Memory	（unique_ptr）
Math
Time	(random関数)

Itemclass	(Itemの基礎クラス)
Itemupper	(値を増加させるItemのクラス)


外部から必要な値
Scrollクラス	メソッド名:ItemScroll(Int,Int)			//スクロールから背景の移動量（スクロール量）を取得する
Mapクラス		メソッド名:StageCoord(Int,Int)			//マップがスクロールした時の座標を取得


使い方例
//Item
iobj->chara_strc(player);
iobj->item_scroll(obj1.BackMoveX, obj1.BackMoveY);					※
iobj->stage_coord(obj2.get_block_X(), obj2.get_block_Y());			※
iobj->MainLoop(hdc);

//	pobj->joutaihenka(iobj->GetItemtype());

iobj->GetItemtype(0);


□解説□
キャラクターのステータス状態（座標等）をまず渡します。（判定するため）
スクロールの値とマップの値を取り。

MainloopにHDCを渡す。
	スポーンとかは勝手にやってくれる
	キャラクターとあたったという判定が取れたら
	GetItemTypeの戻り値に　 0　 以外の数値が得られる

	処理終了後には０を代入する。


※外部の値を必要とする





******************************************************************************

*/


class ItemManager{
	private:
		HDC itemhdc;	//デバイスコンテキストハンドル(Mainloopによりその都度更新される)
		int itemtype;

		player_info *plstats;	//敵に渡すキャラのデータのコピー(Main>>EnemyManager>>Enemy)

		int scroll_x, scroll_y;		//スクロール量を座標に反映させる
		int maps_x, maps_y;			//ステージの座標を格納しておく。　スクロールによって可変される座標値を取るため

		//出現座標格納用配列
		int spawnpoint[2];

		int map1_spawnpoint[3][2];	//マップ１用

		//メソッド

		//int getMapID();			//マップIDの取得<未使用>

		int SpawnItem();		//アイテムの生成
		int GetSpawnPoint(int);	//アイテムの出現ポイントを指定する。
		void SetSpawnPoint();	//アイテムの出現ポイントを初期化しておく。

		int Maxitem;	//アイテム最大数（可変）
		const int SpawnInterval = ITEM_SPAWN_INTERVAL;		//リスポーンするまでのインターバル


	public:

		std::unique_ptr<Itemclass>iobj[5];

		int chara_strc(player_info *tp);	//マネージャからキャラのステータスを格納する

		int item_scroll(int, int);		//スクロールに対応するため値を渡す
		int stage_coord(int, int);		//スポーンする座標値が画面からの座標になるためグローバルの座標がひつよう

		void MainLoop(HDC);
		int GetItemtype(){ return itemtype; }
		int GetItemtype(int);

	ItemManager();
	~ItemManager();
};

