#include"Ranking.h"
#include"timer.h"
#include"debugmsg.h"


void Ranking_Load()
{
	FILE *fp;
	int i, j, tmp;

	
	if ((fp = fopen(FileName, "r")) == NULL){
		for (i = 0; i < 3; i++){
			r_time[i] = 999;
		}
	}else{
		for (i = 0; i < 3; i++){
			fscanf(fp, "%*s%d%*s", &r_time[i]);	//�ǂݍ���
		}
		fclose(fp);
	}
	return;
}


/*
void Ranking_save(int rankTime)
{
	FILE *fp;
	TCHAR mes[80];
	int i;

	if ((fp = fopen(FileName, "w")) == NULL)
	{
		wsprintf(mes, TEXT("�f�[�^�t�@�C���̃I�[�v���Ɏ��s���܂����B�ۑ��𒆎~���܂����B\n"));
		OutputDebugString(mes);
		return;
	}
		fprintf(fp, "%d\n", rankTime);
	fclose(fp);

}
*/
void Ranking_save(HDC hdc)
{
	FILE *fp;
	TCHAR mes[80];
	int i,tmp,tmp2;

	if ((fp = fopen(FileName, "w")) == NULL)
	{
		wsprintf(mes, TEXT("�f�[�^�t�@�C���̃I�[�v���Ɏ��s���܂����B�ۑ��𒆎~���܂����B\n"));
		OutputDebugString(mes);
		return;
	}

						
		if (r_time[0] > S_time){		//�����L���O1�ʂ�茻�݃v���C���Ă�l�̂ق����������
			tmp = r_time[0];
			r_time[0] = S_time;		//���݂�1�ʂ��㏑��
			tmp2 = r_time[1];
			r_time[1] = tmp;		//�����L���O1�ʂ̐l��2�ʂɉ�����	
			r_time[2] = tmp2;		//�����L���O2�ʂ̐l��3�ʂɉ�����
		}

		else if (r_time[1] > S_time && S_time >r_time[0]){	//�����L���O2�ʂ�茻�݃v���C���Ă�l�̂ق����������
			tmp = r_time[1];
			r_time[1] = S_time;
			r_time[2] = tmp;
		}

		else if (r_time[2] > S_time && S_time >r_time[1]){		
			r_time[2] = S_time;
		}

			fprintf(fp, "1�� %d�b\n", r_time[0]);
			DebugStringVal("1�� %d�b",r_time[0], hdc, 380, 30 * (1 + 3), 30, 1);
			fprintf(fp, "2�� %d�b\n", r_time[1]);
			DebugStringVal("2�� %d�b", r_time[1], hdc, 380, 30 * (2 + 3), 30, 1);
			fprintf(fp, "3�� %d�b\n", r_time[2]);
			DebugStringVal("3�� %d�b", r_time[2], hdc, 380, 30 * (3+ 3), 30, 1);
		
	fclose(fp);
}