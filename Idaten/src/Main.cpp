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
//#include"Player_Status.h"
#include "Paint_Player.h"
//#include "Player_Move.h"



#include"player_info.h"


//�f�o�b�O
#include"debugmsg.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// �E�C���h�E�v���V�[�W���֐�


int SceneNum;

int Paint(HDC);
int Paint_BG(HDC,int);
int Init_Game();
int Get_Key(int);
int SceneChanger();

#define KEY_SPACE 32

//HBITMAP title_hb;	// �r�b�g�}�b�v�n���h��
//HBITMAP end_hb;	// �r�b�g�}�b�v�n���h��
HBITMAP menu_hb[5];	//�^�C�g����N���A���

BYTE key_input_buff;// �L�[�{�[�h���
BYTE key_buff[256];

HWND hWnd;







PAINT *paint_player_obj;


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
		TEXT("Window01"), TEXT("�C�_�e���E�`���b�J�["),					// �E�C���h�E�̃^�C�g����
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
		BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_back, 0, 0, SRCCOPY);




		EndPaint(hWnd, &ps);			// �`��̏I��
		return 0;

	case WM_CREATE:


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

		// �r�b�g�}�b�v�n���h���ɉ摜�f�[�^��ǂݍ��ݕۑ����Ă���
		//�V�[���pBITMAP
		menu_hb[Title] = (HBITMAP)LoadImage(NULL, TEXT("title.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		menu_hb[End] = (HBITMAP)LoadImage(NULL, TEXT("end.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		menu_hb[Stage2] = (HBITMAP)LoadImage(NULL, TEXT("waitScene.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		menu_hb[Boss] = (HBITMAP)LoadImage(NULL, TEXT("waitScene.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		/*
		title_hb = (HBITMAP)LoadImage(NULL, TEXT("title.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		end_hb = (HBITMAP)LoadImage(NULL, TEXT("end.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		*/	
	


		return 0;

	case WM_DESTROY:	// �Ō�ɃE�C���h�E������ꂽ���̏���
		// �f�o�C�X�R���e�L�X�g�̉��
		DeleteDC(hdc_back);
		// �I�u�W�F�N�g�̉�� 
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
		Paint_BG(hdc,Title);		// �w�i�`��֐���
		if (cc > 50){
			cc = Get_Key(cc);
			if (cc == 1){
				SceneChanger();
				eobj = new(EnemyManager);
				iobj = new(ItemManager);
				scrobj = new(Scroll);
				blobj = new(Block);
				paint_player_obj = new(PAINT);
				//oilobj = new(OIL);
				//paint_player_obj->obj2 = new(MOVE);
				
				tobj = new(Timer);
				scrobj->Backimg_x = 0;
				scrobj->Backimg_y = -(30 * CHIP_SIZE - 350);
			
			}
		}

	}
	else if (SceneNum < 0){
		
		Paint_BG(hdc,-SceneNum);
	

		if (cc > 5){	
			SceneNum *= -1;	//�}�C�i�X�̒l�ɂȂ��Ă�SceneNum��߂�
			delete scrobj;
			scrobj = new Scroll(SceneNum);

			delete blobj;
			blobj = new(Block);
			
			delete eobj;
			eobj = new(EnemyManager);
			
			delete iobj;
			iobj = new(ItemManager);

			scrobj->Backimg_x = 0;
			scrobj->Backimg_y = 0;
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
		DebugStringVal("%d", SceneNum, hdc, 200, 200, 20);

		return 0;

	}


	//Enemy
	//-----------------------------
	eobj->chara_strc(&paint_player_obj->obj2->player);
	eobj->enemy_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
	eobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
	eobj->MainLoop(hdc);

	paint_player_obj->obj->Item(eobj->GetDeadflag());		//�A�C�e�����擾���ăQ�[�W�ɕω������邩���f����(�G�̏ꍇ�́|�P�����j

	eobj->GetDeadflag(0);

	//�I�C���Q�[�W�ʂȂǍX�V����
	paint_player_obj->obj->Player_Sts();
	paint_player_obj->obj->Oil_Sts();


	//Item
	iobj->chara_strc(&paint_player_obj->obj2->player);
	iobj->item_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
	iobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
	iobj->MainLoop(hdc);

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

	tobj->MainTimer(hdc);

	}
	else if (SceneNum == Boss) {
		if (cc > 10) {
			SceneNum = End;
			cc = 0;
		}
	}
	else if (SceneNum == End){
		Paint_BG(hdc,End);
		if (cc > 50){
			cc = Get_Key(cc);
			if (cc == 1){
				SceneChanger();
				delete eobj;
				delete iobj;
				delete scrobj;
				delete blobj;
				delete paint_player_obj;
				delete tobj;
			}
		}
		
	}
	cc++;
	DebugStringVal("%d", SceneNum, hdc, 20 * SceneNum + 200, 200, 20);
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

