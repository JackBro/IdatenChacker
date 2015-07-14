#pragma once
#include<Windows.h>
#include"player_info.h"
#include "block_info.h"
#include<memory>
#include"debugmsg.h"
#include"Option.h"



/******���ꂼ��̃u���b�N�̎�ނ��`���Ă�u���b�N�N���X*********
*�����ƌ����΂��̑��r�b�g�}�b�v���S�������Œ�`���Ă��܂��Ă�����*
*                                                                *
*         ����Ӗ�����class�̓r�b�g�}�b�v�n���h���錾�N���X      *
*****************************************************************/

class Block{
	HDC blockhdc;
	//���Ƃ��ǂɎg���u���b�N
	BYTE key_buff[256];
	HBITMAP hb_block = (HBITMAP)LoadImage(NULL, TEXT("sozai01.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// �r�b�g�}�b�v�n���h��
		//�j��ł���u���b�N
	HBITMAP hc_block = (HBITMAP)LoadImage(NULL, TEXT("sozai02.bmp"), IMAGE_BITMAP,
	0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// �r�b�g�}�b�v�n���h��
	     
	//�S�[���e�[�v
	HBITMAP gorl = (HBITMAP)LoadImage(NULL, TEXT("Sikaku.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// �r�b�g�}�b�v�n���h��
	//�t���b�O�i�X�^�[�g�n�_�j
	HBITMAP flag = (HBITMAP)LoadImage(NULL, TEXT("flag.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// �r�b�g�}�b�v�n���h��

	char MAPDATA[MAP_HEIGHT][MAP_WIDTH];
	
	float MapDrawPointX, MapDrawPointY;		// �`�悷��}�b�v���W�l
	float DrawMapChipX, DrawMapChipY;	// �`�悷��}�b�v�`�b�v�̐�

public:
	int Hit_Check(HDC);
	int Init_block();

	block_info block;  //block_info�^�̍\����   :�u���b�N�쐬�p�I�u�W�F�N�g


	Block(){
		Init_block();
		
	};

	int block_scroll(int, int);

	~Block(){
		DeleteObject(hb_block);
		DeleteObject(hc_block);
		DeleteObject(gorl);
	

	}
	player_info *plstats;
	float block_kansu(HDC);
	void CharMove();
	Block(BYTE * key){
		key_buff[0] = *key;
	}
	void toPoint(player_info *st);
	int BackMoveX, BackMoveY;		//�X�N���[��

	//�u���b�N�i�X�e�[�W�̍��W���擾�j
	int get_block_X();
	int get_block_Y();
	    
};


