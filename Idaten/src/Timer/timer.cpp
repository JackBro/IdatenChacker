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
	S_time = (timewindows / 1) / 1000.0 - (timestart / 1) / 1000.0;					//windowsN®-vOªN®µ½

<<<<<<< HEAD
	DebugStringFloat("Time:%.1fb", S_time, hdc, 950, 10, 20);
=======
	DebugStringFloatR("Time:%.3fb", S_time, hdc, 850, 10, 40,-80);
>>>>>>> 4b44a3b... ãã¼ã¹ã³ããã
	return;
}



Timer::~Timer()
{

}

void Timer::WindowsTimer(HDC hdc){

	timestart = GetTickCount();			//windowsN®©çÌÔ

	return;
}

