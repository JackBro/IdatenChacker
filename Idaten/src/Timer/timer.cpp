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
	S_time = (timewindows / 1) / 1000.0 - (timestart / 1) / 1000.0;					//windows�N��-�v���O�������N��������

	DebugStringFloatR("Time:%.3f�b", S_time, hdc, 850, 10, 40,-80);
	return;
}



Timer::~Timer()
{

}

void Timer::WindowsTimer(HDC hdc){

	timestart = GetTickCount();			//windows�N������̎���

	return;
}

