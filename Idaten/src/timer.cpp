#pragma once
#include "timer.h"
#include"debugmsg.h"

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

	DebugStringVal("‚s‚h‚l‚dF%3d", cnt/100, hdc, 920, 10, 20);
	DebugStringVal(":%d", cnt%100, hdc, 1050, 10, 20);

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