#include "EnemyManager.h"


#ifdef SETSPAWN

#else
	#define SETSPAWN(num, x, y) map1_spawnpoint[num][0] = x, map1_spawnpoint[num][1] = y
#endif

EnemyManager::EnemyManager()
{
	SetSpawnPoint();
	maps_x = 0, maps_y = 0;
	deadflg = 0;

}


EnemyManager::~EnemyManager()
{

}

int EnemyManager::SpawnEnemy(){
	//とりあえず呼ばれたら追加
	
	for (int i = 0; i < ENEMYMAX; i++){
	

		if (eobj[i]){
			continue;
		}
		else{}
		srand((int)time(NULL));
		GetSpawnPoint(i % 3);

		int ran = rand() % 3 + 1;

		switch (ran){
		case 1:
		{
				std::unique_ptr<Enemy>obj(new Enemy01(spawnpoint[0],spawnpoint[1]));
				eobj[i] = std::move(obj);
				return 1;		}
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
				  eobj[i] = std::move(obj);
				  return 1;		}
		case 3:
		{
				  std::unique_ptr<Enemy>obj(new Enemy07(spawnpoint[0], spawnpoint[1]));
				  eobj[i] = std::move(obj);
				  return 1;		}
		}
	}
	return 0;
}

void EnemyManager::MainLoop(HDC hdc){
	static int cnt;

	enemyhdc = hdc;
	if (cnt >= 20){
		SpawnEnemy();

		
		cnt = -100;
	}
	
	cnt++;



	//敵の移動。キャラとの判定。消滅など。
	for (int i = 0; i < ENEMYMAX; i++){
		if (eobj[i]){
			eobj[i]->chara_strc(plstats);
			eobj[i]->move_enemy();
			eobj[i]->enemy_scroll(scroll_x, scroll_y);
			eobj[i]->bullet_scroll(scroll_x, scroll_y);
			eobj[i]->Enemy_paint(hdc);
			if (eobj[i]->get_deadflg()){
				GetDeadflag(eobj[i]->get_deadflg());
			}
			if (eobj[i]->get_onActive() == 0){
				eobj[i].reset();
				cnt = -100;
				break;
			}
		}
	}
}


int EnemyManager::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}

void EnemyManager::SetSpawnPoint(){
	//はじめに座標の指定をすべて行います
	SETSPAWN(0, 177 * CHIP_SIZE, 24 * CHIP_SIZE);
	SETSPAWN(1, 164*CHIP_SIZE, 41*CHIP_SIZE);
	SETSPAWN(2, 96 * CHIP_SIZE, 29 * CHIP_SIZE);


}

int EnemyManager::GetSpawnPoint(int a){
	spawnpoint[0] = map1_spawnpoint[a][0] + maps_x;
	spawnpoint[1] = map1_spawnpoint[a][1] + maps_y;
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