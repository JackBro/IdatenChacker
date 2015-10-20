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
			fscanf(fp, "%*s%d%*s", &r_time[i]);	//読み込み
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
		wsprintf(mes, TEXT("データファイルのオープンに失敗しました。保存を中止しました。\n"));
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
		wsprintf(mes, TEXT("データファイルのオープンに失敗しました。保存を中止しました。\n"));
		OutputDebugString(mes);
		return;
	}

						
		if (r_time[0] > S_time){		//ランキング1位より現在プレイしてる人のほうが早ければ
			tmp = r_time[0];
			r_time[0] = S_time;		//現在の1位を上書き
			tmp2 = r_time[1];
			r_time[1] = tmp;		//ランキング1位の人を2位に下げる	
			r_time[2] = tmp2;		//ランキング2位の人を3位に下げる
		}

		else if (r_time[1] > S_time && S_time >r_time[0]){	//ランキング2位より現在プレイしてる人のほうが高ければ
			tmp = r_time[1];
			r_time[1] = S_time;
			r_time[2] = tmp;
		}

		else if (r_time[2] > S_time && S_time >r_time[1]){		
			r_time[2] = S_time;
		}

			fprintf(fp, "1位 %d秒\n", r_time[0]);
			DebugStringColor("1位 %f秒",r_time[0], hdc, 500, 65 * (2 + 3), 30, 0, 0, 0);

			fprintf(fp, "2位 %d秒\n", r_time[1]);
			DebugStringColor("2位 %f秒", r_time[1], hdc, 500, 65 * (2 + 4), 30, 0, 0, 0);
			fprintf(fp, "3位 %d秒\n", r_time[2]);
			DebugStringColor("3位 %f秒", r_time[2], hdc, 500, 65 * (2 + 5), 30, 0, 0, 0);
		
	fclose(fp);
}