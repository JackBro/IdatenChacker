
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
	enemy.anim_flg = 0;

	enemyID = 0;

	enemy_bullet.onActive = 0;


}


int Enemy::enemyPaintBullet(){
	if (enemy_bullet.onActive == 1){
		HDC hdc_work;
		hdc_work = CreateCompatibleDC(enemyhdc);
		SelectObject(hdc_work, bullet_hb);
		TransparentBlt(enemyhdc, (int)enemy_bullet.x, (int)enemy_bullet.y, enemy_bullet.width, enemy_bullet.height, hdc_work, 0, 0, 120, 120, RGB(0, 0, 255));
		DeleteDC(hdc_work);
	}
	return 0;
}
 
//描画用
int Enemy::Enemy_paint(HDC hdc){

	enemyhdc = hdc;

	if (enemy.onActive & 1 && enemy.onActive > 0){

		HDC hdc_work;
		hdc_work = CreateCompatibleDC(hdc);
		SelectObject(hdc_work, enemy_hb);
		int ex = enemy.x;
		int ey = enemy.y;

		TransparentBlt(hdc, ex, ey, enemy.width, enemy.height, hdc_work, 0, 0, 120, 120 , RGB(0, 0, 255));
		DeleteDC(hdc_work);

	}
	return 0;


}

int Enemy::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}

int Enemy::hit_enemycheck(){

	static	MCI_OPEN_PARMS se_open;
	static	MCI_PLAY_PARMS se_playDevice;

	if (enemy.onActive & 1 && enemy.onActive > 0){
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
				if (ey <= ph - 12){
					DEADflg = -1;//??キャラに影響する 死亡の扱いは不明。
					mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
					se_open.lpstrDeviceType = L"WaveAudio";
					se_open.lpstrElementName = L"res/SE/damage.wav";
					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
					mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);

				}
				else{
					plstats->c_flg = 4;
					mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
					se_open.lpstrDeviceType = L"WaveAudio";
					se_open.lpstrElementName = L"res/SE/pop.wav";
					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
					mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);
				}
			}
			
			enemy.onActive = 0;
			enemy_bullet.onActive = 0;

		}
	}
	else {
		enemy.onActive++;
	}
	return 0;
}

int Enemy::hit_enemycheckN(){
	static	MCI_OPEN_PARMS se_Item;
	static	MCI_PLAY_PARMS se_playDevice;
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
			enemy.onActive = 0;
		}
	}
	return 0;
}

int Enemy::hit_enemycheckRide() {
	if (enemy.onActive & 1) {
		//当たり判定　四角形
		int ex = enemy.x;
		int ey = enemy.y;
		int ew = ex + enemy.width;
		int eh = ey + enemy.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		
		if (ex <= pw && px <= ew && ey <= ph && py <= eh) {
			if (plstats->c_flg == 3 || plstats->c_flg == 2) {
				enemy.onActive = 0;//??キャラに影響する 死亡の扱いは不明。
				return 0;
			}
			if (ph - eh < -70 ) { //上
				plstats->y = ey - plstats->height - 0.5;
				plstats->vy = 0;
				if (plstats->c_flg != 3 && plstats->c_flg != 2) {
					plstats->c_flg = 0;
				}
				return 0;
			}

			if (eh - py < MAX_LENGTH + (-plstats->vy * 2)) { //下
				if (plstats->c_flg == 5) {
					plstats->vy = 0;
				}
				plstats->y = eh + 1;
				return 0;
			}

				if (ew - px < MAX_LENGTH + -plstats->vx * 1.5) {
					plstats->x = ew;
					plstats->vx = 0;
				}


				if (plstats->vx > 0) {
					if (pw - ex < MAX_LENGTH + plstats->vx * 2) {
						plstats->x = ex - plstats->width;
						plstats->vx = 0;
					}
				}

//				DebugStringFloat("%d", pw - ex, enemyhdc, 200, 200, 20);

			//
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

float Enemy::Enemy_x() {
	return enemy.x;
}

float Enemy::Enemy_y() {
	return enemy.y;
}