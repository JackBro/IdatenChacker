#pragma once
#include <Windows.h>
#include"player_info.h"
#include"Player_Status.h"

#include"debugmsg.h"


int a_flg;//�A�j���[�V�����t���O
int a_cnt;//�A�j���[�V�����J�E���g
int x;	//�^�b�N���̃t���O(�O�F�����iOFF�j�P�F�L���iON�j
int grv;  //�d��

int STAND = 0;
int WALK = 1;
int TACKLE = 2;
int TACKLE_STOP = 3;
int JUMP = 4;
int JUMPDOWN = 5;

player_info player;

//�A�j���[�V�����p
#define A_WALK1_Right  0
#define A_WALK2_Right  1
#define A_WALK3_Right  2
#define A_WALK4_Right  3
#define A_WALK1_Left   4
#define A_WALK2_Left   5
#define A_WALK3_Left   6
#define A_WALK4_Left   7
#define A_JUMP         8
#define A_TACKL        9
#define A_STAND       10


class MOVE{
	int c_sts;
	int *Oil;

	////�̌^�ʈړ��֐�
	int Move_DEBU();
	int Move_POTYA();
	int Move_HUTHU();
	int Move_TYOIYASE();
	int Move_GARI();

public:
	int Move();//���C���ړ��֐�
	void C_sts(int,int*);//c_sts,Oil_Gage
};

/////�ړ��֐�//////////////
int MOVE:: Move()
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
		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -6;
		a_flg = A_WALK1_Left;
		a_cnt++;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 6;
		a_flg = A_WALK1_Right;
		a_cnt++;
	}

	//�E�̃A�j���[�V����
	if (a_flg == A_WALK1_Right && a_cnt >= 10){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 20){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 30){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 20){
		a_flg = A_WALK1_Right;
		a_cnt = 0;
	}

	//���̃A�j���[�V����
	if (a_flg == A_WALK1_Left && a_cnt >= 10){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 20){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 30){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 20){
		a_flg = A_WALK1_Left;
		a_cnt = 0;
	}

	//a_flg��A_STAND�ɖ߂�����
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left){
		if (player.vx <= 1 && player.vx >= -1)
		{
			a_flg = A_STAND;
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
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 6;
		}
		a_flg = A_JUMP;
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
	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
		player.attack_mukou -= 3;//����X�L�[�̓��͑҂�����
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


		a_flg = A_TACKL;
	}
	/****************************************/


	//�}�b�v�̃u���b�N�̏�ӂɐڐG������
	
		//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_TACKL){
			a_flg = A_STAND;
		}
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
		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -8;
		a_flg = A_WALK1_Left;
		a_cnt++;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 8;
		a_flg = A_WALK1_Right;
		a_cnt++;
	}

	//�E�̃A�j���[�V����
	if (a_flg == A_WALK1_Right && a_cnt >= 10){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 20){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 30){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 20){
		a_flg = A_WALK1_Right;
		a_cnt = 0;
	}

	//���̃A�j���[�V����
	if (a_flg == A_WALK1_Left && a_cnt >= 10){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 20){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 30){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 20){
		a_flg = A_WALK1_Left;
		a_cnt = 0;
	}

	//a_flg��A_STAND�ɖ߂�����
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left){
		if (player.vx <= 1 && player.vx >= -1)
		{
			a_flg = A_STAND;
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
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 8;
		}
		a_flg = A_JUMP;
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
	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
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


		a_flg = A_TACKL;
	}
	/****************************************/


		//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_TACKL){
			a_flg = A_STAND;
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
		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -10;
		a_flg = A_WALK1_Left;
		a_cnt++;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 10;
		a_flg = A_WALK1_Right;
		a_cnt++;
	}

	//�E�̃A�j���[�V����
	if (a_flg == A_WALK1_Right && a_cnt >= 10){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 20){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 30){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 20){
		a_flg = A_WALK1_Right;
		a_cnt = 0;
	}

	//���̃A�j���[�V����
	if (a_flg == A_WALK1_Left && a_cnt >= 10){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 20){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 30){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 20){
		a_flg = A_WALK1_Left;
		a_cnt = 0;
	}

	//a_flg��A_STAND�ɖ߂�����
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left){
		if (player.vx <= 1 && player.vx >= -1)
		{
			a_flg = A_STAND;
		}
	}
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
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 10;
		}
		a_flg = A_JUMP;
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
	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
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


		a_flg = A_TACKL;
	}
	/****************************************/


	//�}�b�v�̃u���b�N�̏�ӂɐڐG������
	
		//���ړ���A_STAND�̕`�������
		if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_TACKL){
			a_flg = A_STAND;
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
		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -12;
		a_flg = A_WALK1_Left;
		a_cnt++;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 12;
		a_flg = A_WALK1_Right;
		a_cnt++;
	}

	//�E�̃A�j���[�V����
	if (a_flg == A_WALK1_Right && a_cnt >= 10){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 20){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 30){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 20){
		a_flg = A_WALK1_Right;
		a_cnt = 0;
	}

	//���̃A�j���[�V����
	if (a_flg == A_WALK1_Left && a_cnt >= 10){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 20){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 30){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 20){
		a_flg = A_WALK1_Left;
		a_cnt = 0;
	}

	//a_flg��A_STAND�ɖ߂�����
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left){
		if (player.vx <= 1 && player.vx >= -1)
		{
			a_flg = A_STAND;
		}
	}
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
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 12;
		}
		a_flg = A_JUMP;
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
	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
				player.vx += player.attack_x;
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

		
		a_flg = A_TACKL;
	}
	/****************************************/


	//�}�b�v�̃u���b�N�̏�ӂɐڐG������

		//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_TACKL){
			a_flg = A_STAND;
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
		}
	}
	/*****************************************/

	/******����********************************/
	if (GetKeyState(VK_LEFT) & 0x8000){
		player.vx = -14;
		a_flg = A_WALK1_Left;
		a_cnt++;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000){
		player.vx = 14;
		a_flg = A_WALK1_Right;
		a_cnt++;
	}

	//�E�̃A�j���[�V����
	if (a_flg == A_WALK1_Right && a_cnt >= 10){
		a_flg = A_WALK2_Right;
	}
	if (a_flg == A_WALK2_Right && a_cnt >= 20){
		a_flg = A_WALK3_Right;
	}
	if (a_flg == A_WALK3_Right && a_cnt >= 30){
		a_flg = A_WALK4_Right;
	}
	if (a_flg == A_WALK4_Right && a_cnt >= 20){
		a_flg = A_WALK1_Right;
		a_cnt = 0;
	}

	//���̃A�j���[�V����
	if (a_flg == A_WALK1_Left && a_cnt >= 10){
		a_flg = A_WALK2_Left;
	}
	if (a_flg == A_WALK2_Left && a_cnt >= 20){
		a_flg = A_WALK3_Left;
	}
	if (a_flg == A_WALK3_Left && a_cnt >= 30){
		a_flg = A_WALK4_Left;
	}
	if (a_flg == A_WALK4_Left && a_cnt >= 20){
		a_flg = A_WALK1_Left;
		a_cnt = 0;
	}

	//a_flg��A_STAND�ɖ߂�����
	if (a_flg == A_WALK1_Right || a_flg == A_WALK2_Right || a_flg == A_WALK3_Right || a_flg == A_WALK4_Right || a_flg == A_WALK1_Left || a_flg == A_WALK2_Left || a_flg == A_WALK3_Left || a_flg == A_WALK4_Left){
		if (player.vx <= 1 && player.vx >= -1)
		{
			a_flg = A_STAND;
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
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000){
			player.vx = 14;
		}
		a_flg = A_JUMP;
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
	/*****�^�b�N���̏I��*******/
	if (player.c_flg == TACKLE_STOP){
		player.vx += player.attack_x;
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


		a_flg = A_TACKL;
	}
	if (*Oil < 0){  //�I�C���Q�[�W��0�̎��̓^�b�N���͕s��
		*Oil = 0;
		player.attack_x = 0;
		a_flg = A_STAND;
	}
	/****************************************/


	//�}�b�v�̃u���b�N�̏�ӂɐڐG������
	
		//���ړ���A_STAND�̕`�������
	if (a_flg != A_WALK1_Right && a_flg != A_WALK2_Right && a_flg != A_WALK3_Right && a_flg != A_WALK4_Right && a_flg != A_WALK1_Left && a_flg != A_WALK2_Left && a_flg != A_WALK3_Left && a_flg != A_WALK4_Left && a_flg != A_TACKL){
			a_flg = A_STAND;
		}
	
	return 0;
}


void MOVE::C_sts(int a,int *b){
	c_sts = a;
	Oil = b;
}