#pragma once
#include<Windows.h>
#include"../Charactor/player_info.h"
#include<memory>
#include<vector>
#include<math.h>
#include<time.h>
#include"AtackClass.h"
#include"BossAtack.h"

#include"../_Option/Option.h"
#include"../_Option/debugmsg.h"
class BossAtackManager
{

	HDC atackhdc;

	player_info *plstats;

	int stageID;

	int ax, ay;
	int scroll_x, scroll_y;
	int maps_x, maps_y;

	int deadflg;

	int SpawnAtack();
	int Get_SpawnPoint(int);
	void Set_SpawnPoint();

	int Max_Atack;

	int SpawnPoint[2];

	std::vector<std::vector<int>>Stage_Spawnpoint;

	const int SpawnInterval = ITEM_SPAWN_INTERVAL;

	std::vector<int>SpawnList;

	std::vector<std::unique_ptr<AtackClass>>acobj;
public:
	int chara_strc(player_info *tp);

	int Atack_scroll(int, int);
	int stage_coord(int, int);

	int GetDeadflag();
	int GetDeadflag(int);


	void Main(HDC);
	BossAtackManager();
	~BossAtackManager();
};

