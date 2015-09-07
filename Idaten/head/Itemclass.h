#pragma once
#include<Windows.h>
#include"player_info.h"

class Itemclass{
protected:
		HDC itemhdc;
		int itemtype;

		HBITMAP item_hb;

		player_info *plstats;

		int itemID;

		struct item_info {
			float x, y;
			int width, height;
			int onActive;
		}item;
public:



		//共有メソッド
		int Item_paint(HDC enemy_hdc);
		int chara_strc(player_info *tp);	//マネージャからキャラのステータスを格納する

		int hit_itemcheck();		//敵との当たり判定

		void ItemID(int a) { itemID = a; }
		int ItemID() { return itemID; }

		int item_scroll(int, int);
		int getItemtype(){ return itemtype; }
		int get_onActive(){ return item.onActive; }

	Itemclass();
	virtual	~Itemclass();
};

