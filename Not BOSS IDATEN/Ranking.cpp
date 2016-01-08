#include "Ranking.h"

Ranking_Name::Ranking_Name()
{

}

Ranking_Name::~Ranking_Name()
{
}

bool Ranking_Name::Reading()
{
	int num = 0;
	int i = 0;


	std::string str;
	std::ifstream ifs("ranking.txt");

	if (ifs.fail()) {			//ランキングファイルが無かったら

		for (i = 0; i < 5; i++){
			rank.push_back(std::make_pair("あいうえお", 999.0 - i));		//初期のランキングの値
		}
	}
	else{

		while (getline(ifs, str))			//ランキングファイルがある場合
		{
			std::string tmp;
			std::istringstream stream(str);
			num += 1;

			while (getline(stream, tmp, ','))
			{
				data.push_back(tmp);	//カンマだったらtmpに一時的にデータを入れる
			}
			rank.resize(num);
			rank[i].first = data[0];
			rank[i].second = atof(data[1].c_str());
			++i;
			data.clear();
		}
	}
	ifs.close();
	return true;
}

void Ranking_Name::Sort_Asc()
{
	std::sort(rank.begin(), rank.end(), sort_less());	//昇順ソート

}

void Ranking_Name::AddRanking(HWND hWnd1){

#ifdef UNICODE

	WideCharToMultiByte(CP_ACP, 0, name, -1, str, sizeof(str), NULL, NULL);	//TCHAR からCHAR
#endif

	rank.push_back(std::make_pair(str, S_time));       //ランキング最後に入れる

	Sort_Asc();										//昇順ソート

	rank.pop_back();								//最後のランキングの値を消す
	rank.resize(5);
}

int Ranking_Name::NameInput(HWND hWnd2)
{
	SYSTEMTIME st;
	int age;
	TCHAR str[256];

	MessageBox(hWnd2, name, TEXT("名前"), MB_OK);	//確認画面

	return 0;
}

bool Ranking_Name::Ranking_Paint(HDC hdc){

	int i = 0;

	std::ofstream ofs("ranking.txt");

	for (i = 0; i < 5; i++){

		strcpy(str, rank[i].first.c_str());			//stringからcharに変換(コピー)
		//wsprintf(buf[i], TEXT("%d"), rank[i].first);

		MultiByteToWideChar(CP_OEMCP, MB_PRECOMPOSED, str, -1, buf[i], sizeof(buf));	//charからTCHARに変換

		ofs << rank[i].first << "," << rank[i].second << "," << std::endl;		//テキストファイルに書き込み

		DebugStringColor("%d位", i + 1, hdc, 300, 65 * (4.5 + i), 27, 0, 0, 0);			//描画
		DebugStringColor("%.3lf秒", rank[i].second, hdc, 650, 65 * (4.5 + i), 27, 0, 0, 0);
		DebugStringColor("名前 %s", buf[i], hdc, 350, 65 * (4.5 + i), 27, 0, 0, 0);
	}
	return true;
}


