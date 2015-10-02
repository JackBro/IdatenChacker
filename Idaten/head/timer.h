#include<Windows.h>
 
class Timer {
	 DWORD timestart;	//プログラム起動時の時間
	 DWORD timewindows;	//windowsの起動からの時間
	 int S_time;
public:
	Timer();	
	~Timer();	
	void StartTimer(HDC hdc);
	void WindowsTimer(HDC hdc);
	void ShowTime(HDC hdc);
};

