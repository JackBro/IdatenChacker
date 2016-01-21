#include "timer.h"
#include"debugmsg.h"
#include "ranking.h"

Timer::Timer()
{
}

void Timer::StartTimer(HDC hdc){
	timewindows = GetTickCount();
	return;
}

void Timer::ShowTime(HDC hdc){
	S_time = (timewindows / 100) / 10.0 - (timestart / 100) / 10.0;					//windows起動-プログラムが起動した時

	DebugStringFloatR("Time:%.1f秒", S_time, hdc, 850, 10, 40,-80);
	return;
}



Timer::~Timer()
{

}

void Timer::WindowsTimer(HDC hdc){

	timestart = GetTickCount();			//windows起動からの時間

	return;
}

