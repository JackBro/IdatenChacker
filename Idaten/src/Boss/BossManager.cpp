#pragma once
#include "BossManager.h"

BossManager::BossManager()
{
	deadflg = 0;
	SET_POINT();
	AlreadySpawn = false;

}

BossManager::~BossManager()
{
}

int BossManager::POP_BOSS(){


	GET_POINT(0);

	
	bsobj = std::make_unique<MasterCloud>(POPPOINT[0], POPPOINT[1]);
	bsobj->BOSSID(0);
	return 0;
}
int BossManager::MAIN(HDC hdc){


	bosshdc = hdc;
	if (!AlreadySpawn){
		POP_BOSS();
		AlreadySpawn = true;
	}
	if (bsobj){
		int ex = bsobj->Boss_x(), ey = bsobj->Boss_y();

		bsobj->boss_scroll(scroll_x, scroll_y);
		bsobj->chara_strc(plstats);
		if (ex > 0 - 30 && ey > 0 - 30 && ex < WINDOW_WIDTH + 100 && ey < WINDOW_HEIGHT + 100){
			bsobj->move_boss(hdc);
			bsobj->BOSS_paint(hdc);
		}

		if (bsobj->get_deadflg()){
			GetDeadflag(bsobj->get_deadflg());
		}
		if (bsobj->get_boss_active() == 0){
			return End;
		}
	}
	return 0;
	
}

int BossManager::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}
void BossManager::SET_POINT(){
	int desinate[1][2]{
		{ 215 * CHIP_SIZE, 35 * CHIP_SIZE }
	};
	std::vector<int>n;
	for (int i = 0; i < 1; i++){
		for (int j = 0; j < 2; j++){
			n.push_back(desinate[i][j]);
		}
		DESINATE.push_back(n);
		n.clear();
	}
	maps_x = 0;
	maps_y = -(35 * CHIP_SIZE - 350);
}

int BossManager::GET_POINT(int a){
	POPPOINT[0] = DESINATE[a][0] + maps_x;
	POPPOINT[1] = DESINATE[a][1] + maps_y;
	return 0;
}


int BossManager::BOSS_SCROLL(int x, int y){
	scroll_x = x;
	scroll_y = y;
	return 0;
}
int BossManager::STAGE_COOD(int x, int y){
	maps_x = x;
	maps_y = y;
	return 0;
}

int BossManager::GetDeadflag(){
	return deadflg;
}

int BossManager::GetDeadflag(int a){
	if (a == 0 || a == 1 || a == -1){
		deadflg = a;
		bsobj->get_deadflg(0);
	}
	return 0;
}