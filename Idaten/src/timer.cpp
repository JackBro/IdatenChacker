#include "timer.h"
#include"debugmsg.h"

Timer::Timer()
{	
}

void Timer::StartTimer(HDC hdc){
	timewindows = GetTickCount();	
	DebugStringVal("�^�C��:%d�b", timewindows / 1000 - timestart / 1000, hdc, 950, 10, 20); //windows�̋N������̎��� - �v���O�����N�����ɏK����������
	return ;
}

void Timer::ShowTime(HDC hdc){
	S_time = timewindows/1000 - timestart/1000;			
	DebugStringVal("�^�C��:%d�b", S_time, hdc, 950, 10, 20); 
	return ;
}

Timer::~Timer()
{
	
}

void Timer::WindowsTimer(HDC hdc){

	timestart = GetTickCount();			//windows�N������̎���

	return ;
}

