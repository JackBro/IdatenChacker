#include<Windows.h>
 
class Timer {
	 DWORD timestart;	//�v���O�����N�����̎���
	 DWORD timewindows;	//windows�̋N������̎���
	 int S_time;
public:
	Timer();	
	~Timer();	
	void StartTimer(HDC hdc);
	void WindowsTimer(HDC hdc);
	void ShowTime(HDC hdc);
};

