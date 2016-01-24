#pragma once
#include "MasterCloud.h"

MasterCloud::MasterCloud(int x, int y)
{
	init();
	boss.x = x;
	boss.y = y;

	boss_hb[MOVE] = (HBITMAP)LoadImage(NULL, TEXT("res/BOSS/MasterCloud.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	boss_hb[ATTACK] = (HBITMAP)LoadImage(NULL, TEXT("res/BOSS/MasterCloud_attack.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	
}


MasterCloud::~MasterCloud()
{
	DeleteObject(boss_hb);
}

int MasterCloud::init(){

	boss.step_y = 2;


	boss.dx = 0;
	boss.dy = 0;

	boss.width = 150;
	boss.height = 180;

	boss.max_cnt = 150;
	boss.move_cnt = 0;

	boss.active = 1;
	boss.durability = 3;
	m_attackCnt = 0;
	return 0;
}

int  MasterCloud::move_boss(HDC hdc){
	srand((int)time(NULL));
	static int Attack = 30;

	if (state == MOVE){
		boss.move_cnt++;
		if (boss.move_cnt > boss.max_cnt){
			boss.move_cnt = 0;
		}
		else if (boss.move_cnt <= boss.max_cnt / 2){
			boss.dy = boss.step_y;
		}
		else if (boss.move_cnt > 0){
			boss.dy = -boss.step_y;
		}
		boss.y += boss.dy;
	}if (state == ATTACK){
		if (!m_wind){
			m_wind = std::make_unique<AttackWind>(boss.x,boss.y+boss.height/2);
		}		
	}
	if (m_wind){
		m_wind->chara_strc(plstats);
		m_wind->Scroll(scroll_x, scroll_y);
		if (!m_wind->Update()){
			m_wind.reset();
			state = MOVE;
			return 0;
		}
		m_wind->Draw(hdc);
		m_wind->IsHit();
		DEADflg = m_wind->GetDeadflg();
		m_wind->GetDeadflg(0);
	}
	if (m_attackCnt > Attack){
		state = ATTACK;
		m_attackCnt = 0;
		Attack = int((boss.x-plstats->x) /12);
	}
	else if (state == MOVE){
		m_attackCnt++;
	}

	DebugStringVal("%d", Attack, hdc, 200, 220, 20);
	DebugStringVal("%d",m_attackCnt, hdc, 200, 200, 20);
	hit_bosscheck();
	return 0;
}

