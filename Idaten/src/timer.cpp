#pragma once
#include "timer.h"
#include"debugmsg.h"
#include"Option.h"

Timer::Timer()
{
	cnt = 0;
	min_cnt = 0;
	sec_cnt = 0;
}

Timer::~Timer()
{
}

int Timer::MainTimer(HDC hdc){
	cnt += 3;

	TCHAR disp_msg[100];
	wsprintf((LPWSTR)disp_msg, TEXT("‚s‚h‚l‚dF%3d:%2d"), cnt / 100, cnt%100);
	Str_Put(hdc, WINDOW_WIDTH-160, 10, 25, RGB(255, 255, 255), disp_msg);
	//DebugStringVal("‚s‚h‚l‚dF%3d", cnt/100, hdc, 920, 10, 25);
	//DebugStringVal(":%d", cnt%100, hdc, 1050, 10, 25);

	sec_cnt = cnt / 100;
	min_cnt = cnt % 100;
	return 0;
}

// Œv‘ªŠJn
//void Start(clock_t* pStart)
//{
//	*pStart = clock();
//}
//
// Œo‰ßŠÔ(msec)
//clock_t Elapse(clock_t ctStart)
//{
//	return (clock_t)((double)(clock() - ctStart) / (double)(CLOCKS_PER_SEC / 1000.0f));
//}
//