#pragma once
typedef struct{
	
	float x, y;				// �ʒu
	float step_x, step_y;	// �ړ���
	float jump_power;
	int   width, height;	// ���A����

	//�L�����̍U���i�^�b�N���Ɋւ���l�j					��NEW
	int vx, vy;
	int attack_mukou;
	int attack_x, attack_y;

	//�L�����̃t���O
	//�O����	�P����	�@2�^�b�N���@3�^�b�N���X�g�b�v 4�W�����v�@5�����H
	int c_flg;              
	

	//
	bool jump;
	bool Tackle;
	//
}player_info;