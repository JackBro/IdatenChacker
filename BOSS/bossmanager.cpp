#include "bossmanager.h"

bossmanager::bossmanager()
{
	stageID = Boss;
	deadflg = 0;

	SET_POINT();

	for (int i = 0; i < 1;i++)
	{
		POPLIST.push_back(i);
	}

}

bossmanager::bossmanager(int num)
{
	stageID = num;
	deadflg = 0;

	SET_POINT();

	for (int i = 0; i < 1;i++)
	{
	POPLIST.push_back(i);
	}

}

bossmanager::~bossmanager()
{
}

int bossmanager::POP_BOSS(){


		GET_POINT(POPLIST[0]);

		std::unique_ptr<BOSS>obj(new master_cloud(POPPOINT[0], POPPOINT[1]));
		obj->BOSSID(POPLIST[0]);
			bsobj = std::move(obj);

			//POPLIST.erase(POPLIST.begin());
	return 0;
}
void bossmanager::MAIN(HDC hdc){

		bosshdc = hdc;
		POP_BOSS();

		DebugStringVal("%d", POPLIST, hdc, 200, 200, 20);

		int ex = bsobj->Boss_x(), ey = bsobj->Boss_y();

	if (ex > 0 && ey > 0 && ex < WINDOW_WIDTH && ey < WINDOW_HEIGHT){
		bsobj->chara_strc(plstats);
		bsobj->move_boss();
		bsobj->BOSS_paint(hdc);
		if (bsobj->get_deadflg()){
			GetDeadflag(bsobj->get_deadflg());
		}
		if (bsobj->get_boss_active() == 0){
			stageID = End;
		}
	}

}

int bossmanager::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}
void bossmanager::SET_POINT(){
	int desinate[1][2]{
		{ 200 * CHIP_SIZE, 40 * CHIP_SIZE }
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

int bossmanager::GET_POINT(int a){
	POPPOINT[0] = DESINATE[a][0] + maps_x;
	POPPOINT[1] = DESINATE[a][1] + maps_y;
	return 0;
}


int bossmanager::BOSS_SCROLL(int x, int y){
	scroll_x = x;
	scroll_y = y;
	return 0;
}
int bossmanager::STAGE_COOD(int x, int y){
	maps_x = x;
	maps_y = y;
	return 0;
}

int bossmanager::GetDeadflag(){
	return deadflg;
}

int bossmanager::GetDeadflag(int a){
	if (a == 0 || a == 1 || a == -1){
		deadflg = a;
	}
	return 0;
}