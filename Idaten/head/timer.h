#pragma once
#include<Windows.h>




class Timer {
	int cnt, min_cnt, sec_cnt;
public:
	Timer();	//コンストラクタ
	~Timer();	//デストラクタ
	int MainTimer(HDC hdc);
	int Get_min(){ return min_cnt; }
	int Get_sec(){ return sec_cnt; }

};

