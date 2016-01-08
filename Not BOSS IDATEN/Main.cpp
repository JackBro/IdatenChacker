#pragma once
#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")


#include <windows.h>
#include <math.h>	// atan2()���g�����߂ɕK�v
#include <time.h>   // time()���g���̂ɕK�v
#include <assert.h>

//�v�f
#include "Enemy\EnemyManager.h"
#include "Item\ItemManager.h"
#include"scroll.h"
#include"Block.h"
#include"timer.h"
#include"Ranking.h"
#include"SandStorm\SandStrom.h"


//�c�[���n
#include"Framerate\FrameRate.h"
#include"debugmsg.h"
#include<Thread>
#include<mmsystem.h>

//chara
#include "Paint_Player.h"
#include"player_info.h"

//�ݒ蓙
#include"Option.h"


static MCI_OPEN_PARMS mop;
static MCI_PLAY_PARMS mpp;

TCHAR szClassName[] = TEXT("Window01"); // �E�B���h�E�N���X�BUNICODE�Ƃ��Ă̕�����萔
TCHAR szClassName2[] = TEXT("edit2"); // �E�B���h�E�N���X�BUNICODE�Ƃ��Ă̕�����萔
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// �Q�[���p�E�C���h�E�v���V�[�W���֐�
LRESULT CALLBACK WndProc1(HWND, UINT, WPARAM, LPARAM);	// ���O�p�E�C���h�E�v���V�[�W���֐�

BOOL InitApp(HINSTANCE);	//�E�B���h�E�N���X�\����
BOOL InitApp1(HINSTANCE);	//���O�p
BOOL InitInstance(HINSTANCE, int);	//�E�B���h�E����
BOOL InitInstance1(HINSTANCE, int);	//���O�p

#define ID_EDIT1   1000		//EDIT�p
#define ID_BUTTON1    1020	//�{�^���p

HWND hWnd;					//�Q�[���p
HWND hEWnd1, hBWnd1;		//�G�f�B�b�g�p�A�{�^���p


int SceneNum;

int Paint(HDC);
int Paint_BG(HDC,int);
int Init_Game();
int Get_Key(int);
int SceneChanger();

double S_time;			//�^�C��
char namae[15];
static int flag2 = OFF;




#define KEY_SPACE 32

HBITMAP menu_hb[5];	//�^�C�g����N���A���

BYTE key_input_buff;// �L�[�{�[�h���
BYTE key_buff[256];


PAINT *paint_player_obj;
Scroll *scrobj;
Block *blobj;
EnemyManager *eobj;

ItemManager *iobj;
Timer *timeobj;
Ranking_Name rankobj;


SandStrom sandstorm;
FrameRate frr;





/////���C���֐�///////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	if (!hPrevInstance) {
		if (!InitApp(hInstance))		//�Q�[���p�̃E�B���h�E������
			return FALSE;
	}

	if (!InitInstance(hInstance, nCmdShow)) {	//�Q�[���p�̃E�B���h�E����
		return FALSE;
	}

	if (!hPrevInstance) {
		if (!InitApp1(hInstance))		//���O�p�̃E�B���h�E������
			return FALSE;
	}


	if (!InitInstance1(hInstance, nCmdShow)) {	//���O�p�̃E�B���h�E����
		return FALSE;
	}
	
	// ���b�Z�[�W���[�v
	while (true)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);  //�L�[�{�[�h���p���\�ɂ���
			DispatchMessage(&msg);
		}
		else
		{
			// WM_USER+1�ց@(�������Q�[�����[�v)
			SendMessage(hWnd, WM_USER + 1, 0, 0);

			// �X���[�v�֐���
			Sleep(20);
		}
	}

	return msg.wParam;
}

BOOL InitApp(HINSTANCE hInstance)
{
	WNDCLASS wc;
	// �E�C���h�E�N���X�\����
	ZeroMemory(&wc, sizeof(WNDCLASS));
	wc.style = CS_HREDRAW | CS_VREDRAW;         // �E�C���h�E�X�^�C��
	wc.lpfnWndProc = (WNDPROC)WndProc;                // �E�C���h�E�v���V�[�W���A�h���X
	wc.cbClsExtra = 0;                               // �⏕�̈�T�C�Y�i�g�p���Ȃ��j
	wc.cbWndExtra = 0;                               // �⏕�̈�T�C�Y�i�g�p���Ȃ��j
	wc.hInstance = hInstance;                       // �C���X�^���X�n���h��
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // �A�C�R��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);     // �}�E�X�J�[�\��
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);      // �E�B���h�E��ʂ̐F
	wc.lpszMenuName = NULL;                            // �E�C���h�E���j���[�i�g�p���Ȃ��j
	wc.lpszClassName = TEXT("Window01");                // �E�C���h�E�N���X��

	// �E�C���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) return FALSE;
}

BOOL InitApp1(HINSTANCE hInstance)
{
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(WNDCLASS));
	wc.style = CS_HREDRAW | CS_VREDRAW;		 // �E�C���h�E�X�^�C��
	wc.lpfnWndProc = WndProc1;				// �E�C���h�E�v���V�[�W���A�h���X
	wc.cbClsExtra = 0;						// �⏕�̈�T�C�Y�i�g�p���Ȃ��j
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;				// �C���X�^���X�n���h��
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;   // �E�C���h�E���j���[
	wc.lpszClassName = szClassName2;	// �E�C���h�E�N���X��

	// �E�C���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) return FALSE;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hWnd = CreateWindow(
		szClassName, TEXT("�C�_�e���E�`���b�J�["),					// �E�C���h�E�̃^�C�g����
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,			// �E�C���h�E�X�^�C��
		180,												// �E�B���h�E�̕\��X���W
		100,												// �E�B���h�E�̕\��Y���W
		WINDOW_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,						// �E�B���h�E�̕�
		WINDOW_HEIGHT + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// ����
		NULL,														// �e�E�C���h�E
		NULL,														// �E�C���h�E���j���[
		hInstance,													// �C���X�^���X�n���h��
		NULL);														 // WM_CREATE���

	// �E�C���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

BOOL InitInstance1(HINSTANCE hInstance, int nCmdShow)
{
	hWnd2 = CreateWindow(
		szClassName2,
		TEXT("���O����"),					// �E�C���h�E�̃^�C�g����
		WS_OVERLAPPED,			// �E�C���h�E�X�^�C��
		180,												// �E�B���h�E�̕\��X���W
		100,												// �E�B���h�E�̕\��Y���W
		180,						// �E�B���h�E�̕�
		150,						// ����
		NULL,														// �e�E�C���h�E
		NULL,														// �E�C���h�E���j���[
		hInstance,													// �C���X�^���X�n���h��
		NULL);													 // WM_CREATE���
	ShowWindow(hWnd2, nCmdShow);
	UpdateWindow(hWnd2);
	return TRUE;
}


///////�E�C���h�E�v���V�[�W���֐�//////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// �摜��ǂݍ��ޏ���
	HDC hdc;		// �f�o�C�X�R���e�L�X�g�n���h��
	PAINTSTRUCT ps; // �y�C���g�\����

	// �o�b�N�o�b�t�@�p�R���e�L�X�g�n���h���ƁA�r�b�g�}�b�v�n���h���̏���
	static HDC hdc_back;	// ����ʁi�o�b�N�o�b�t�@�j�p�f�o�C�X�R���e�L�X�g�n���h��
	static HBITMAP hb_back;	// ����ʁi�o�b�N�o�b�t�@�j�p�r�b�g�}�b�v�n���h��


	switch (msg)
	{

	case MM_MCINOTIFY:
		if (wParam != MCI_NOTIFY_SUCCESSFUL) {
			return 0;
		}
		mciSendCommand((MCIDEVICEID)lParam, MCI_SEEK, MCI_SEEK_TO_START, 0);
		mciSendCommand((MCIDEVICEID)lParam, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

		break;
	case WM_USER + 1:	// �Q�[�����[�v�iSendMessage����Ă΂��j

		// ���ʂ̍ĕ`��@WM_PAINT�����s����
		InvalidateRect(hWnd, NULL, false);
		return 0;

	case WM_PAINT:	// ��ʂ�`�悷�鎞�̏���

		hdc = BeginPaint(hWnd, &ps);	// �`��̊J�n
		Paint(hdc_back);				// Paint�֐���
		
		//�o�b�N�o�b�t�@�ɕۑ����ꂽ�摜��\��ʂɕ`��
		BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_back, 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);			// �`��̏I��

		return 0;
	
	case WM_CREATE:

		mop.lpstrDeviceType = L"WaveAudio";
		mop.lpstrElementName = L"res/Sound/title.wav";
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
		mpp.dwCallback = (DWORD)hWnd;

		mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

		frr.SetSampleNum(100);
		Init_Game();

		// �`��̊J�n
		hdc = GetDC(hWnd);
		// �݊��f�o�C�X�R���e�L�X�g�̍쐬
		hdc_back = CreateCompatibleDC(hdc);
		// �݊��r�b�g�}�b�v�̍쐬
		hb_back = CreateCompatibleBitmap(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);

		// �I�u�W�F�N�g�̑I��
		SelectObject(hdc_back, hb_back);
		// �`��̏I��
		ReleaseDC(hWnd, hdc);

		//�V�[���pBITMAP
		menu_hb[Title] = (HBITMAP)LoadImage(NULL, TEXT("res/bgImage/title.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		menu_hb[End] = (HBITMAP)LoadImage(NULL, TEXT("res/bgImage/end.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		return 0;

	case WM_DESTROY:	// �Ō�ɃE�C���h�E������ꂽ���̏���
		mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
		// �f�o�C�X�R���e�L�X�g�̉��
		DeleteDC(hdc_back);
		DeleteObject(hb_back);
		DeleteObject(menu_hb);
		PostQuitMessage(0);
		return 0;

	default:	// �f�t�H���g����
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

int Init_Game(){

	SceneNum = Title;

	return 0;
}

//���O����
LRESULT CALLBACK WndProc1(HWND hWnd2, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int id;
	PAINTSTRUCT ps;
	HDC hdc;
	HINSTANCE hInst;

	switch (msg) {

	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		hEWnd1 = CreateWindow(TEXT("EDIT"),		//���O���̗͂�
			TEXT("���O�����"),
			WS_CHILD | WS_VISIBLE,
			60, 10,
			100, 20,
			hWnd2,
			(HMENU)ID_EDIT1,
			hInst,
			NULL);
		hBWnd1 = CreateWindow(TEXT("BUTTON"),		//����{�^��
			TEXT("����"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			30, 50,
			100, 30,
			hWnd2,
			(HMENU)ID_BUTTON1,
			hInst,
			NULL);

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd2, &ps);
		TextOut(hdc, 10, 10, TEXT("���O�F"), 3);
		EndPaint(hWnd2, &ps);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_BUTTON1:
			GetWindowText(hEWnd1, rankobj.name, 30);
			rankobj.NameInput(hWnd2);
			DestroyWindow(hWnd2);
			break;
		default:
			return(DefWindowProc(hWnd2, msg, wParam, lParam));
		}
		break;
	case WM_DESTROY:
		break;
	default:
		return (DefWindowProc(hWnd2, msg, wParam, lParam));
	}
	return 0L;
}





/*
�I�u�W�F�N�g�D��x

Player Move
�@|
  V
Scroll			�w�i�`��̂��߁B
  |
  V
Item
  |
  V
Player�@Oil
�@|
�@V
 Enemy
  |
  V
BLOCK
  |
  V
Player�@Paint


*/


int Paint(HDC hdc)
{
	static MCI_OPEN_PARMS SEOPEN;
	static MCI_PLAY_PARMS SEPLAY;

	static int cc;
	if (SceneNum == Title){
		Paint_BG(hdc,Title);		// �w�i�`��֐���

		flag = ON;
		if (flag2 == OFF){
			flag2 = ON;
			InitInstance1(GetModuleHandle(NULL), SW_SHOW);	//���O�p�̃E�B���h�E����
		}

		if (cc > 50){
			cc = Get_Key(cc);
			if (cc == 1){
			
					SEOPEN.lpstrDeviceType = L"WaveAudio";
					SEOPEN.lpstrElementName = L"res/SE/tackle.wav";

					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&SEOPEN);
					mciSendCommand(SEOPEN.wDeviceID, MCI_PLAY, 0, (DWORD)&SEPLAY);


					mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
					mop.lpstrElementName = L"res/Sound/stagebgm.wav";
					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
					mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

			
				SceneChanger();
				eobj = new EnemyManager(SceneNum);
				iobj = new ItemManager(SceneNum);
				scrobj = new Scroll(SceneNum);
				blobj = new Block(SceneNum);
				paint_player_obj = new(PAINT);
				//oilobj = new(OIL);
				//paint_player_obj->obj2 = new(MOVE);

				timeobj = new(Timer);
				timeobj->WindowsTimer(hdc);		//windows�̋N������̎��Ԃ̏K��
				/*if (SceneNum == Boss)
				{
					bsobj = new BossManager(SceneNum);
				}*/

			}
		}

	}
	else if (SceneNum < 0){
		
		Paint_BG(hdc,-SceneNum);
		sandstorm.Start(hdc);

		if (cc > 1){

			mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);

			mop.lpstrElementName = L"res/Sound/stagebgm.wav";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
			mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

		

			SceneNum *= -1;	//�}�C�i�X�̒l�ɂȂ��Ă�SceneNum��߂�
			delete scrobj;
			scrobj = new Scroll(SceneNum);

			delete blobj;
			blobj = new Block(SceneNum);

			delete eobj;
				eobj = new EnemyManager(SceneNum);
			delete iobj;
			iobj = new ItemManager(SceneNum);
			
				paint_player_obj->obj2->player.x = 120;
				paint_player_obj->obj2->player.y = 420;
			
			sandstorm.End();

			
		}
	}
	else if (SceneNum == Stage1 || SceneNum == Stage2){
		
		paint_player_obj->obj2->C_sts(paint_player_obj->obj->c_sts, &paint_player_obj->obj->Oil_Gage);
		paint_player_obj->obj2->Move();

		//Scroll
		scrobj->toPoint(&paint_player_obj->obj2->player);
		scrobj->scroll_kansu(hdc);
		//Block
		blobj->toPoint(&paint_player_obj->obj2->player);
		blobj->block_scroll(scrobj->Backimg_x, scrobj->Backimg_y);
		int aa = 0;
		aa = blobj->block_kansu(hdc);	//�l���󂯎���Ă����玟��
		if (aa == 2){
			SceneNum++;
			SceneNum *= -1;
			cc = 0;
			sandstorm.Initialize(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
			//	DebugStringVal("%d", SceneNum, hdc, 200, 200, 20);
			sandstorm.Start(hdc);


			mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
			mop.lpstrElementName = L"res/Sound/SandStorm.wav";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
			mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, (DWORD)&mop);
		


			return 0;

		}


		//Enemy
		//-----------------------------
		eobj->chara_strc(&paint_player_obj->obj2->player);
		eobj->enemy_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
		eobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
		eobj->MainThread(hdc);

		paint_player_obj->obj->Item(eobj->GetDeadflag());		//�A�C�e�����擾���ăQ�[�W�ɕω������邩���f����(�G�̏ꍇ�́|�P�����j

		eobj->GetDeadflag(0);

		//�I�C���Q�[�W�ʂȂǍX�V����
		paint_player_obj->obj->Player_Sts();
		paint_player_obj->obj->Oil_Sts();


		//Item
		iobj->chara_strc(&paint_player_obj->obj2->player);
		iobj->item_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
		iobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
		iobj->MainThread(hdc);

		paint_player_obj->obj->Item(iobj->GetItemtype());		//�A�C�e�����擾���ăQ�[�W�ɕω������邩���f����
		//	DebugStringVal("%d", iobj->GetItemtype(), hdc, 300, 30, 20);

		iobj->GetItemtype(0);	//�l�̏������B�@���Ȃ��ƃo�O���o�܂��O���O

		//�I�C���Q�[�W�ʂȂǍX�V����
		paint_player_obj->obj->Player_Sts();
		paint_player_obj->obj->Oil_Sts();


		//�I�C���Ƃ��̃Q�[�W�̕`��
		paint_player_obj->obj->Paint_Oil(hdc);
		paint_player_obj->obj->Paint_Gage(hdc);


		//�ړ��ʂ̍ő�l�̗}��
		if (paint_player_obj->obj2->player.vx < -10)paint_player_obj->obj2->player.vx = -10;
		if (paint_player_obj->obj2->player.vy > 10)	paint_player_obj->obj2->player.vy = 10;

		paint_player_obj->obj2->player.x += paint_player_obj->obj2->player.vx;
		paint_player_obj->obj2->player.y += paint_player_obj->obj2->player.vy;

		//�L��������ʍ��W�O���O�֏o�Ȃ��悤�ɗ}��
		if (paint_player_obj->obj2->player.x < 0)	paint_player_obj->obj2->player.x = 0;
		if (paint_player_obj->obj2->player.y < 0)	paint_player_obj->obj2->player.y = 0;
		//	DebugStringFloat("%f",paint_player_obj->obj2->player.y,hdc,200,200,20);
		//�ȉ��`�揈��
		paint_player_obj->char_strc(&paint_player_obj->obj2->player);
		paint_player_obj->Paint_Player(hdc);

		timeobj->StartTimer(hdc);	//�v���O�������J�n���ꂽ���̎��Ԃ̏K��
		timeobj->ShowTime(hdc);

		
	}
	
	else if (SceneNum == Boss) {
		if (cc > 10) {
			SceneNum = End;
			cc = 0;

		}
	}
	else if (SceneNum == End){
		Paint_BG(hdc,End);  //ed
		timeobj->ShowTime(hdc);//�^�C���`��
		flag2 = OFF;
		if (flag == ON){
			rankobj.Reading();
			rankobj.AddRanking(hWnd2);		//�����L���O�X�V
			flag = OFF;
		}

		rankobj.Ranking_Paint(hdc);
		if (cc > 50){
			cc = Get_Key(cc);
			if (cc == 1){
				mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);

				mop.lpstrElementName = L"res/Sound/title.wav";
				mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
				mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

				SceneChanger();
				delete eobj;
				delete iobj;
				delete scrobj;
				delete blobj;
				delete paint_player_obj;
				delete timeobj;
			}
		}
		
	}
	cc++;
	//DebugStringFloat("%2.2f", frr.GetFrameRate() / 10, hdc, 100, 50, 22);


	return 0;
}


///// �L�[���͊֐� ///////////////////////////////////////////////////////
//�X�y�[�X�L�[��������Ă����ꍇ�P��Ԃ�
//����ȊO�͒l�����̂܂ܕԂ��܂�
int Get_Key(int count)
{
	GetKeyboardState(key_buff);
	key_input_buff = 0;

	if (key_buff[VK_SPACE] & 0x80){

		key_input_buff |= KEY_SPACE;
		return 1;
	}

	return count;
}

int Paint_BG(HDC hdc ,int Num){
	HDC hdc_work;
	hdc_work = CreateCompatibleDC(hdc);
	SelectObject(hdc_work, menu_hb[Num]);		// �I�u�W�F�N�g�̑I��
	BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_work, 0, 0, SRCCOPY);
	


	DeleteDC(hdc_work);// �f�o�C�X�R���e�L�X�g�̉��
	return 0;
}

int SceneChanger(){
	switch (key_input_buff)
	{
	case 32:
		
		if (SceneNum == Title){
			SceneNum = Stage1;
		}
		
		
		if (SceneNum == End){
			SceneNum = Title;
		}
		break;
	default:
		break;
	}
	return 0;
}
