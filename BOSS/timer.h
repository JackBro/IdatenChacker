#pragma once
#include<Windows.h>




class Timer {
	int cnt, min_cnt, sec_cnt;
public:
	Timer();	//�R���X�g���N�^
	~Timer();	//�f�X�g���N�^
	int MainTimer(HDC hdc);
	int Get_min(){ return min_cnt; }
	int Get_sec(){ return sec_cnt; }

};

