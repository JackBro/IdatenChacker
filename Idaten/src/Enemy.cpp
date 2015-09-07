
#include"Enemy.h"

Enemy::Enemy(){
	//構造体の値の初期化
	enemy.x = 0, enemy.y = 0;
	enemy.dx = 0, enemy.dy = 0;
	enemy.rad_x = 0, enemy.rad_y = 0;
	enemy.step_x = 0, enemy.step_y = 0;
	enemy.width = 0, enemy.height = 0;
	enemy.onActive = 0;
	enemy.base_y = 0;
	enemy.actioncnt = 0;
	enemy.timecnt = 0;
	enemy.anim_count = 0;
	enemy.MAX_Tcnt = 0;

	enemyID = 0;

	enemy_bullet.onActive = 0;
}


int Enemy::enemyPaintBullet(){
	if (enemy_bullet.onActive == 1){
		HDC hdc_work;
		hdc_work = CreateCompatibleDC(enemyhdc);
		SelectObject(hdc_work, enemy_hb);
		TransparentBlt(enemyhdc, (int)enemy_bullet.x, (int)enemy_bullet.y, enemy_bullet.width, enemy_bullet.height, hdc_work, 0, 0, enemy_bullet.width, enemy_bullet.height, RGB(0, 0, 255));
		DeleteDC(hdc_work);
	}
	return 0;
}
 
//描画用
int Enemy::Enemy_paint(HDC hdc){

	enemyhdc = hdc;

	if (enemy.onActive & 1){

		HDC hdc_work;
		hdc_work = CreateCompatibleDC(hdc);
		SelectObject(hdc_work, enemy_hb);
		int ex = enemy.x;
		int ey = enemy.y;

		TransparentBlt(hdc, ex, ey, enemy.width, enemy.height, hdc_work, 0, 0, 300, 300, RGB(255, 255, 255));
		DeleteDC(hdc_work);

	}
	return 0;


}

int Enemy::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}

int Enemy::hit_enemycheck(){
	if (enemy.onActive & 1){
		//当たり判定　四角形
		int ex = enemy.x;
		int ey = enemy.y;
		int ew = ex + enemy.width;
		int eh = ey + enemy.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			if (plstats->c_flg != 3 && plstats->c_flg != 2){
				if (ey <= ph - 10){
					DEADflg = -1;//??キャラに影響する 死亡の扱いは不明。
				}
			}
			
			enemy.onActive = 0;
			enemy_bullet.onActive = 0;

		}
	}
	return 0;
}

int Enemy::hit_enemycheckN(){
	if (enemy.onActive & 1){
		//当たり判定　四角形
		int ex = enemy.x;
		int ey = enemy.y;
		int ew = ex + enemy.width;
		int eh = ey + enemy.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			if (plstats->c_flg != 3 && plstats->c_flg != 2)
				DEADflg = -1;//??キャラに影響する 死亡の扱いは不明。
		}
	}
	return 0;
}

int Enemy::enemy_scroll(int x,int y){
			enemy.x += x;
			enemy.y += y;
			enemy.base_y += y;
	return 0;
}

int Enemy::bullet_scroll(int x, int y){
	if (enemy_bullet.onActive & 1){
		enemy_bullet.x += x;
		enemy_bullet.y += y;
	}
	return 0;
}
