#include "ItemManager.h"



ItemManager::ItemManager()
{
	stageID = Stage1;
	Maxitem = 3;
	itemtype = 0;

	SetSpawnPoint();

	//敵の初期スポーンオーダー
	for (int i = 0; i < Maxitem; i++) {
		SpawnList.push_back(i);
	}
}
ItemManager::ItemManager(int num) {
	stageID = num;
	itemtype = 0;

	if (num == Stage1) {
		Maxitem = 3;
	}
	else if (num == Stage2) {
		Maxitem = 13;
	}

	SetSpawnPoint();

	//敵の初期スポーンオーダー
	for (int i = 0; i < Maxitem; i++) {
		SpawnList.push_back(i);
	}

}


ItemManager::~ItemManager()
{
}

int ItemManager::SpawnItem(){
	if (iobj.size() >= Maxitem)
		return -1;		//例外処理

		//オーダーの位置の座標を得る
		GetSpawnPoint(SpawnList[0]);
		
		//生成時に番号を振る
		  std::unique_ptr<Itemclass >obj(new Itemupper(spawnpoint[0], spawnpoint[1]));
		  obj->ItemID(SpawnList[0]);
		  iobj.push_back(std::move(obj));

		  //生成し終わったら最初のオーダーを消す
		  SpawnList.erase(SpawnList.begin());
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
	for (int i = 0; i < iobj.size(); i++) {
		int ix = iobj[i]->Item_x(), iy = iobj[i]->Item_y();
		iobj[i]->item_scroll(scroll_x, scroll_y);
		if (ix > -30 && iy > -30 && ix < WINDOW_WIDTH + 30 && iy < WINDOW_HEIGHT + 30) {
			iobj[i]->chara_strc(plstats);
			itemtype = iobj[i]->hit_itemcheck();
			iobj[i]->Item_paint(hdc);

			//アイテムが消滅したらオブジェクトを外す　//メモリはユニークポインタが開放してくれる
			if (iobj[i]->get_onActive() == 0) {
				SpawnList.push_back(iobj[i]->ItemID());
				cnt = -SpawnInterval;
				iobj.erase(iobj.begin() + i);
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
	if (stageID == Stage1) {
		int xy[3][2] = {
			{ 72 * CHIP_SIZE, 29 * CHIP_SIZE },
			{ 121 * CHIP_SIZE, 40 * CHIP_SIZE },
			{ 155 * CHIP_SIZE, 26 * CHIP_SIZE }
		};
		std::vector<int>n;
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 2; i++) {
				n.push_back(xy[j][i]);
			}
			Stage_Spawnpoint.push_back(n);
			n.clear();
		}
		maps_x = 0;
		maps_y = -(30 * CHIP_SIZE - 350);
	}
	else if (stageID == Stage2) {
		int xy[13][2] = {
			{ 42 * CHIP_SIZE, 34 * CHIP_SIZE },
			{ 59 * CHIP_SIZE, 45 * CHIP_SIZE },
			{ 69 * CHIP_SIZE, 22 * CHIP_SIZE },
			{ 85 * CHIP_SIZE, 45 * CHIP_SIZE },
			{ 86 * CHIP_SIZE, 19 * CHIP_SIZE },
			{ 86 * CHIP_SIZE, 9 * CHIP_SIZE },
			{ 106 * CHIP_SIZE, 40 * CHIP_SIZE },
			{ 129 * CHIP_SIZE, 45 * CHIP_SIZE },
			{ 145 * CHIP_SIZE, 41 * CHIP_SIZE },
			{ 188 * CHIP_SIZE, 16 * CHIP_SIZE },
			{ 205 * CHIP_SIZE, 40 * CHIP_SIZE },
			{ 213 * CHIP_SIZE, 11 * CHIP_SIZE },
			{ 271 * CHIP_SIZE, 30 * CHIP_SIZE }
		};
		std::vector<int>n;
		for (int j = 0; j < 13; j++) {
			for (int i = 0; i < 2; i++) {
				n.push_back(xy[j][i]);
			}
			Stage_Spawnpoint.push_back(n);
			n.clear();
		}
		maps_x = 0;
		maps_y = -(44 * CHIP_SIZE - 350);
	}

}

int ItemManager::GetSpawnPoint(int a){
	spawnpoint[0] = Stage_Spawnpoint[a][0] + maps_x;
	spawnpoint[1] = Stage_Spawnpoint[a][1] + maps_y;
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

void ItemManager::MainThread(HDC hdc) {
	std::thread t1(&ItemManager::MainLoop, this, hdc);
	t1.join();
}