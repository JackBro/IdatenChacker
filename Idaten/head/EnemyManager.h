#pragma once

#include<Windows.h>
#include<memory>
#include"Enemy.h"//�X�[�p�[�N���X

//�ȉ��T�u
#include"Enemy01.h"
#include"Enemy02.h"
#include"Enemy03.h"
#include"Enemy04.h"
#include"Enemy05.h"
#include"Enemy06.h"
#include"Enemy07.h"


//�L�����̃N���X�i��	�l���ǂ��󂯎�邩�͂܂��s���Ȃ̂Łi���j
#include"player_info.h"
#include"Option.h"
//debug�p
#include"debugmsg.h"




/*
���̃N���X�ł͎��

�G�̐����B
���݂̃}�b�v�ԍ�
�o�����W�̎w��

�X�N���[���l�̎󂯓n���i�G�N���X�ցj
�G�N���X����L�����ƐڐG�����Ƃ�������𓾂�B

�Ȃǂ��Ǘ�,�擾����
*///���ɕK�v�Ȃ��Ƃ�����Ώ����ǉ�


/*		//��������ꍇ�́@���̗l�ɂ���Ă����Ɠ�����
/Enemy
//-----------------------------
eobj->chara_strc(player);
eobj->enemy_scroll(obj1.BackMoveX, obj1.BackMoveY);
eobj->stage_coord(obj2.get_block_X(), obj2.get_block_Y());
eobj->MainLoop(hdc);
*/




class EnemyManager
{



private:
	const int TYPE_MAX = 7;	//�G�̃^�C�v�̍ő吔

	HDC enemyhdc;	//�f�o�C�X�R���e�L�X�g�n���h��(Mainloop�ɂ�肻�̓s�x�X�V�����)

	player_info *plstats;	//�G�ɓn���L�����̃f�[�^�̃R�s�[(Main->EnemyManager->Enemy)

	int scroll_x, scroll_y;		//�X�N���[���ʂ�G�̍��W�ɔ��f������
	int maps_x, maps_y;			//�X�e�[�W�̍��W���i�[���Ă����B�@�X�N���[���ɂ���ĉς������W�l����邽��
	int deadflg;				//�L�����N�^�[�����S�����Ƃ����������B�i�֐���I/O����j

	//�o�����W�i�[�p�z��
	int spawnpoint[2];

	int map1_spawnpoint[3][2];	//�}�b�v�P�p

	//���\�b�h

	//int getMapID();			//�}�b�vID�̎擾<���g�p>

	int SpawnEnemy();		//�G�̐���
	int GetSpawnPoint(int);	//�G�̏o���|�C���g���w�肷��B
		void SetSpawnPoint();	//�G�̏o���|�C���g�����������Ă����B

		const int SpawnInterval = ENEMY_SPAWN_INTERVAL;		//���X�|�[������܂ł̃C���^�[�o��

		
public:

std::unique_ptr<Enemy>eobj[ENEMYMAX];

int chara_strc(player_info *tp);	//�}�l�[�W������L�����̃X�e�[�^�X���i�[����

int enemy_scroll(int, int);		//�G���X�N���[���ɑΉ����邽�ߒl��n��
int stage_coord(int, int);		//�X�|�[��������W�l����ʂ���̍��W�ɂȂ邽�߃O���[�o���̍��W���Ђ悤


int GetDeadflag();			//�l����邾��
int GetDeadflag(int);		//�l���Z�b�g���邪�O���P�̂�(deadflg��)����\

	void MainLoop(HDC);
	EnemyManager();
	~EnemyManager();
};




