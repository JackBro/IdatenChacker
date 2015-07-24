#pragma once


#include <windows.h>
#include <math.h>	
#include <time.h>   

#include"player_info.h"

#include"debugmsg.h"
#include"Option.h"


/*
�G�̐e�̃N���X�B
�\���̂̐錾��A�h������̂ɕK�v�Ȑ錾�������Ă���B



�����Ŏ�舵�����\�b�h


*/

class Enemy{
protected:


	int DEADflg = 0;	//�G�ƃL�����N�^�[���ڐG�����ꍇ�ɐ^�i-�P�j�Q�[�W�𒼐ڂ�����̂Ł|�P
	int Jump = 0;		//�����ł̂ݎg�p����

	

	//�G�̃f�o�C�X�R���e�L�X�g�n���h��
	HDC enemyhdc;

	//�G��Bitmap�n���h��
	HBITMAP enemy_hb;

	player_info *plstats;

							//�L�����̃X�e�[�^�X���ꕔ���ۑ����Ă����\����
							//�G�̃X�e�[�^�X�̍\����

	struct bullet_info{
		float x, y;
		float dx, dy;
		int width, height;
		int onActive;
	}enemy_bullet;				//�G���g���e�̍\���́B

public :

	struct enemy_info{
		float x, y;
		float dx, dy;
		float rad_x, rad_y;
		int step_x, step_y;
		int width, height;
		int onActive;
		int base_y;
		int	anim_count, timecnt, actioncnt;
		int MAX_Tcnt;
	}enemy;


	//���L���\�b�h
	int Enemy_paint(HDC enemy_hdc);
	int enemyPaintBullet();
	int chara_strc(player_info *tp);	//�}�l�[�W������L�����̃X�e�[�^�X���i�[����

	int hit_enemycheck();		//�G�Ƃ̓����蔻��
	int hit_enemycheckN();		//�G�Ƃ̓����蔻�肾���G���������Ȃ��B

	int get_deadflg(){ return DEADflg;	}
	int get_onActive(){ return enemy.onActive; }
	
	int enemy_scroll(int, int);
	int bullet_scroll(int, int);
	
	
	//�h�����郁�\�b�h ���g�͋�ł���
	virtual int init(){ return 0; }
	virtual int move_enemy(){ return 0; }
	virtual int spawn_enemy(){ return 0; }


//�f�X�g���N�^�͉��z
	Enemy();
	virtual ~Enemy(){};
};
