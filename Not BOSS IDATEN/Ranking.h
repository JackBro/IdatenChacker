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

	char str[30];		//変換用
	TCHAR buf[5][30];		//変換用
	TCHAR name[30];

	bool Reading();	//ランキング読み込み

	void Sort_Asc();	//Rankingを昇順にソート

	void AddRanking(HWND hWnd2);	//ランキング登録

	int NameInput(HWND hWnd2);		//名前入力

	bool Ranking_Paint(HDC hdc);	//ランキングの描画
};
#endif