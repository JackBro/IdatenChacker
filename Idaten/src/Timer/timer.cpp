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
	S_time = (timewindows / 100) / 10.0 - (timestart / 100) / 10.0;					//windows起動-プログラムが起動した時

	DebugStringFloat("Time:%.1f秒", S_time, hdc, 950, 10, 20);
	return;
}



Timer::~Timer()
{

}

void Timer::WindowsTimer(HDC hdc){

	timestart = GetTickCount();			//windows起動からの時間

	return;
}

