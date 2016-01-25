#pragma once
#include"Player_Move.h"




/////�ړ��֐�//////////////
int MOVE::Move()
{
	switch (c_sts)//�L�����̃X�e�[�^�X�ł��ꂼ��̑̌^�̈ړ����Ǘ�
	{
	case DEBU:

		Move_DEBU();
		break;

	case POTYA:

		Move_POTYA();
		break;

	case HUTHU:

		Move_HUTHU();
		break;

	case TYOIYASE:

		Move_TYOIYASE();
		break;

	case GARI:

		Move_GARI();
		break;
	}

	return 0;
}

/////�̌^�ʈړ�//////////////
int MOVE::Move_DEBU()
{

	player.vy += grv;//�d�͂�^����
	player.vx *= 0.8;
	/******����********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******�^�b�N����*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
			
			mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
			mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);

		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -6;
		a_flg = A_WALK14_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 6;
		a_flg = A_WALK14_Right;
		a_cnt++;
		houkou = 1;
	}

	//�E�̃A�j���[�V����

	if (a_flg == A_WALK14_Right && a_cnt >= 7){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 9){

		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 11){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 13){
		a_flg = A_WALK12_Right;
	}
	if (a_flg == A_WALK12_Right && a_cnt >= 15){
		a_flg = A_WALK14_Right;
		a_cnt = 0;
	}



	//���̃A�j���[�V����
	if (a_flg == A_WALK14_Left && a_cnt >= 7){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 9){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 11){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 13){
		a_flg = A_WALK12_Left;
	}
	if (a_flg == A_WALK12_Left && a_cnt >= 15){
		a_flg = A_WALK14_Left;
		a_cnt = 0;
	}

	//a_flg��A_STAND�ɖ߂�����

	if (a_flg <= 16){
		if (player.vx <= 1 && player.vx >= -1){
			if (houkou == 1){
				a_flg = A_STAND1;
			}
			else if (houkou == 0){
				a_flg = A_STAND1_Left;
			}

		}
	}
	/*****************************************/

	/******�W�����v(����)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 12;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******�W�����v(��)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -6;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 6;
			houkou = 1;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		
	}
	/*****************************************/

	/******�^�b�N��***************************/
	if (x == 1){ //X�L�[�������ꂽ��
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //�l�̃Z�b�g	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}

	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		if (houkou == 0){
			player.vx -= player.attack_x + 10;
		}
		if (houkou == 1){
			player.vx += player.attack_x;
		}


		player.attack_mukou -= 5;//����X�L�[�̓��͑҂�����
		player.attack_x -= 5;	//�^�b�N���̌����l

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//X�L�[�̍ē��͂��\
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}

		if (houkou == 1)a_flg = A_TACKLE;
		if (houkou == 0)a_flg = A_TACKLE_Left;
	}

	/****************************************/

	return 0;
}

int MOVE::Move_POTYA()
{
	player.vy += grv;//�d�͂�^����
	player.vx *= 0.8;
	/******����********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******�^�b�N����*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
			mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
			mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);

		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -8;
		a_flg = A_WALK14_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 8;
		a_flg = A_WALK14_Right;
		a_cnt++;
		houkou = 1;
	}

	//�E�̃A�j���[�V����

	if (a_flg == A_WALK14_Right && a_cnt >= 7){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 9){

		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 11){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 13){
		a_flg = A_WALK12_Right;
	}
	if (a_flg == A_WALK12_Right && a_cnt >= 15){
		a_flg = A_WALK14_Right;
		a_cnt = 0;
	}



	//���̃A�j���[�V����
	if (a_flg == A_WALK14_Left && a_cnt >= 7){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 9){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 11){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 13){
		a_flg = A_WALK12_Left;
	}
	if (a_flg == A_WALK12_Left && a_cnt >= 15){
		a_flg = A_WALK14_Left;
		a_cnt = 0;
	}

	//a_flg��A_STAND�ɖ߂�����

	if (a_flg <= 16){
		if (player.vx <= 1 && player.vx >= -1){
			if (houkou == 1){
				a_flg = A_STAND1;
			}
			else{
				a_flg = A_STAND1_Left;
			}

		}
	}
	/*****************************************/

	/******�W�����v(����)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 14;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******�W�����v(��)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -8;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 8;
			houkou = 1;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		
	}
	/*****************************************/

	/******�^�b�N��***************************/
	if (x == 1){      //X�L�[�������ꂽ��
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //�l�̃Z�b�g	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}
	/******�^�b�N��***************************/
	if (x == 1){ //X�L�[�������ꂽ��
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //�l�̃Z�b�g	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}

	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		if (houkou == 0){
			player.vx -= player.attack_x + 10;
		}
		if (houkou == 1){
			player.vx += player.attack_x;
		}


		player.attack_mukou -= 5;//����X�L�[�̓��͑҂�����
		player.attack_x -= 5;	//�^�b�N���̌����l

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//X�L�[�̍ē��͂��\
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}

		if (houkou == 1)a_flg = A_TACKLE;
		if (houkou == 0)a_flg = A_TACKLE_Left;
	}

	/****************************************/


	//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK3_Right && a_flg != A_WALK3_Left && a_flg != A_WALK5_Right && a_flg != A_WALK5_Left
		&& a_flg != A_WALK8_Right && a_flg != A_WALK8_Left && a_flg != A_WALK12_Right && a_flg != A_WALK12_Left && a_flg != A_WALK14_Right && a_flg != A_WALK14_Left){
		a_cnt2 = 0;
	}

	return 0;
}

int MOVE::Move_HUTHU()
{
	player.vy += grv;//�d�͂�^����
	player.vx *= 0.8;
	/******����********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******�^�b�N����*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
			mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
			mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);

		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -10;
		a_flg = A_WALK14_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 10;
		a_flg = A_WALK14_Right;
		a_cnt++;
		houkou = 1;
	}

	//�E�̃A�j���[�V����

	if (a_flg == A_WALK14_Right && a_cnt >= 7){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 9){

		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 11){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 13){
		a_flg = A_WALK12_Right;
	}
	if (a_flg == A_WALK12_Right && a_cnt >= 15){
		a_flg = A_WALK14_Right;
		a_cnt = 0;
	}
	


	//���̃A�j���[�V����
	if (a_flg == A_WALK14_Left && a_cnt >= 7){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 9){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 11){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 13){
		a_flg = A_WALK12_Left;
	}
	if (a_flg == A_WALK12_Left && a_cnt >= 15){
		a_flg = A_WALK14_Left;
		a_cnt = 0;
	}


	//a_flg��A_STAND�ɖ߂�����
	if (a_flg <= 16){
		if (player.vx <= 1 && player.vx >= -1){
			if (houkou == 1){
				a_flg = A_STAND1;
			}
			else if(houkou == 0){
				a_flg = A_STAND1_Left;
			}

		}
	}


	//}
	/*****************************************/

	/******�W�����v(����)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 16;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******�W�����v(��)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -10;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 10;
			houkou = 1;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
	

		
	}
	/*****************************************/

	/******�^�b�N��***************************/
	if (x == 1){ //X�L�[�������ꂽ��
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //�l�̃Z�b�g	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}

	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		if (houkou == 0){
			player.vx -= player.attack_x;
		}
		if (houkou == 1){
			player.vx += player.attack_x;
		}


		player.attack_mukou -= 5;//����X�L�[�̓��͑҂�����
		player.attack_x -= 5;	//�^�b�N���̌����l

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//X�L�[�̍ē��͂��\
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}

		if (houkou == 1)a_flg = A_TACKLE;
		if (houkou == 0)a_flg = A_TACKLE_Left;
	}

	/****************************************/

	//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK3_Right && a_flg != A_WALK3_Left && a_flg != A_WALK5_Right && a_flg != A_WALK5_Left
		&& a_flg != A_WALK8_Right && a_flg != A_WALK8_Left && a_flg != A_WALK12_Right && a_flg != A_WALK12_Left && a_flg != A_WALK14_Right && a_flg != A_WALK14_Left){
		a_cnt2 = 0;
	}

	return 0;
}

int MOVE::Move_TYOIYASE()
{
	player.vy += grv;//�d�͂�^����
	player.vx *= 0.8;
	/******����********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******�^�b�N����*************************/
	if (x != 1){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;
			mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
			mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);

		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -12;
		a_flg = A_WALK14_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 12;
		a_flg = A_WALK14_Right;
		a_cnt++;
		houkou = 1;
	}

	//�E�̃A�j���[�V����

	if (a_flg == A_WALK14_Right && a_cnt >= 7){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 9){

		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 11){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 13){
		a_flg = A_WALK12_Right;
	}
	if (a_flg == A_WALK12_Right && a_cnt >= 15){
		a_flg = A_WALK14_Right;
		a_cnt = 0;
	}



	//���̃A�j���[�V����
	if (a_flg == A_WALK14_Left && a_cnt >= 7){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 9){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 11){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 13){
		a_flg = A_WALK12_Left;
	}
	if (a_flg == A_WALK12_Left && a_cnt >= 15){
		a_flg = A_WALK14_Left;
		a_cnt = 0;
	}


	//a_flg��A_STAND�ɖ߂�����
	if (a_flg <= 16){
		if (player.vx <= 1 && player.vx >= -1){
			if (houkou == 1){
				a_flg = A_STAND1;
				houkou = 1;
			}
			else if (houkou == 0){
				a_flg = A_STAND1_Left;
				houkou = 0;
			}

		}
	}


	//}
	/*****************************************/

	/******�W�����v(����)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 18;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******�W�����v(��)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -12;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 12;
			houkou = 1;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		


	}
	/*****************************************/

	/******�^�b�N��***************************/
	if (x == 1){ //X�L�[�������ꂽ��
	    player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //�l�̃Z�b�g	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}

	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		if (houkou == 0){
			player.vx -= player.attack_x;
		}
		if (houkou == 1){
			player.vx += player.attack_x;
		}
		
		
		player.attack_mukou -= 5;//����X�L�[�̓��͑҂�����
		player.attack_x -= 5;	//�^�b�N���̌����l

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//X�L�[�̍ē��͂��\
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}

		if(houkou == 1)a_flg = A_TACKLE;
		if (houkou == 0)a_flg = A_TACKLE_Left;
	}

	/****************************************/
	

	//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK3_Right && a_flg != A_WALK3_Left && a_flg != A_WALK5_Right && a_flg != A_WALK5_Left
		&& a_flg != A_WALK8_Right && a_flg != A_WALK8_Left && a_flg != A_WALK12_Right && a_flg != A_WALK12_Left && a_flg != A_WALK14_Right && a_flg != A_WALK14_Left){
		a_cnt2 = 0;
	}
	return 0;
}

int MOVE::Move_GARI()
{
	player.vy += grv;//�d�͂�^����
	player.vx *= 0.8;

	/******����********************************/
	if (player.c_flg == STAND){
		if (GetKeyState('C') & 0x8000){
			player.c_flg = JUMP;
		}
	}
	/*****************************************/

	/******�^�b�N����*************************/
	if (x != 1 && *Oil != 0){
		if (GetKeyState('X') & 0x8000){
			x = 1;
			*Oil -= 1;

			mciSendCommand(se_open.wDeviceID, MCI_CLOSE, 0, 0);
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&se_open);
			mciSendCommand(se_open.wDeviceID, MCI_PLAY, 0, (DWORD)&se_playDevice);

		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -14;
		a_flg = A_WALK14_Left;
		a_cnt++;
		houkou = 0;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 14;
		a_flg = A_WALK14_Right;
		a_cnt++;
		houkou = 1;
	}

	//�E�̃A�j���[�V����

	if (a_flg == A_WALK14_Right && a_cnt >= 7){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 9){

		a_flg = A_WALK5_Right;
	}
	if (a_flg == A_WALK5_Right && a_cnt >= 11){
		a_flg = A_WALK8_Right;
	}
	if (a_flg == A_WALK8_Right && a_cnt >= 13){
		a_flg = A_WALK12_Right;
	}
	if (a_flg == A_WALK12_Right && a_cnt >= 15){
		a_flg = A_WALK14_Right;
		a_cnt = 0;
	}



	//���̃A�j���[�V����
	if (a_flg == A_WALK14_Left && a_cnt >= 7){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 9){
		a_flg = A_WALK5_Left;
	}
	if (a_flg == A_WALK5_Left && a_cnt >= 11){
		a_flg = A_WALK8_Left;
	}
	if (a_flg == A_WALK8_Left && a_cnt >= 13){
		a_flg = A_WALK12_Left;
	}
	if (a_flg == A_WALK12_Left && a_cnt >= 15){
		a_flg = A_WALK14_Left;
		a_cnt = 0;
	}


	//a_flg��A_STAND�ɖ߂�����
	if (a_flg <= 16){
		if (player.vx <= 1 && player.vx >= -1){
			if (houkou == 1){
				a_flg = A_STAND1;
			}
			else if(houkou == 0){
				a_flg = A_STAND1_Left;
			}

		}
	}

	/*****************************************/

	/******�W�����v(����)*********************/
	if (player.c_flg == JUMP){
		player.jump_power = 22;
		player.vy = -player.jump_power;
		player.c_flg = JUMPDOWN;
	}
	/*****************************************/

	/******�W�����v(��)*********************/
	if (player.c_flg == JUMPDOWN){
		player.jump_power = 0;
		if (GetKeyState(VK_LEFT) & 0x8000){
			player.vx = -14;
			houkou = 0;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 14;
			houkou = 1;
		}
		if (houkou == 0){
			a_flg = A_JUMP_Left;
		}
		if (houkou == 1){
			a_flg = A_JUMP;
		}
		
	}
	/*****************************************/

	/******�^�b�N��***************************/
	if (x == 1){ //X�L�[�������ꂽ��
		player.c_flg = TACKLE;
	}
	if (player.c_flg == TACKLE){ //�l�̃Z�b�g	
		player.vy = 0;
		player.c_flg = TACKLE_STOP;
	}

	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		if (houkou == 0){
			player.vx -= player.attack_x + 10;
		}
		if (houkou == 1){
			player.vx += player.attack_x;
		}


		player.attack_mukou -= 5;//����X�L�[�̓��͑҂�����
		player.attack_x -= 5;	//�^�b�N���̌����l

		if (player.attack_x <= 0){
			player.attack_x = 0;
		}
		if (player.attack_mukou <= 0){//X�L�[�̍ē��͂��\
			player.attack_x = 30;
			player.attack_mukou = 90;
			player.vx = 0;
			x = 0;
			player.c_flg = STAND;
		}

		if (houkou == 1)a_flg = A_TACKLE;
		if (houkou == 0)a_flg = A_TACKLE_Left;
	}

	/****************************************/


	//�}�b�v�̃u���b�N�̏�ӂɐڐG������

	//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK3_Right && a_flg != A_WALK3_Left && a_flg != A_WALK5_Right && a_flg != A_WALK5_Left
		&& a_flg != A_WALK8_Right && a_flg != A_WALK8_Left && a_flg != A_WALK12_Right && a_flg != A_WALK12_Left && a_flg != A_WALK14_Right && a_flg != A_WALK14_Left){
		a_cnt2 = 0;
	}

	return 0;
}


void MOVE::C_sts(int a, int *b){
	c_sts = a;
	Oil = b;
}