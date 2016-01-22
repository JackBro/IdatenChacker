#include "BossAtackManager.h"


BossAtackManager::BossAtackManager()
{
	stageID = Boss;
	Max_Atack = 8;
	Set_SpawnPoint();

	for (int i = 0; i < Max_Atack; i++){
		SpawnList.push_back(i);
	}

}

BossAtackManager::BossAtackManager(int num)
{
	stageID = Boss;
	Max_Atack = 8;
	Set_SpawnPoint();

	for (int i = 0; i < Max_Atack; i++){
		SpawnList.push_back(i);
	}
}
BossAtackManager::~BossAtackManager(){

}

int BossAtackManager::SpawnAtack()
{
	if (acobj.size() >= Max_Atack)
		return -1;

	int Get_SpawnPoint(SpawnList[0]);

	std::unique_ptr<AtackClass>obj(new BossAtack(SpawnPoint[0], SpawnPoint[1]));
	obj->AtackID(SpawnList[0]);
	acobj.push_back(std::move(obj));

	SpawnList.erase(SpawnList.begin());
	return 0;
}


void BossAtackManager::Main(HDC hdc)
{
	static int cnt;

	atackhdc = hdc;
	if (cnt > 20){
		SpawnAtack();
		cnt = 0;
	}
	cnt++;
		//DebugStringVal("%d", SpawnPoint[0], hdc, 200, 250, 20);
	

	for (int i = 0; i < acobj.size(); i++)
	{
		
		int ex = acobj[i]->Atack_x(), ey = acobj[i]->Atack_y();
		acobj[i]->atack_scroll(scroll_x, scroll_y);
		if (ex > 0 - 30 && ey > 0 - 30  && ex < WINDOW_WIDTH + 30 && ey < WINDOW_HEIGHT + 30)
		{
			
			acobj[i]->chara_strc(plstats);
			acobj[i]->move();
			acobj[i]->Atack_Paint(hdc);

			if (acobj[i]->get_atack_active() == 0)
			{
				SpawnList.push_back(acobj[i]->AtackID());
				cnt = -SpawnInterval;
				acobj.erase(acobj.begin() + i);
				break;
			}
		}
	}
}

int BossAtackManager::chara_strc(player_info *tp)
{
	plstats = tp;
	return 0;
}

void BossAtackManager::Set_SpawnPoint()
{
	int xy[8][2]={
		{ 194 * CHIP_SIZE, 42 * CHIP_SIZE },
		{ 155 * CHIP_SIZE, 25 * CHIP_SIZE },
		{ 133 * CHIP_SIZE, 6 * CHIP_SIZE },
		{ 124 * CHIP_SIZE, 16 * CHIP_SIZE },
		{ 110 * CHIP_SIZE, 20 * CHIP_SIZE },
		{ 108 * CHIP_SIZE, 5 * CHIP_SIZE },
		{ 94 * CHIP_SIZE, 36 * CHIP_SIZE },
		{ 30 * CHIP_SIZE, 40 * CHIP_SIZE },
	};
	std::vector<int>n;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 2; j++){
			n.push_back(xy[i][j]);
		}
		Stage_Spawnpoint.push_back(n);
		n.clear();
	}
	maps_x = 0;
	maps_y = -(35 * CHIP_SIZE - 350);
}

int BossAtackManager::Get_SpawnPoint(int a)
{
	SpawnPoint[0] = Stage_Spawnpoint[a][0] + maps_x;
	SpawnPoint[1] = Stage_Spawnpoint[a][1] + maps_y;
	return 0;
}

int BossAtackManager::Atack_scroll(int x, int y)
{
	scroll_x = x;
	scroll_y = y;
	return 0;
}

int BossAtackManager::stage_coord(int x, int y)
{
	maps_x = x;
	maps_y = y;
	return 0;
}

int BossAtackManager::GetDeadflag()
{
	return deadflg;
}

int BossAtackManager::GetDeadflag(int a)
{
	if (a == 0 || a == 1 || a == -1 ||a == 2){
		deadflg = a;
		for (int i = 0; i < acobj.size(); i++){
			acobj[i]->get_deadflg(a);
		}
	}
	return 0;
}