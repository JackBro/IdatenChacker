#ifndef _timer_H
#define _timer_H
#include<Windows.h>
extern double S_time;

class Timer {
	DWORD timestart;	//�v���O�����N�����̎���
	DWORD timewindows;	//windows�̋N������̎���

public:
	Timer();
	~Timer();
	void StartTimer(HDC hdc);
	void WindowsTimer(HDC hdc);
	void ShowTime(HDC hdc);
	void ShowTime2(HDC hdc);
};
#endif