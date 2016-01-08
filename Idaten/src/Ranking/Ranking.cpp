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

	if (ifs.fail()) {			//�����L���O�t�@�C��������������

		for (i = 0; i < 5; i++){
			rank.push_back(std::make_pair("����������", 999.0 - i));		//�����̃����L���O�̒l
		}
	}
	else{

		while (getline(ifs, str))			//�����L���O�t�@�C��������ꍇ
		{
			std::string tmp;
			std::istringstream stream(str);
			num += 1;

			while (getline(stream, tmp, ','))
			{
				data.push_back(tmp);	//�J���}��������tmp�Ɉꎞ�I�Ƀf�[�^������
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
	std::sort(rank.begin(), rank.end(), sort_less());	//�����\�[�g

}

void Ranking_Name::AddRanking(HWND hWnd1){

#ifdef UNICODE

	WideCharToMultiByte(CP_ACP, 0, name, -1, str, sizeof(str), NULL, NULL);	//TCHAR ����CHAR
#endif

	rank.push_back(std::make_pair(str, S_time));       //�����L���O�Ō�ɓ����

	Sort_Asc();										//�����\�[�g

	rank.pop_back();								//�Ō�̃����L���O�̒l������
	rank.resize(5);
}

int Ranking_Name::NameInput(HWND hWnd2)
{
	SYSTEMTIME st;
	int age;
	TCHAR str[256];

	MessageBox(hWnd2, name, TEXT("���O"), MB_OK);	//�m�F���

	return 0;
}

bool Ranking_Name::Ranking_Paint(HDC hdc){

	int i = 0;

	std::ofstream ofs("ranking.txt");

	for (i = 0; i < 5; i++){

		strcpy(str, rank[i].first.c_str());			//string����char�ɕϊ�(�R�s�[)
		//wsprintf(buf[i], TEXT("%d"), rank[i].first);

		MultiByteToWideChar(CP_OEMCP, MB_PRECOMPOSED, str, -1, buf[i], sizeof(buf));	//char����TCHAR�ɕϊ�

		ofs << rank[i].first << "," << rank[i].second << "," << std::endl;		//�e�L�X�g�t�@�C���ɏ�������

		DebugStringColor("%d��", i + 1, hdc, 300, 65 * (4.5 + i), 27, 0, 0, 0);			//�`��
		DebugStringColor("%.3lf�b", rank[i].second, hdc, 650, 65 * (4.5 + i), 27, 0, 0, 0);
		DebugStringColor("���O %s", buf[i], hdc, 350, 65 * (4.5 + i), 27, 0, 0, 0);
	}
	return true;
}


