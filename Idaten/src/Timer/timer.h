#pragma once
#include<Windows.h>
extern float S_time;

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

