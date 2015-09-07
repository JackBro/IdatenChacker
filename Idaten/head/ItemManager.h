#pragma once
#include<Windows.h>
#include"player_info.h"
#include<memory>
#include<vector>
#include<math.h>
#include<time.h>

#include"Itemclass.h"

#include"Itemupper.h"
#include"Itemdowner.h"
#include"debugmsg.h"
#include"Option.h"


/*
******************************************************************************
�N���X�̐���
------------------------------------------------------------------------------
�A�C�e���𐶐�����N���X

�g�p�w�b�_�i�N���X�j
Memory	�iunique_ptr�j
Math
Time	(random�֐�)
Vector  (vector)

Itemclass	(Item�̊�b�N���X)
Itemupper	(�l�𑝉�������Item�̃N���X)


�O������K�v�Ȓl
Scroll�N���X	���\�b�h��:ItemScroll(Int,Int)			//�X�N���[������w�i�̈ړ��ʁi�X�N���[���ʁj���擾����
Map�N���X		���\�b�h��:StageCoord(Int,Int)			//�}�b�v���X�N���[���������̍��W���擾


�g������
//Item
iobj->chara_strc(player);
iobj->item_scroll(obj1.BackMoveX, obj1.BackMoveY);					��
iobj->stage_coord(obj2.get_block_X(), obj2.get_block_Y());			��
iobj->MainLoop(hdc);

//	pobj->joutaihenka(iobj->GetItemtype());

iobj->GetItemtype(0);


�������
�L�����N�^�[�̃X�e�[�^�X��ԁi���W���j���܂��n���܂��B�i���肷�邽�߁j
�X�N���[���̒l�ƃ}�b�v�̒l�����B

Mainloop��HDC��n���B
	�X�|�[���Ƃ��͏���ɂ���Ă����
	�L�����N�^�[�Ƃ��������Ƃ������肪��ꂽ��
	GetItemType�̖߂�l�Ɂ@ 0�@ �ȊO�̐��l��������

	�����I����ɂ͂O��������B


���O���̒l��K�v�Ƃ���





******************************************************************************

*/


class ItemManager{
	private:
		HDC itemhdc;	//�f�o�C�X�R���e�L�X�g�n���h��(Mainloop�ɂ�肻�̓s�x�X�V�����)
		int itemtype;

		player_info *plstats;	//�G�ɓn���L�����̃f�[�^�̃R�s�[(Main>>EnemyManager>>Enemy)

		int scroll_x, scroll_y;		//�X�N���[���ʂ����W�ɔ��f������
		int maps_x, maps_y;			//�X�e�[�W�̍��W���i�[���Ă����B�@�X�N���[���ɂ���ĉς������W�l����邽��

		//�o�����W�i�[�p�z��
		int spawnpoint[2];
		std::vector<std::vector<int>>Stage_Spawnpoint;			//�X�e�[�W��̏o�����W���i�[���Ă���


		int SpawnItem();		//�A�C�e���̐���
		int GetSpawnPoint(int);	//�A�C�e���̏o���|�C���g���w�肷��B
		void SetSpawnPoint();	//�A�C�e���̏o���|�C���g�����������Ă����B

		int Maxitem;			//�A�C�e���ő吔�i�ρj
		
		int stageID;			//�R���X�g���N�^����X�e�[�W�̔ԍ����擾����
		const int SpawnInterval = ITEM_SPAWN_INTERVAL;		//���X�|�[������܂ł̃C���^�[�o��

		std::vector<int>SpawnList;							//�ǂ��̃A�C�e�������ɏo�������邩�����Ă����I�[�_�[���X�g

	public:

		std::vector<std::unique_ptr<Itemclass>>iobj;
//		std::unique_ptr<Itemclass>iobj[5];

		int chara_strc(player_info *tp);	//�}�l�[�W������L�����̃X�e�[�^�X���i�[����

		int item_scroll(int, int);		//�X�N���[���ɑΉ����邽�ߒl��n��
		int stage_coord(int, int);		//�X�|�[��������W�l����ʂ���̍��W�ɂȂ邽�߃O���[�o���̍��W���Ђ悤

		void MainLoop(HDC);
		int GetItemtype(){ return itemtype; }
		int GetItemtype(int);

	ItemManager();
	ItemManager(int);
	~ItemManager();
};

