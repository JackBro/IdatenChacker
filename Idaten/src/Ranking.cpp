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
			DebugStringColor("1�� %f�b",r_time[0], hdc, 500, 65 * (2 + 3), 30, 0, 0, 0);

			fprintf(fp, "2�� %d�b\n", r_time[1]);
			DebugStringColor("2�� %f�b", r_time[1], hdc, 500, 65 * (2 + 4), 30, 0, 0, 0);
			fprintf(fp, "3�� %d�b\n", r_time[2]);
			DebugStringColor("3�� %f�b", r_time[2], hdc, 500, 65 * (2 + 5), 30, 0, 0, 0);
		
	fclose(fp);
}