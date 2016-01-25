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
	boss_hb[DEATH] = (HBITMAP)LoadImage(NULL, TEXT("res/BOSS/MasterCloud_death.bmp"),
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

	boss.max_cnt = 120;
	boss.move_cnt = 0;

	boss.active = 1;
	boss.durability = 3;
	m_attackCnt = 0;
	return 0;
}

int  MasterCloud::move_boss(HDC hdc){
	static	MCI_OPEN_PARMS se_open;
	static	MCI_PLAY_PARMS se_playDevice;

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
	}
	else if (state == ATTACK){
		if (!m_wind){
			m_wind = std::make_unique<AttackWind>(boss.x, boss.y + boss.height / 2);
			mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
			se_open.lpstrDeviceType = L"MPEGVideo";
			se_open.lpstrElementName = L"res/SE/wind.mp3";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
			mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);
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
	}
	else if (state == DEATH){
		static int cnt = 0;
		if (m_wind){
			m_wind.reset();
			m_wind = nullptr;
		}
		
		if (cnt % 20 == 0){
			mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
			se_open.lpstrDeviceType = L"WaveAudio";
			se_open.lpstrElementName = L"res/SE/bossdead.wav";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
			mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);
		}
		if (cnt > 100){
			boss.active = 0;
		}
		else if (cnt > 60){
			boss.y += 7;
		}if (cnt % 2 == 0){
			boss.x += 10;
		}
		else{
			boss.x -= 10;
		}


		cnt++;
	}
	if (m_attackCnt > Attack){
		state = ATTACK;
		m_attackCnt = 0;
		Attack = int((boss.x-plstats->x) /20);
	}
	else if (state == MOVE){
		m_attackCnt++;
	}

#ifdef _DEBUG_MODE
	DebugStringVal("%d", Attack, hdc, 200, 220, 20);
	DebugStringVal("%d", m_attackCnt, hdc, 200, 200, 20);
#endif // _DEBUG_MODE

	hit_bosscheck();
	return 0;
}

