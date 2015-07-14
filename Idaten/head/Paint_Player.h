#pragma once
#pragma comment(lib,"msimg32.lib")
#include"player_info.h"
#include<Windows.h>


HBITMAP hb_Player;
HBITMAP hb_Walk_Right;
HBITMAP hb_Walk2_Right;
HBITMAP hb_Walk3_Right;
HBITMAP hb_Walk4_Right;
HBITMAP hb_Walk_Left;
HBITMAP hb_Walk2_Left;
HBITMAP hb_Walk3_Left;
HBITMAP hb_Walk4_Left;
HBITMAP hb_Tackl;
HBITMAP hb_Jump;
HBITMAP hb_Yarare;
HBITMAP hb_BG;//�r�b�g�}�b�v�n���h��(�w�i�p)

class PAINT{
		

public:
	player_info pla;
	~PAINT(){ DeleteObject(hb_Player); }

	

	int Paint_Player_H(HDC);//���ʏ�Ԃ̕`��
	int Paint_Walk1_H_Right(HDC);
	int Paint_Walk2_H_Right(HDC);
	int Paint_Walk3_H_Right(HDC);
	int Paint_Walk4_H_Right(HDC);
	int Paint_Walk1_H_Left(HDC);
	int Paint_Walk2_H_Left(HDC);
	int Paint_Walk3_H_Left(HDC);
	int Paint_Walk4_H_Left(HDC);
	int Paint_Jump_H(HDC);
	int Paint_Tackl_H(HDC);

	int Paint_Player_D(HDC);//�f�u��Ԃ̕`��
	int Paint_Walk1_D_Right(HDC);
	int Paint_Walk2_D_Right(HDC);
	int Paint_Walk3_D_Right(HDC);
	int Paint_Walk4_D_Right(HDC);
	int Paint_Walk1_D_Left(HDC);
	int Paint_Walk2_D_Left(HDC);
	int Paint_Walk3_D_Left(HDC);
	int Paint_Walk4_D_Left(HDC);
	int Paint_Jump_D(HDC);
	int Paint_Tackl_D(HDC);

	int Paint_Player_P(HDC);//�|�`����Ԃ̕`��
	int Paint_Walk1_P_Right(HDC);
	int Paint_Walk2_P_Right(HDC);
	int Paint_Walk3_P_Right(HDC);
	int Paint_Walk4_P_Right(HDC);
	int Paint_Walk1_P_Left(HDC);
	int Paint_Walk2_P_Left(HDC);
	int Paint_Walk3_P_Left(HDC);
	int Paint_Walk4_P_Left(HDC);
	int Paint_Jump_P(HDC);
	int Paint_Tackl_P(HDC);

	int Paint_Player_Y(HDC);//���Z��Ԃ̕`��
	int Paint_Walk1_Y_Right(HDC);
	int Paint_Walk2_Y_Right(HDC);
	int Paint_Walk4_Y_Right(HDC);
	int Paint_Walk3_Y_Right(HDC);
	int Paint_Walk1_Y_Left(HDC);
	int Paint_Walk2_Y_Left(HDC);
	int Paint_Walk3_Y_Left(HDC);
	int Paint_Walk4_Y_Left(HDC);
	int Paint_Jump_Y(HDC);
	int Paint_Tackl_Y(HDC);

	int Paint_Player_G(HDC);//�K����Ԃ̕`��
	int Paint_Walk1_G_Right(HDC);
	int Paint_Walk2_G_Right(HDC);
	int Paint_Walk3_G_Right(HDC);
	int Paint_Walk4_G_Right(HDC);
	int Paint_Walk1_G_Left(HDC);
	int Paint_Walk2_G_Left(HDC);
	int Paint_Walk3_G_Left(HDC);
	int Paint_Walk4_G_Left(HDC);
	int Paint_Jump_G(HDC);
	int Paint_Tackl_G(HDC);
	
	int Paint_Yarare(HDC);

	void char_strc(player_info *);


};
void PAINT::char_strc(player_info *p){
	pla = *p;
}




/************���ʏ��************************************************************/
int PAINT::Paint_Player_H(HDC hdc)
{
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Player);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_H_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_H_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_H_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_H_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_H_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_H_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_H_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_H_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_H(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Jump);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_H(HDC hdc){
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Tackl);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}
/********************************************************************************/

/***********************�f�u���*************************************************/
int PAINT::Paint_Player_D(HDC hdc)
{
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Player);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width + 20, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_D_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_D_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_D_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_D_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_D_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_D_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_D_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_D_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_D(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Jump);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width + 100, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_D(HDC hdc){
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Tackl);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/

/***********************�|�`�����************************************************/
int PAINT::Paint_Player_P(HDC hdc)
{
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Player);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_P_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_P_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_P_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_P_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_P_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_P_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_P_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_P_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_P(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Jump);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_P(HDC hdc){
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Tackl);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/


/***********************���Z���**************************************************/
int PAINT::Paint_Player_Y(HDC hdc)
{
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Player);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 160, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_Y_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_Y_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_Y_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_Y_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_Y_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_Y_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_Y_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_Y_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Y(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Jump);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_Y(HDC hdc){
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Tackl);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/


/***********************�K�����*************************************************/
int PAINT::Paint_Player_G(HDC hdc)
{
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Player);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_G_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_G_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_G_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_G_Right(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Right);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_G_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_G_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk2_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_G_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk3_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_G_Left(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Walk4_Left);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_G(HDC hdc){
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�������f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Jump);
	//�摜�]��
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_G(HDC hdc){
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_Tackl);
	// �摜��]������
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/

