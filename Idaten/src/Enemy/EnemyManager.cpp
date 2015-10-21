#pragma once
#include "EnemyManager.h"



EnemyManager::EnemyManager()
{
	stageID = Stage1;
	deadflg = 0;
	MaxEnemy = 3;

	SetSpawnPoint();

	//敵の初期スポーンオーダー
	for (int i = 0; i < MaxEnemy; i++) {
		SpawnList.push_back(i);
	}

}
EnemyManager::EnemyManager(int num)
{
	stageID = num;
	deadflg = 0;
	if (num == Stage1) {
		MaxEnemy = 3;
	}
	else if (num == Stage2) {
		MaxEnemy = 13;
	}

	SetSpawnPoint();

	//敵の初期スポーンオーダー
	for (int i = 0; i < MaxEnemy; i++) {
		SpawnList.push_back(i);
	}


}


EnemyManager::~EnemyManager()
{

}

int EnemyManager::SpawnEnemy(){
	if (eobj.size() >= MaxEnemy) 
		return -1;		//例外処理
		
		srand((int)time(NULL));
		GetSpawnPoint(SpawnList[0]);

		int ran = rand() % 3 + 1;

		switch (ran) {
		case 1:
		{
			std::unique_ptr<Enemy>obj(new Enemy01(spawnpoint[0], spawnpoint[1]));
			obj->EnemyID(SpawnList[0]);
			eobj.push_back(std::move(obj));
			break;
		}
		/*
	case 2:
	{
			  std::unique_ptr<Enemy>obj(new Enemy02(spawnpoint[0], spawnpoint[1]));
			  eobj[i] = std::move(obj);
			  return 1;		}
	case 3:
	{
			  std::unique_ptr<Enemy>obj(new Enemy03(spawnpoint[0], spawnpoint[1]));
			  eobj[i] = std::move(obj);
			  return 1;		}
	case 4:
	{
			  std::unique_ptr<Enemy>obj(new Enemy04(spawnpoint[0], spawnpoint[1]));
			  eobj[i] = std::move(obj);
			  return 1;		}
	case 5:
	{
			  std::unique_ptr<Enemy>obj(new Enemy05(spawnpoint[0], spawnpoint[1]));
			  eobj[i] = std::move(obj);
			  return 1;		}
			  */
		case 2:
		{
			std::unique_ptr<Enemy>obj(new Enemy06(spawnpoint[0], spawnpoint[1]));
			obj->EnemyID(SpawnList[0]);
			eobj.push_back(std::move(obj));
			break;
		}
		case 3:
		{
			std::unique_ptr<Enemy>obj(new Enemy07(spawnpoint[0], spawnpoint[1]));
			obj->EnemyID(SpawnList[0]);
			eobj.push_back(std::move(obj));
			break;
		}

		}//switch
		
		SpawnList.erase(SpawnList.begin());
		return 0;

}

void EnemyManager::MainLoop(HDC hdc){
	static int cnt = SpawnInterval;

	enemyhdc = hdc;
	if (cnt >= SpawnInterval){
		SpawnEnemy();

		
		cnt = SpawnInterval / 2;
	}
	
	cnt++;
/*
	if(SpawnList.empty()){}
	else
		DebugStringVal("%d", SpawnList[0], hdc, 200, 200, 20);
	*/	


	//敵の移動。キャラとの判定。消滅など。
	for (int i = 0; i < eobj.size(); i++) {
		//	DebugStringVal("Call=%d", i, hdc, 100, 50 + (10 * i), 15);
		int ex = eobj[i]->Enemy_x(), ey = eobj[i]->Enemy_y();
		eobj[i]->enemy_scroll(scroll_x, scroll_y);
		eobj[i]->bullet_scroll(scroll_x, scroll_y);

		if (ex > 0 && ey > 0 && ex < WINDOW_WIDTH && ey < WINDOW_HEIGHT) {
			eobj[i]->chara_strc(plstats);
			eobj[i]->move_enemy();
			eobj[i]->Enemy_paint(hdc);

			//敵からの死亡フラグを得る
			if (eobj[i]->get_deadflg()) {
				GetDeadflag(eobj[i]->get_deadflg());
			}

			//敵が消滅したらオブジェクトを外す　//メモリはユニークポインタが開放してくれる
			if (eobj[i]->get_onActive() == 0) {
				SpawnList.push_back(eobj[i]->EnemyID());
				cnt = 0;
				eobj.erase(eobj.begin() + i);

				break;
			}
		}
	}
}


int EnemyManager::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}

void EnemyManager::SetSpawnPoint() {
	//はじめに座標の指定をすべて行います
	if (stageID == Stage1) {
		int xy[3][2] = {
			{ 177 * CHIP_SIZE, 24 * CHIP_SIZE },
			{ 164 * CHIP_SIZE, 41 * CHIP_SIZE },
			{ 96 * CHIP_SIZE, 29 * CHIP_SIZE }
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
			{ 22 * CHIP_SIZE, 41 * CHIP_SIZE },
			{ 37 * CHIP_SIZE, 45 * CHIP_SIZE },
			{ 106 * CHIP_SIZE, 28 * CHIP_SIZE },
			{ 112 * CHIP_SIZE, 45 * CHIP_SIZE },
			{ 126 * CHIP_SIZE, 2 * CHIP_SIZE },
			{ 154 * CHIP_SIZE, 45 * CHIP_SIZE },
			{ 164 * CHIP_SIZE, 2 * CHIP_SIZE },
			{ 167 * CHIP_SIZE, 17 * CHIP_SIZE },
			{ 196 * CHIP_SIZE, 28 * CHIP_SIZE },
			{ 210 * CHIP_SIZE, 45 * CHIP_SIZE },
			{ 217 * CHIP_SIZE, 21 * CHIP_SIZE },
			{ 243 * CHIP_SIZE, 30 * CHIP_SIZE },
			{ 279 * CHIP_SIZE, 12 * CHIP_SIZE }
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

int EnemyManager::GetSpawnPoint(int a){
	spawnpoint[0] = Stage_Spawnpoint[a][0] + maps_x;
	spawnpoint[1] = Stage_Spawnpoint[a][1] + maps_y;
	return 0;
}

int EnemyManager::enemy_scroll(int x, int y){
	scroll_x = x;
	scroll_y = y;
	return 0;
}

int EnemyManager::stage_coord(int x, int y){
	maps_x = x;
	maps_y = y;
	return 0;
}

int EnemyManager::GetDeadflag(){
		return deadflg;
}

int EnemyManager::GetDeadflag(int a){
	if (a == 0 || a == 1 || a==-1){
		deadflg = a;
	}
	return 0;
}