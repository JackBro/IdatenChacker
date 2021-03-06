#include "BOSS.h"


BOSS::BOSS()
{
	boss.x = 0, boss.y = 0;
	boss.dx = 0, boss.dy = 0;
	boss.step_y = 0;
	boss.width = 0, boss.height = 0;
	boss.move_cnt = 0;
	boss.max_cnt = 0;
	boss.hit_cnt = 0;
	boss.active = 0;
	boss.durability = 0;

	bossID = 0;
	stageID = 0;
	state = MOVE;

}
int BOSS::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}

int BOSS::hit_bosscheck(){

	if (boss.active & 1 && boss.active>0){

		int ex = boss.x;
		int ey = boss.y;
		int ew = ex + boss.width;
		int eh = ey + boss.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			if (plstats->c_flg == 3 || plstats->c_flg == 2){
				boss.active = -1;
				state = DEATH;
			}
			else{
				DEADflg = -1;
				plstats->vx = 0;
				plstats->x -= 400;
			}
		}

	}
	return 0;
}



/*int BOSS::nohit_bosscheck(){
if (boss.active & 1){

int ex = boss.x;
int ey = boss.y;
int ew = ex + boss.width;
int eh = ey + boss.height;
int px = (int)plstats->x;
int py = (int)plstats->y;
int pw = px + plstats->width;
int ph = py + plstats->height;

if (ex <= pw && px <= ew && ey <= ph && py <= eh){
if (plstats->c_flg != 3 && plstats->c_flg != 2){
DEADflg = -1;
}
}
}
return 0;
}*/

int BOSS::boss_scroll(int x, int y){
	boss.x += x;
	boss.y += y;
	scroll_x = x;
	scroll_y = y;
	return 0;
}


float BOSS::Boss_x(){
	return boss.x;
}

float BOSS::Boss_y(){
	return boss.y;
}

int BOSS::BOSS_paint(HDC hdc){

	bosshdc = hdc;

	if (boss.active & 1 || state == DEATH){
		HDC hdc_work;
		hdc_work = CreateCompatibleDC(hdc);
		SelectObject(hdc_work, boss_hb[state]);
		int ex = boss.x;
		int ey = boss.y;
		TransparentBlt(hdc, ex, ey, boss.width, boss.height, hdc_work, 0, 0, 120, 180, RGB(0, 0, 255));
		DeleteDC(hdc_work);
	}
	return 0;
}




BOSS::~BOSS()
{

}