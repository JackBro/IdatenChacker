#include "timer.h"
#include"../_Option/debugmsg.h"
#include "../Ranking/ranking.h"

Timer::Timer()
{
}

void Timer::StartTimer(HDC hdc){
	timewindows = GetTickCount();
	return;
}

void Timer::ShowTime(HDC hdc){
	S_time = (timewindows / 1) / 1000.0 - (timestart / 1) / 1000.0;					//windows起動-プログラムが起動した時

	DebugStringFloatR("Time:%.3f秒", S_time, hdc, 850, 10, 40,-80);
	return;
}



Timer::~Timer()
{

}

void Timer::WindowsTimer(HDC hdc){

	timestart = GetTickCount();			//windows起動からの時間

	return;
}

