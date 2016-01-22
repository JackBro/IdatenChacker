#ifndef _Ranking_H
#define _Ranking_H

#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include"timer.h"
#include"debugmsg.h"


using std::string;
#define ON 1
#define OFF 0

static int flag=ON;
static HWND hWnd2;


class Ranking_Name
{
private:

	typedef std::pair<std::string, double> rank_pair;

	std::vector<rank_pair>rank;

	std::vector<std::string>data;

	struct sort_less {
		bool operator()(const std::pair<string, double> &left, const std::pair<string, double> &right) {
			return left.second < right.second;
		}
	};

public:
	Ranking_Name();
	~Ranking_Name();

	char str[30];		//�ϊ��p
	TCHAR buf[5][30];		//�ϊ��p
	TCHAR name[30];

	bool Reading();	//�����L���O�ǂݍ���

	void Sort_Asc();	//Ranking�������Ƀ\�[�g

	void AddRanking(HWND hWnd2);	//�����L���O�o�^

	int NameInput(HWND hWnd2);		//���O����

	bool Ranking_Paint(HDC hdc);	//�����L���O�̕`��
};
#endif