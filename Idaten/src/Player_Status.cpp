#include"Player_Status.h"
#pragma comment(lib,"msimg32.lib")


void OIL::Item(int a)
{
	if (a == 1 || a == -1){
		Oil_Gage += a;
		}
	if (Oil_Gage > 5){
		Oil_Gage = 5;
	}
	if (Oil_Gage < 0){
		Oil_Gage = 0;
	}

}

/////�X�e�[�^�X�Ǘ�////////
int OIL::Player_Sts()
{
	if (Oil_Gage == 0 || Oil_Gage == 1){
		c_sts = GARI;
		if (Oil_Gage == 0){
			gage = 0;
		}
		if (Oil_Gage == 1){
			gage = 1;
		}
		
	}
	if (Oil_Gage == 2){
		c_sts = TYOIYASE;
		gage = 2;
	}
	if (Oil_Gage == 3){
		c_sts = HUTHU;
		gage = 3;
	}
	if (Oil_Gage == 4){
		c_sts = POTYA;
		gage = 4;
	}
	if (Oil_Gage == 5){
		c_sts = DEBU;
		gage = 5;
	}
	return 0;
}

/////�I�C���̃p���[�Ǘ�/////////
int OIL::Oil_Sts()
{
	Power_w = 50;
	if (gage == 0){
		Power_w = Power_w * gage;
	}
	if (gage == 1){
		Power_w = Power_w * gage;
	}
	if (gage == 2){
		Power_w = Power_w * gage;
	}
	if (gage == 3){
		Power_w = Power_w * gage;
	}
	if (gage == 4){
		Power_w = Power_w * gage;
	}
	if (gage == 5){
		Power_w = Power_w * gage;
	}
	return 0;
}

/////�Q�[�W�`��/////////
int OIL::Paint_Gage(HDC hdc)
{
	// �f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	// �������f�o�C�X�R���e�L�X�g���쐬
	hdc_work = CreateCompatibleDC(hdc);
	// �I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_OilGage);
	// �摜��]������
	TransparentBlt(hdc, 0, 0, 254, 35, hdc_work, 0, 0, 254, 35, RGB(255, 255, 255));
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}


//////�I�C���p���[�̕`��////////////
int OIL::Paint_Oil(HDC hdc)
{
	//�f�o�C�X�R���e�L�X�g�n���h��
	HDC hdc_work;
	//�f�o�C�X�R���e�L�X�g�̍쐬
	hdc_work = CreateCompatibleDC(hdc);
	//�I�u�W�F�N�g�̑I��
	SelectObject(hdc_work, hb_OilPower);
	//�摜�]��
	BitBlt(hdc, 0, 0, Power_w, 35, hdc_work, 0, 0, SRCCOPY);
	//�f�o�C�X�R���e�L�X�g�̉��
	DeleteDC(hdc_work);
	return 0;
}

