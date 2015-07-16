#pragma once
#include <windows.h>

#pragma comment(lib,"msimg32.lib")
#include <math.h>	// atan2()���g�����߂ɕK�v
#include <time.h>   // time()���g���̂ɕK�v

#include "EnemyManager.h"
#include "ItemManager.h"
#include"scroll.h"
#include"Block.h"
#include"Option.h"
#include"timer.h"


//chara
#include"Player_Status.h"
#include "Paint_Player.h"
#include "Player_Move.h"



#include"player_info.h"


//�f�o�b�O
#include"debugmsg.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// �E�C���h�E�v���V�[�W���֐�

enum Scene{ Title, Stage1, End };
int SceneNum;

int Paint(HDC);
int Paint_BG(HDC);
int Init_Game();
int Get_Key();
int SceneChanger();

#define KEY_SPACE 32

HBITMAP title_hb;	// �r�b�g�}�b�v�n���h��
HBITMAP end_hb;	// �r�b�g�}�b�v�n���h��
HBITMAP player_hb;

BYTE key_input_buff;// �L�[�{�[�h���
BYTE key_buff[256];

HWND hWnd;







PAINT pl_paint_obj;

OIL *oilobj;
MOVE *pl_move_obj;
Scroll *scrobj;
Block *blobj;
EnemyManager *eobj;
ItemManager *iobj;
Timer *tobj;

/////���C���֐�///////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	MSG msg;

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

	// �E�C���h�E�̍쐬
	hWnd = CreateWindow(
		TEXT("Window01"), TEXT("STG ���@�̒e"),					// �E�C���h�E�̃^�C�g����
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,			// �E�C���h�E�X�^�C��
		CW_USEDEFAULT,												// �E�B���h�E�̕\��X���W
		CW_USEDEFAULT,												// �E�B���h�E�̕\��Y���W
		WINDOW_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,						// �E�B���h�E�̕�
		WINDOW_HEIGHT + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// ����
		NULL,														// �e�E�C���h�E
		NULL,														// �E�C���h�E���j���[
		hInstance,													// �C���X�^���X�n���h��
		NULL);														 // WM_CREATE���

	// �E�C���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);                         // �\����Ԃ̐ݒ�
	UpdateWindow(hWnd);                                 // �N���C�A���g�̈�̍X�V

	// ���b�Z�[�W���[�v
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
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


	case WM_USER + 1:	// �Q�[�����[�v�iSendMessage����Ă΂��j

		// ���ʂ̍ĕ`��@WM_PAINT�����s����
		InvalidateRect(hWnd, NULL, false);
		return 0;

	case WM_PAINT:	// ��ʂ�`�悷�鎞�̏���

		hdc = BeginPaint(hWnd, &ps);	// �`��̊J�n
		Paint(hdc_back);				// Paint�֐���

		//�o�b�N�o�b�t�@�ɕۑ����ꂽ�摜��\��ʂɕ`��
		BitBlt(hdc, 0, 0, 1100, 500, hdc_back, 0, 0, SRCCOPY);




		EndPaint(hWnd, &ps);			// �`��̏I��
		return 0;

	case WM_CREATE:


		Init_Game();

		// �`��̊J�n
		hdc = GetDC(hWnd);
		// �݊��f�o�C�X�R���e�L�X�g�̍쐬
		hdc_back = CreateCompatibleDC(hdc);
		// �݊��r�b�g�}�b�v�̍쐬
		hb_back = CreateCompatibleBitmap(hdc, 1100, 500);
		// �I�u�W�F�N�g�̑I��
		SelectObject(hdc_back, hb_back);
		// �`��̏I��
		ReleaseDC(hWnd, hdc);

		// �r�b�g�}�b�v�n���h���ɉ摜�f�[�^��ǂݍ��ݕۑ����Ă���
		//�V�[��
		title_hb = (HBITMAP)LoadImage(NULL, TEXT("title.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		end_hb = (HBITMAP)LoadImage(NULL, TEXT("end.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		player_hb = (HBITMAP)LoadImage(NULL, TEXT("player.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		//�L�����N�^�[
		hb_Stand00 = (HBITMAP)LoadImage(NULL, TEXT("stand_000.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand01 = (HBITMAP)LoadImage(NULL, TEXT("stand_001.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand02 = (HBITMAP)LoadImage(NULL, TEXT("stand_002.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand03 = (HBITMAP)LoadImage(NULL, TEXT("stand_003.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand04 = (HBITMAP)LoadImage(NULL, TEXT("stand_004.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand05 = (HBITMAP)LoadImage(NULL, TEXT("stand_005.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand06 = (HBITMAP)LoadImage(NULL, TEXT("stand_006.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand07 = (HBITMAP)LoadImage(NULL, TEXT("stand_007.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand08 = (HBITMAP)LoadImage(NULL, TEXT("stand_008.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Stand09 = (HBITMAP)LoadImage(NULL, TEXT("stand_009.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hb_Run00_Right = (HBITMAP)LoadImage(NULL, TEXT("run_000.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run01_Right = (HBITMAP)LoadImage(NULL, TEXT("run_001.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run02_Right = (HBITMAP)LoadImage(NULL, TEXT("run_002.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run03_Right = (HBITMAP)LoadImage(NULL, TEXT("run_003.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run04_Right = (HBITMAP)LoadImage(NULL, TEXT("run_004.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run05_Right = (HBITMAP)LoadImage(NULL, TEXT("run_005.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run06_Right = (HBITMAP)LoadImage(NULL, TEXT("run_006.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run07_Right = (HBITMAP)LoadImage(NULL, TEXT("run_007.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run08_Right = (HBITMAP)LoadImage(NULL, TEXT("run_008.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run09_Right = (HBITMAP)LoadImage(NULL, TEXT("run_009.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run10_Right = (HBITMAP)LoadImage(NULL, TEXT("run_010.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run11_Right = (HBITMAP)LoadImage(NULL, TEXT("run_011.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run12_Right = (HBITMAP)LoadImage(NULL, TEXT("run_012.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run13_Right = (HBITMAP)LoadImage(NULL, TEXT("run_013.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run14_Right = (HBITMAP)LoadImage(NULL, TEXT("run_014.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hb_Run00_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_000.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run01_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_001.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run02_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_002.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run03_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_003.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run04_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_004.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run05_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_005.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run06_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_006.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run07_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_007.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run08_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_008.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run09_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_009.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run10_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_010.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run11_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_011.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run12_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_012.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run13_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_013.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Run14_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_014.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			
		hb_Jump_Right = (HBITMAP)LoadImage(NULL, TEXT("run_007.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Jump_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_007.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hb_Tackle00 = (HBITMAP)LoadImage(NULL, TEXT("tackle_007.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	


		return 0;

	case WM_DESTROY:	// �Ō�ɃE�C���h�E������ꂽ���̏���
		// �f�o�C�X�R���e�L�X�g�̉��
		DeleteDC(hdc_back);
		// �I�u�W�F�N�g�̉�� 
		DeleteObject(hb_back);
		DeleteObject(title_hb);
		DeleteObject(end_hb);
		PostQuitMessage(0);
		return 0;

	default:	// �f�t�H���g����
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

int Init_Game(){


	SceneNum = Title;

	player.x = 100;
	player.y = 200;
	player.width = 30;
	player.height = 60;
	player.attack_x = 30;
	player.attack_mukou = 90;
	
	//�ȉ����
	player.c_flg = STAND;
	//�L�����N�^�[�A�j���[�V����
	a_flg = A_STAND1;
	a_cnt = 0;
	a_cnt2 = 0;
	//�^�b�N���̃t���O
	x = 0;
	grv = 1.1;


	return 0;
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
	static int cc;
	if (SceneNum == Title){
		Paint_BG(hdc);		// �w�i�`��֐���
		if (cc > 50){
			cc = Get_Key();
			if (cc == 1){
				SceneChanger();
				eobj = new(EnemyManager);
				iobj = new(ItemManager);
				scrobj = new(Scroll);
				blobj = new(Block);
				oilobj = new(OIL);
				pl_move_obj = new(MOVE);
				tobj = new(Timer);
				scrobj->Backimg_x = -(9  * CHIP_SIZE - 550);
				scrobj->Backimg_y = -(30 * CHIP_SIZE - 350);
				player.x = 240;
				player.y = 200;
			}
		}

	}
	else if (SceneNum == Stage1){
		
	pl_move_obj->C_sts(oilobj->c_sts, &oilobj->Oil_Gage);
	pl_move_obj->Move();

	//Scroll
	scrobj->toPoint(&player);
	scrobj->scroll_kansu(hdc);

	//Block
	blobj->toPoint(&player);
	blobj->block_scroll(scrobj->Backimg_x, scrobj->Backimg_y);
	int aa = blobj->block_kansu(hdc);
	if (aa == End){
		SceneNum = End;
		return 0;
	}

	//Enemy
	//-----------------------------
	eobj->chara_strc(&player);
	eobj->enemy_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
	eobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
	eobj->MainLoop(hdc);

	oilobj->Item(eobj->GetDeadflag());		//�A�C�e�����擾���ăQ�[�W�ɕω������邩���f����(�G�̏ꍇ�́|�P�����j

	eobj->GetDeadflag(0);

	//�I�C���Q�[�W�ʂȂǍX�V����
	oilobj->Player_Sts();
	oilobj->Oil_Sts();


	//Item
	iobj->chara_strc(&player);
	iobj->item_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
	iobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
	iobj->MainLoop(hdc);

	oilobj->Item(iobj->GetItemtype());		//�A�C�e�����擾���ăQ�[�W�ɕω������邩���f����
//	DebugStringVal("%d", iobj->GetItemtype(), hdc, 300, 30, 20);

	iobj->GetItemtype(0);	//�l�̏������B�@���Ȃ��ƃo�O���o�܂��O���O
	
	//�I�C���Q�[�W�ʂȂǍX�V����
	oilobj->Player_Sts();
	oilobj->Oil_Sts();


	//�I�C���Ƃ��̃Q�[�W�̕`��
	oilobj->Paint_Oil(hdc);
	oilobj->Paint_Gage(hdc);


	//�ړ��ʂ̍ő�l�̗}��
	if (player.vx < -10)player.vx = -10;
	if (player.vy > 10)	player.vy = 10;

	player.x += player.vx;
	player.y += player.vy;

	//�L��������ʍ��W�O���O�֏o�Ȃ��悤�ɗ}��
	if (player.x < 0)	player.x = 0;
	if (player.y < 0)	player.y = 0;

	//�ȉ��`�揈��

	//��ԕ���
	pl_paint_obj.char_strc(&player);
	if (oilobj->c_sts == HUTHU && a_flg == A_STAND1){
		pl_paint_obj.Paint_Stand00_H(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK1_Right){
		pl_paint_obj.Paint_Run00_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK2_Right){
		pl_paint_obj.Paint_Run01_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK3_Right){
		pl_paint_obj.Paint_Run02_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK4_Right){
		pl_paint_obj.Paint_Run03_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK5_Right){
		pl_paint_obj.Paint_Run04_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK6_Right){
		pl_paint_obj.Paint_Run05_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK7_Right){
		pl_paint_obj.Paint_Run06_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK8_Right){
		pl_paint_obj.Paint_Run07_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK9_Right){
		pl_paint_obj.Paint_Run08_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK10_Right){
		pl_paint_obj.Paint_Run09_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK11_Right){
		pl_paint_obj.Paint_Run10_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK12_Right){
		pl_paint_obj.Paint_Run11_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK13_Right){
		pl_paint_obj.Paint_Run12_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK14_Right){
		pl_paint_obj.Paint_Run13_H_Right(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK15_Right){
		pl_paint_obj.Paint_Run14_H_Right(hdc);
		player.width = 30;
	}

	if (oilobj->c_sts == HUTHU && a_flg == A_WALK1_Left){
		pl_paint_obj.Paint_Run00_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK2_Left){
		pl_paint_obj.Paint_Run01_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK3_Left){
		pl_paint_obj.Paint_Run02_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK4_Left){
		pl_paint_obj.Paint_Run03_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK5_Left){
		pl_paint_obj.Paint_Run04_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK6_Left){
		pl_paint_obj.Paint_Run05_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK7_Left){
		pl_paint_obj.Paint_Run06_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK8_Left){
		pl_paint_obj.Paint_Run07_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK9_Left){
		pl_paint_obj.Paint_Run08_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK10_Left){
		pl_paint_obj.Paint_Run09_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK11_Left){
		pl_paint_obj.Paint_Run10_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK12_Left){
		pl_paint_obj.Paint_Run11_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK13_Left){
		pl_paint_obj.Paint_Run12_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK14_Left){
		pl_paint_obj.Paint_Run13_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_WALK15_Left){
		pl_paint_obj.Paint_Run14_H_Left(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_JUMP){
		pl_paint_obj.Paint_Jump_Right_H(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_JUMP_Left){
		pl_paint_obj.Paint_Jump_Left_H(hdc);
		player.width = 30;
	}
	if (oilobj->c_sts == HUTHU && a_flg == A_TACKLE){
		pl_paint_obj.Paint_Tackle00_H(hdc);
		player.width = 30;
	}
	

	//��ԏd�����
	if (oilobj->c_sts == DEBU && a_flg == A_STAND1){
		pl_paint_obj.Paint_Stand00_D(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK1_Right){
		pl_paint_obj.Paint_Run00_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK2_Right){
		pl_paint_obj.Paint_Run01_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK3_Right){
		pl_paint_obj.Paint_Run02_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK4_Right){
		pl_paint_obj.Paint_Run03_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK5_Right){
		pl_paint_obj.Paint_Run04_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK6_Right){
		pl_paint_obj.Paint_Run05_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK7_Right){
		pl_paint_obj.Paint_Run06_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK8_Right){
		pl_paint_obj.Paint_Run07_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK9_Right){
		pl_paint_obj.Paint_Run08_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK10_Right){
		pl_paint_obj.Paint_Run09_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK11_Right){
		pl_paint_obj.Paint_Run10_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK12_Right){
		pl_paint_obj.Paint_Run11_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK13_Right){
		pl_paint_obj.Paint_Run12_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK14_Right){
		pl_paint_obj.Paint_Run13_D_Right(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK15_Right){
		pl_paint_obj.Paint_Run14_D_Right(hdc);
		player.width = 45;
	}

	if (oilobj->c_sts == DEBU && a_flg == A_WALK1_Left){
		pl_paint_obj.Paint_Run00_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK2_Left){
		pl_paint_obj.Paint_Run01_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK3_Left){
		pl_paint_obj.Paint_Run02_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK4_Left){
		pl_paint_obj.Paint_Run03_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK5_Left){
		pl_paint_obj.Paint_Run04_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK6_Left){
		pl_paint_obj.Paint_Run05_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK7_Left){
		pl_paint_obj.Paint_Run06_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK8_Left){
		pl_paint_obj.Paint_Run07_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK9_Left){
		pl_paint_obj.Paint_Run08_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK10_Left){
		pl_paint_obj.Paint_Run09_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK11_Left){
		pl_paint_obj.Paint_Run10_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK12_Left){
		pl_paint_obj.Paint_Run11_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK13_Left){
		pl_paint_obj.Paint_Run12_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK14_Left){
		pl_paint_obj.Paint_Run13_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_WALK15_Left){
		pl_paint_obj.Paint_Run14_D_Left(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_JUMP){
		pl_paint_obj.Paint_Jump_Right_D(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_JUMP_Left){
		pl_paint_obj.Paint_Jump_Left_D(hdc);
		player.width = 45;
	}
	if (oilobj->c_sts == DEBU && a_flg == A_TACKLE){
		pl_paint_obj.Paint_Tackle00_D(hdc);
		player.width = 45;
	}

	//��Ԓ��̏���
	if (oilobj->c_sts == POTYA && a_flg == A_STAND1){
		pl_paint_obj.Paint_Stand00_P(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK1_Right){
		pl_paint_obj.Paint_Run00_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK2_Right){
		pl_paint_obj.Paint_Run01_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK3_Right){
		pl_paint_obj.Paint_Run02_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK4_Right){
		pl_paint_obj.Paint_Run03_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK5_Right){
		pl_paint_obj.Paint_Run04_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK6_Right){
		pl_paint_obj.Paint_Run05_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK7_Right){
		pl_paint_obj.Paint_Run06_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK8_Right){
		pl_paint_obj.Paint_Run07_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK9_Right){
		pl_paint_obj.Paint_Run08_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK10_Right){
		pl_paint_obj.Paint_Run09_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK11_Right){
		pl_paint_obj.Paint_Run10_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK12_Right){
		pl_paint_obj.Paint_Run11_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK13_Right){
		pl_paint_obj.Paint_Run12_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK14_Right){
		pl_paint_obj.Paint_Run13_P_Right(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK15_Right){
		pl_paint_obj.Paint_Run14_P_Right(hdc);
		player.width = 38;
	}

	if (oilobj->c_sts == POTYA && a_flg == A_WALK1_Left){
		pl_paint_obj.Paint_Run00_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK2_Left){
		pl_paint_obj.Paint_Run01_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK3_Left){
		pl_paint_obj.Paint_Run02_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK4_Left){
		pl_paint_obj.Paint_Run03_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK5_Left){
		pl_paint_obj.Paint_Run04_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK6_Left){
		pl_paint_obj.Paint_Run05_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK7_Left){
		pl_paint_obj.Paint_Run06_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK8_Left){
		pl_paint_obj.Paint_Run07_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK9_Left){
		pl_paint_obj.Paint_Run08_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK10_Left){
		pl_paint_obj.Paint_Run09_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK11_Left){
		pl_paint_obj.Paint_Run10_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK12_Left){
		pl_paint_obj.Paint_Run11_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK13_Left){
		pl_paint_obj.Paint_Run12_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK14_Left){
		pl_paint_obj.Paint_Run13_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_WALK15_Left){
		pl_paint_obj.Paint_Run14_P_Left(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_JUMP){
		pl_paint_obj.Paint_Jump_Right_P(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_JUMP_Left){
		pl_paint_obj.Paint_Jump_Left_P(hdc);
		player.width = 38;
	}
	if (oilobj->c_sts == POTYA && a_flg == A_TACKLE){
		pl_paint_obj.Paint_Tackle00_P(hdc);
		player.width = 38;
	}

	//���̉����
	if (oilobj->c_sts == TYOIYASE && a_flg == A_STAND1){
		pl_paint_obj.Paint_Stand00_Y(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK1_Right){
		pl_paint_obj.Paint_Run00_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK2_Right){
		pl_paint_obj.Paint_Run01_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK3_Right){
		pl_paint_obj.Paint_Run02_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK4_Right){
		pl_paint_obj.Paint_Run03_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK5_Right){
		pl_paint_obj.Paint_Run04_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK6_Right){
		pl_paint_obj.Paint_Run05_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK7_Right){
		pl_paint_obj.Paint_Run06_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK8_Right){
		pl_paint_obj.Paint_Run07_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK9_Right){
		pl_paint_obj.Paint_Run08_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK10_Right){
		pl_paint_obj.Paint_Run09_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK11_Right){
		pl_paint_obj.Paint_Run10_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK12_Right){
		pl_paint_obj.Paint_Run11_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK13_Right){
		pl_paint_obj.Paint_Run12_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK14_Right){
		pl_paint_obj.Paint_Run13_Y_Right(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK15_Right){
		pl_paint_obj.Paint_Run14_Y_Right(hdc);
		player.width = 25;
	}

	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK1_Left){
		pl_paint_obj.Paint_Run00_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK2_Left){
		pl_paint_obj.Paint_Run01_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK3_Left){
		pl_paint_obj.Paint_Run02_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK4_Left){
		pl_paint_obj.Paint_Run03_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK5_Left){
		pl_paint_obj.Paint_Run04_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK6_Left){
		pl_paint_obj.Paint_Run05_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK7_Left){
		pl_paint_obj.Paint_Run06_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK8_Left){
		pl_paint_obj.Paint_Run07_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK9_Left){
		pl_paint_obj.Paint_Run08_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK10_Left){
		pl_paint_obj.Paint_Run09_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK11_Left){
		pl_paint_obj.Paint_Run10_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK12_Left){
		pl_paint_obj.Paint_Run11_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK13_Left){
		pl_paint_obj.Paint_Run12_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK14_Left){
		pl_paint_obj.Paint_Run13_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_WALK15_Left){
		pl_paint_obj.Paint_Run14_Y_Left(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_JUMP){
		pl_paint_obj.Paint_Jump_Right_Y(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_JUMP_Left){
		pl_paint_obj.Paint_Jump_Left_Y(hdc);
		player.width = 25;
	}
	if (oilobj->c_sts == TYOIYASE && a_flg == A_TACKLE){
		pl_paint_obj.Paint_Tackle00_Y(hdc);
		player.width = 25;
	}

	//��Ԍy�����
	if (oilobj->c_sts == GARI && a_flg == A_STAND1){
		pl_paint_obj.Paint_Stand00_G(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK1_Right){
		pl_paint_obj.Paint_Run00_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK2_Right){
		pl_paint_obj.Paint_Run01_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK3_Right){
		pl_paint_obj.Paint_Run02_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK4_Right){
		pl_paint_obj.Paint_Run03_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK5_Right){
		pl_paint_obj.Paint_Run04_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK6_Right){
		pl_paint_obj.Paint_Run05_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK7_Right){
		pl_paint_obj.Paint_Run06_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK8_Right){
		pl_paint_obj.Paint_Run07_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK9_Right){
		pl_paint_obj.Paint_Run08_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK10_Right){
		pl_paint_obj.Paint_Run09_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK11_Right){
		pl_paint_obj.Paint_Run10_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK12_Right){
		pl_paint_obj.Paint_Run11_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK13_Right){
		pl_paint_obj.Paint_Run12_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK14_Right){
		pl_paint_obj.Paint_Run13_G_Right(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK15_Right){
		pl_paint_obj.Paint_Run14_G_Right(hdc);
		player.width = 22;
	}

	if (oilobj->c_sts == GARI && a_flg == A_WALK1_Left){
		pl_paint_obj.Paint_Run00_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK2_Left){
		pl_paint_obj.Paint_Run01_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK3_Left){
		pl_paint_obj.Paint_Run02_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK4_Left){
		pl_paint_obj.Paint_Run03_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK5_Left){
		pl_paint_obj.Paint_Run04_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK6_Left){
		pl_paint_obj.Paint_Run05_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK7_Left){
		pl_paint_obj.Paint_Run06_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK8_Left){
		pl_paint_obj.Paint_Run07_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK9_Left){
		pl_paint_obj.Paint_Run08_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK10_Left){
		pl_paint_obj.Paint_Run09_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK11_Left){
		pl_paint_obj.Paint_Run10_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK12_Left){
		pl_paint_obj.Paint_Run11_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK13_Left){
		pl_paint_obj.Paint_Run12_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK14_Left){
		pl_paint_obj.Paint_Run13_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_WALK15_Left){
		pl_paint_obj.Paint_Run14_G_Left(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_JUMP){
		pl_paint_obj.Paint_Jump_Right_G(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_JUMP_Left){
		pl_paint_obj.Paint_Jump_Left_G(hdc);
		player.width = 22;
	}
	if (oilobj->c_sts == GARI && a_flg == A_TACKLE){
		pl_paint_obj.Paint_Tackle00_G(hdc);
		player.width = 22;
	}

	tobj->MainTimer(hdc);

	}
	else if (SceneNum == End){
		Paint_BG(hdc);
		if (cc > 50){
			cc = Get_Key();
			if (cc == 1){
				SceneChanger();
				delete eobj;
				delete iobj;
				delete scrobj;
				delete blobj;
				delete pl_move_obj;
				delete oilobj;
				delete tobj;
			}
		}
		
	}
	cc++;

	return 0;
}



///// �L�[���͊֐� ///////////////////////////////////////////////////////
int Get_Key()
{
	GetKeyboardState(key_buff);
	key_input_buff = 0;

	if (key_buff[VK_SPACE] & 0x80){
		key_input_buff |= KEY_SPACE;
		return 1;
	}

	return 50;
}

int Paint_BG(HDC hdc){
	HDC hdc_work;
	hdc_work = CreateCompatibleDC(hdc);
	if (SceneNum == Title){
		SelectObject(hdc_work, title_hb);		// �I�u�W�F�N�g�̑I��
		BitBlt(hdc, 0, 0, 1100, 350, hdc_work, 0, 0, SRCCOPY);
	}
	else if (SceneNum == End){
		SelectObject(hdc_work, end_hb);		// �I�u�W�F�N�g�̑I��
		BitBlt(hdc, 0, 0, 1100, 350, hdc_work, 0, 0, SRCCOPY);
	}


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

