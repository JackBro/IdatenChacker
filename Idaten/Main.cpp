#pragma once
#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")


#include <windows.h>
#include <math.h>	// atan2()���g�����߂ɕK�v
#include <time.h>   // time()���g���̂ɕK�v
#include <assert.h>
#include<memory>
//�ݒ蓙
#include"src/_Option/Option.h"

//�v�f
#include"src/Boss/BossManager.h"
#include"src/Boss/BossAtackManager.h"

#include "src/Enemy/EnemyManager.h"
#include "src/Item/ItemManager.h"
#include"src/Scroll/scroll.h"
#include"src/Block/Block.h"
#include"src/Timer/timer.h"
#include"src/Ranking/Ranking.h"
#include"src/SandStorm/SandStrom.h"

//�c�[���n
#ifdef _DEBUG_MODE
#include"src/_Option/ConsoleWindow.h"
#include"src/Framerate/FrameRate.h"
#endif _DEBUG_MODE_

#include"src/_Option/debugmsg.h"
#include<Thread>
#include<mmsystem.h>

//chara
#include "src/Charactor/Paint_Player.h"
#include"src/Charactor/player_info.h"



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

float S_time;			//�^�C��
char namae[15];
static int flag2 = OFF;
static int flag3 = OFF;



#define KEY_SPACE 32


HBITMAP menu_hb[5];	//�^�C�g����N���A���

BYTE key_input_buff;// �L�[�{�[�h���
BYTE key_buff[256];


std::shared_ptr<PAINT>paint_player_obj;
std::shared_ptr<Scroll>scrobj;
std::shared_ptr<Block>blobj;
std::shared_ptr<EnemyManager>eobj;
std::shared_ptr<BossManager>bsobj;
std::shared_ptr<BossAtackManager>bsAtkobj;

std::shared_ptr<ItemManager>iobj;
std::shared_ptr<Timer>timeobj;
Ranking_Name rankobj;


SandStrom sandstorm;

#ifdef _DEBUG_MODE
FrameRate frr;

#endif // DEBUG_MODE




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
		
#ifdef _DEBUG_MODE
		frr.SetSampleNum(100);
		aetherClass::ConsoleWindow::Create();		
#endif // _DEBUG_MODE
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
#ifdef _DEBUG_MODE
		aetherClass::ConsoleWindow::Close();
#endif // _DEBUG_MODE

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
		flag3 = ON;
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
			if (flag3 == ON){
				if (cc == 1){

					SEOPEN.lpstrDeviceType = L"WaveAudio";
					SEOPEN.lpstrElementName = L"res/SE/tackle.wav";

					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&SEOPEN);
					mciSendCommand(SEOPEN.wDeviceID, MCI_PLAY, 0, (DWORD)&SEPLAY);


					mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
					mop.lpstrDeviceType = L"WaveAudio";
					mop.lpstrElementName = L"res/Sound/stagebgm.wav";
					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
					mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);


					SceneChanger();
					eobj = std::make_shared< EnemyManager>(SceneNum);
					iobj = std::make_shared< ItemManager>(SceneNum);
					scrobj = std::make_shared< Scroll>(SceneNum);
					blobj = std::make_shared< Block>(SceneNum);
					paint_player_obj = std::make_shared<PAINT>();

					timeobj = std::make_shared<Timer>();
					timeobj->WindowsTimer(hdc);		//windows�̋N������̎��Ԃ̏K��
				}
			}
		}

	}
	else if (SceneNum < 0){
		
		Paint_BG(hdc,-SceneNum);
		sandstorm.Start(hdc);

		if (cc > 1){


			mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
			mop.lpstrDeviceType = L"WaveAudio";
			mop.lpstrElementName = L"res/Sound/stagebgm.wav";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
			mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

		

			SceneNum *= -1;	//�}�C�i�X�̒l�ɂȂ��Ă�SceneNum��߂�
			scrobj.reset();
			scrobj = std::make_shared< Scroll>(SceneNum);

			blobj.reset();
			blobj = std::make_shared< Block>(SceneNum);

			eobj.reset();
			eobj = std::make_shared< EnemyManager>(SceneNum);
			iobj.reset();
			iobj = std::make_shared< ItemManager>(SceneNum);
			
			eobj.reset();
			if (SceneNum == Stage1 || SceneNum == Stage2){
				eobj = std::make_shared< EnemyManager>(SceneNum);
			}
			bsobj.reset();
			if (SceneNum == Boss){
				bsobj = std::make_shared< BossManager>();
				bsAtkobj = std::make_shared<BossAtackManager>();

				mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
				mop.lpstrDeviceType = L"MPEGVideo";
				mop.lpstrElementName = L"res/Sound/bossbgm.mp3";
				mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
				mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);


			}

			iobj.reset();
			iobj = std::make_shared< ItemManager>(SceneNum);
			if (SceneNum == Stage2){
				paint_player_obj->obj2->player.x = 120;
				paint_player_obj->obj2->player.y = 420;
			}
			if (SceneNum == Boss){
				paint_player_obj->obj2->player.x = 150;
				paint_player_obj->obj2->player.y = 600;
			}			
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
		if (paint_player_obj->obj2->player.vx < -30)paint_player_obj->obj2->player.vx = -10;
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
	else if (SceneNum == Boss){

		paint_player_obj->obj2->C_sts(paint_player_obj->obj->c_sts, &paint_player_obj->obj->Oil_Gage);
		paint_player_obj->obj2->Move();

		//Scroll
		scrobj->toPoint(&paint_player_obj->obj2->player);
		scrobj->scroll_kansu(hdc);

		blobj->toPoint(&paint_player_obj->obj2->player);
		blobj->block_scroll(scrobj->Backimg_x, scrobj->Backimg_y);

		blobj->block_kansu(hdc);	//�l���󂯎���Ă����玟��


		bsobj->chara_strc(&paint_player_obj->obj2->player);
		bsobj->BOSS_SCROLL(scrobj->BackMoveX, scrobj->BackMoveY);
		bsobj->STAGE_COOD(blobj->get_block_X(), blobj->get_block_Y());
		int IsEnd = bsobj->MAIN(hdc);
		paint_player_obj->obj->Item(bsobj->GetDeadflag());
		bsobj->GetDeadflag(0);

		if (IsEnd == End){
			SceneNum = End;
			return 0;
		}
		
		bsAtkobj->chara_strc(&paint_player_obj->obj2->player);
		bsAtkobj->Atack_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
		bsAtkobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
		bsAtkobj->Main(hdc);
		paint_player_obj->obj->Item(bsAtkobj->GetDeadflag());
		bsAtkobj->GetDeadflag(0);
		

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
		return 0;

	}
	else if (SceneNum == End){
		Paint_BG(hdc,End);  //ed
		timeobj->ShowTime(hdc);//�^�C���`��
		flag2 = OFF;
		if (flag == ON){
			rankobj.Reading();
			rankobj.AddRanking(hWnd2);		//�����L���O�X�V
			flag = OFF;

			mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
			mop.lpstrDeviceType = L"WaveAudio";
			mop.lpstrElementName = L"res/Sound/stagebgm.wav";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
			mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);
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
				if (eobj){
					eobj.reset();
				}
				if (iobj){
					iobj.reset();
				}
				if (scrobj){
					scrobj.reset();
				}
				if (blobj){
					blobj.reset();
				}
				if (paint_player_obj){
					paint_player_obj.reset();
				}
				if (timeobj){
					timeobj.reset();
				}
				if (bsobj){
					bsobj.reset();
				}
				if (bsAtkobj){
					bsAtkobj.reset();
				}
			}
		}
		
	}
	cc++;
#ifdef _DEBUG_MODE


	DebugStringFloat("%2.2f", frr.GetFrameRate() / 10, hdc, 100, 50, 22);

#endif // _DEBUG_MODE

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
		if (flag3 == ON){
			if (SceneNum == Title){
				SceneNum = Stage1;
			}
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

