#pragma once
#include<Windows.h>
#include"player_info.h"

class Itemclass{
protected:
		HDC itemhdc;
		int itemtype;

		HBITMAP item_hb;

		player_info *plstats;

		//�L�����̃X�e�[�^�X���ꕔ���ۑ����Ă����\����
public:
		struct item_info{
			float x, y;
			int width, height;
			int onActive;
		}item;


		//���L���\�b�h
		int Item_paint(HDC enemy_hdc);
		int chara_strc(player_info *tp);	//�}�l�[�W������L�����̃X�e�[�^�X���i�[����

		int hit_itemcheck();		//�G�Ƃ̓����蔻��


		int item_scroll(int, int);
		int getItemtype(){ return itemtype; }
		int get_onActive(){ return item.onActive; }

	Itemclass();
	virtual	~Itemclass();
};

