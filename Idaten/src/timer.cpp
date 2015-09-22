#include "timer.h"
#include"debugmsg.h"

Timer::Timer()
{	
}

void Timer::StartTimer(HDC hdc){
	timewindows = GetTickCount();	
	DebugStringVal("タイム:%d秒", timewindows / 1000 - timestart / 1000, hdc, 950, 10, 20); //windowsの起動からの時間 - プログラム起動時に習得した時間
	return ;
}

void Timer::ShowTime(HDC hdc){
	S_time = timewindows/1000 - timestart/1000;			
	DebugStringVal("タイム:%d秒", S_time, hdc, 950, 10, 20); 
	return ;
}

Timer::~Timer()
{
	
}

void Timer::WindowsTimer(HDC hdc){

	timestart = GetTickCount();			//windows起動からの時間

	return ;
}

