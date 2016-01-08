#ifndef _timer_H
#define _timer_H
#include<Windows.h>
extern double S_time;

class Timer {
	DWORD timestart;	//プログラム起動時の時間
	DWORD timewindows;	//windowsの起動からの時間

public:
	Timer();
	~Timer();
	void StartTimer(HDC hdc);
	void WindowsTimer(HDC hdc);
	void ShowTime(HDC hdc);
	void ShowTime2(HDC hdc);
};
#endif