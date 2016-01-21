#pragma once

//////////////�u���b�N/////////////
#define MAP_WIDTH  220   //��ʂ̉����A  �u���b�N�̉��̗v�f��
#define MAP_HEIGHT 48    //��ʂ̏c���@�@�u���b�N�̏c�̗v�f��


#define BLOCK_PAINT_X  WINDOW_WIDTH/CHIP_SIZE		//�u���b�N����
#define BLOCK_PAINT_Y  WINDOW_HEIGHT/CHIP_SIZE		//�u���b�N�c��

#define STAGE2_WIDTH 320
#define STAGE2_HEIGHT 48

#define BOSS_STAGE_WIDTH 220
#define BOSS_STAGE_HEIGHT 48

#define CHIP_SIZE   30   //��̃u���b�N�̃T�C�Y 

#define PLAYER_HEIGHT 640
#define PLAYER_WIDTH  1280

//��ʃT�C�Y�͂P�U�F�X
#define WINDOW_WIDTH	(16*70)					//��ʉ��T�C�Y 1120
#define WINDOW_HEIGHT	(9*70)					//��ʏc�T�C�Y	630



#define MAX_LENGTH 21  //���p�߂荞�݋��e�l 
#define MAX_LENGTH02 20 //�c�p�߂荞�݋��e�l


//////////////////////////////////////////////////////


// �}�N���̒�`
#define KEY_UP		1
#define KEY_LEFT	2
#define KEY_RIGHT	8


//�G
#define ENEMYMAX 4
#define ENEMY_SPAWN_INTERVAL 100

//�A�C�e��
#define ITEM_SPAWN_INTERVAL 80

enum Scene{ Title, End, Stage1,Stage2, Boss};