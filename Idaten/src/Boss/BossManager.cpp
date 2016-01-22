#pragma once
#include "BossManager.h"

BossManager::BossManager()
{
	stageID = Boss;
	deadflg = 0;
	SET_POINT();

}

BossManager::BossManager(int num)
{
	stageID = num;
	deadflg = 0;

	SET_POINT();

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
void BossManager::MAIN(HDC hdc){

	bosshdc = hdc;
	POP_BOSS();

	for (int i = 0; i < 1;i++){
		int ex = bsobj->Boss_x(), ey = bsobj->Boss_y();

		bsobj->chara_strc(plstats);
		bsobj->move_boss(hdc);
		bsobj->BOSS_paint(hdc);

		if (bsobj->get_deadflg()){
			GetDeadflag(bsobj->get_deadflg());
		}
		if (bsobj->get_boss_active() == 0){
			stageID = End;
			
		}
	
	}
	
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
	}
	return 0;
}