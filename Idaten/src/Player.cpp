#pragma comment(lib,"msimg32.lib")
#include<windows.h>
#include"Player_Status.h"
#include "Paint_Player.h"
#include"player_info.h"
#include "Player_Move.h"
#include"scroll.h"
#include "ItemManager.h"
#include<memory>	//unique_ptr	�Ȃǂ��g�����߂ɕK�v



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//�E�B���h�E�v���V�[�W���֐�

int Paint(HDC);
int Init_Game();//�������֐�


PAINT Pobj;//�I�u�W�F�N�g�錾
OIL Oobj;
MOVE Mobj;
Scroll Sobj;


std::unique_ptr<ItemManager>iobj(new ItemManager);

//�o�b�N�o�b�t�@�p
static HDC hdc_back;
static HBITMAP hb_back;


/////�E�B���h�E�v���V�[�W���֐�//////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;//�y�C���g�\����

	switch (msg)
	{
	case WM_USER+1:
		Mobj.Move();
		
		InvalidateRect(hWnd, NULL, false);
		return 0;

	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);
		

		Paint(hdc_back);
		BitBlt(hdc, 0, 0, 1100, 450, hdc_back, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_CREATE:
		
		Init_Game();//�Q�[���������֐���
	

		// �`��̊J�n
		hdc = GetDC(hWnd);

		//������ �ǉ� (BackBuffer�̈�̍쐬)����������������������������
		// �݊��f�o�C�X�R���e�L�X�g�̍쐬
		hdc_back = CreateCompatibleDC(hdc);
		// �݊��r�b�g�}�b�v�̍쐬
		hb_back = CreateCompatibleBitmap(hdc, 1100, 450);
		// �I�u�W�F�N�g�̑I��
		SelectObject(hdc_back, hb_back);
		//����������������������������������������������������������������

		// �݊��f�o�C�X�R���e�L�X�g�̍쐬
		hdc = CreateCompatibleDC(NULL);
		// �`��̏I��
		ReleaseDC(hWnd, hdc);
		

		hb_Player = (HBITMAP)LoadImage(NULL, TEXT("Player.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk_Right = (HBITMAP)LoadImage(NULL, TEXT("run1_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk2_Right = (HBITMAP)LoadImage(NULL, TEXT("run2_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk3_Right = (HBITMAP)LoadImage(NULL, TEXT("run3_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk4_Right = (HBITMAP)LoadImage(NULL, TEXT("run4_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk_Left = (HBITMAP)LoadImage(NULL, TEXT("run1_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk2_Left = (HBITMAP)LoadImage(NULL, TEXT("run2_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk3_Left = (HBITMAP)LoadImage(NULL, TEXT("run3_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk4_Left = (HBITMAP)LoadImage(NULL, TEXT("run4_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Jump = (HBITMAP)LoadImage(NULL, TEXT("Jump.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Tackl = (HBITMAP)LoadImage(NULL, TEXT("Tackl.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		Oobj.hb_OilGage = (HBITMAP)LoadImage(NULL, TEXT("Oil.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		Oobj.hb_OilPower = (HBITMAP)LoadImage(NULL, TEXT("OilPower.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				
		return 0;

	case WM_DESTROY:
		//DeleteDC(hdc_back);
		//�I�u�W�F�N�g�̉��
		//DeleteObject(hb_back);
		
		DeleteObject(hb_Player);
		DeleteObject(hb_Walk_Right);
		DeleteObject(hb_Walk2_Right);
		DeleteObject(hb_Walk3_Right);
		DeleteObject(hb_Walk4_Right);
		DeleteObject(hb_Walk_Left);
		DeleteObject(hb_Walk2_Left);
		DeleteObject(hb_Walk3_Left);
		DeleteObject(hb_Walk4_Left);
		DeleteObject(hb_Jump);
		DeleteObject(hb_Tackl);
		DeleteObject(Oobj.hb_OilGage);
		DeleteObject(Oobj.hb_OilPower);


		PostQuitMessage(0);
		return 0;	
		
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
/////���C���`��/////////
int Paint(HDC hdc)
{
	
	Oobj.Player_Sts();
	Oobj.Oil_Sts();
	Mobj.C_sts(Oobj.c_sts,&Oobj.Oil_Gage);
	

	Sobj.toPoint(&player);
	Sobj.scroll_kansu(hdc);

	iobj->chara_strc(player);
	iobj->item_scroll(Sobj.BackMoveX, Sobj.BackMoveY);
	iobj->MainLoop(hdc);
	

	Oobj.Item(iobj->GetItemtype());
	iobj->GetItemtype(0);



	Oobj.Paint_Oil(hdc);
	Oobj.Paint_Gage(hdc);

	Pobj.char_strc(&player);
	if (Oobj.c_sts == HUTHU && a_flg == A_STAND){
		Pobj.Paint_Player_H(hdc);//���@�`��֐���
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_JUMP){
		Pobj.Paint_Jump_H(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_TACKL){
		Pobj.Paint_Tackl_H(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_H_Left(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_H_Left(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_H_Left(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_H_Left(hdc);
	}

	if (Oobj.c_sts == DEBU && a_flg == A_STAND){
		Pobj.Paint_Player_D(hdc);//���@�`��֐���
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_JUMP){
		Pobj.Paint_Jump_D(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_TACKL){
		Pobj.Paint_Tackl_D(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_D_Left(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_D_Left(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_D_Left(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_D_Left(hdc);
	}

	if (Oobj.c_sts == POTYA && a_flg == A_STAND){
		Pobj.Paint_Player_P(hdc);//���@�`��֐���
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_JUMP){
		Pobj.Paint_Jump_P(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_TACKL){
		Pobj.Paint_Tackl_P(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_P_Left(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_P_Left(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_P_Left(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_P_Left(hdc);
	}

	if (Oobj.c_sts == TYOIYASE && a_flg == A_STAND){
		Pobj.Paint_Player_Y(hdc);//���@�`��֐���
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_JUMP){
		Pobj.Paint_Jump_Y(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_TACKL){
		Pobj.Paint_Tackl_Y(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_Y_Left(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_Y_Left(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_Y_Left(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_Y_Left(hdc);
	}

	if (Oobj.c_sts == GARI && a_flg == A_STAND){
		Pobj.Paint_Player_G(hdc);//���@�`��֐���
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_JUMP){
		Pobj.Paint_Jump_G(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_TACKL){
		Pobj.Paint_Tackl_G(hdc);
	}

	return 0;
}




/////�������֐�//////////
int Init_Game()
{
	player.x = 100;
	player.y = 200;
	player.width = 100;
	player.height = 100;
	player.attack_x = 30;
	player.attack_mukou = 90;

	x = 0;
	grv = 1;
	player.c_flg = STAND;
	a_flg = A_STAND;
	a_cnt = 0;
	return 0;
}


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
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);       // �E�B���h�E��ʂ̐F
	wc.lpszMenuName = NULL;                            // �E�C���h�E���j���[�i�g�p���Ȃ��j
	wc.lpszClassName = TEXT("Window01");                // �E�C���h�E�N���X��

	// �E�C���h�E�N���X�̓o�^
	if (!RegisterClass(&wc))return FALSE;

	// �E�C���h�E�̍쐬
	HWND hWnd = CreateWindow(
		TEXT("Window01"), TEXT("char"),					// �E�C���h�E�̃^�C�g����
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,			// �E�C���h�E�X�^�C��
		CW_USEDEFAULT,												// �E�B���h�E�̕\��X���W
		CW_USEDEFAULT,												// �E�B���h�E�̕\��Y���W
		1100 + GetSystemMetrics(SM_CXDLGFRAME) * 2,						// �E�B���h�E�̕�
		450 + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// ����
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
