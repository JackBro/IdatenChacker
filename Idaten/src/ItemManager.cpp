#include "ItemManager.h"

#ifdef SETSPAWN
#else
#define SETSPAWN(num, x, y) map1_spawnpoint[num][0] = x, map1_spawnpoint[num][1] = y
#endif


ItemManager::ItemManager()
{
	SetSpawnPoint();
	maps_x = 0, maps_y = 0;
	itemtype = 0;

}


ItemManager::~ItemManager()
{
}

int ItemManager::SpawnItem(){
	//とりあえず呼ばれたら追加

	for (int i = 0; i < Maxitem; i++){


		if (iobj[i]){
		
			continue;
		}
		else{}
			GetSpawnPoint(i);
				  std::unique_ptr<Itemclass >obj(new Itemupper(spawnpoint[0], spawnpoint[1]));
				  iobj[i] = std::move(obj);
				  return 1;	
	}
	return 0;
}
void ItemManager::MainLoop(HDC hdc){
	static int cnt;

	itemhdc = hdc;
	if (cnt >= 20){
		SpawnItem();

		cnt = 0;
	}
	
	cnt++;
	//DebugStringVal("%d", cnt, hdc, 100, 80, 20);

	//敵の移動。キャラとの判定。消滅など。
	for (int i = 0; i < Maxitem; i++){
		if (iobj[i]){
//			DebugStringVal("%d", (int)iobj[i]->hit_itemcheck(), itemhdc, 100, 80 + (i + 1) * 20, 20);

			iobj[i]->chara_strc(plstats);
			iobj[i]->item_scroll(scroll_x, scroll_y);
			 itemtype = iobj[i]->hit_itemcheck();
			iobj[i]->Item_paint(hdc);
			if (iobj[i]->get_onActive() == 0){
				iobj[i].reset();
				cnt = -SpawnInterval;
				break;
			}
		}
	}
}


int ItemManager::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}

void ItemManager::SetSpawnPoint(){
	//はじめに座標の指定をすべて行います
	SETSPAWN(0, 72*CHIP_SIZE, 29*CHIP_SIZE);
	SETSPAWN(1, 121*CHIP_SIZE, 40*CHIP_SIZE);
	SETSPAWN(2, 155*CHIP_SIZE, 26*CHIP_SIZE);
	Maxitem = 3;

}

int ItemManager::GetSpawnPoint(int a){
	spawnpoint[0] = map1_spawnpoint[a][0] + maps_x;
	spawnpoint[1] = map1_spawnpoint[a][1] + maps_y;
	return 0;
}

int ItemManager::item_scroll(int x, int y){
	scroll_x = x;
	scroll_y = y;
	return 0;
}

int ItemManager::stage_coord(int x, int y){
	maps_x = x;
	maps_y = y;
	return 0;
}


int ItemManager::GetItemtype(int a){
	if (a == 0){
		itemtype = a;
	}
	return 0;
}