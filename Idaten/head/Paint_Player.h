#pragma once
#pragma comment(lib,"msimg32.lib")
#include"player_info.h"
#include<Windows.h>


HBITMAP hb_Stand00;
HBITMAP hb_Stand01;
HBITMAP hb_Stand02;
HBITMAP hb_Stand03;
HBITMAP hb_Stand04;
HBITMAP hb_Stand05;
HBITMAP hb_Stand06;
HBITMAP hb_Stand07;
HBITMAP hb_Stand08;
HBITMAP hb_Stand09;
HBITMAP hb_Run00_Right;
HBITMAP hb_Run01_Right;
HBITMAP hb_Run02_Right;
HBITMAP hb_Run03_Right;
HBITMAP hb_Run04_Right;
HBITMAP hb_Run05_Right;
HBITMAP hb_Run06_Right;
HBITMAP hb_Run07_Right;
HBITMAP hb_Run08_Right;
HBITMAP hb_Run09_Right;
HBITMAP hb_Run10_Right;
HBITMAP hb_Run11_Right;
HBITMAP hb_Run12_Right;
HBITMAP hb_Run13_Right;
HBITMAP hb_Run14_Right;
HBITMAP hb_Run00_Left;
HBITMAP hb_Run01_Left;
HBITMAP hb_Run02_Left;
HBITMAP hb_Run03_Left;
HBITMAP hb_Run04_Left;
HBITMAP hb_Run05_Left;
HBITMAP hb_Run06_Left;
HBITMAP hb_Run07_Left;
HBITMAP hb_Run08_Left;
HBITMAP hb_Run09_Left;
HBITMAP hb_Run10_Left;
HBITMAP hb_Run11_Left;
HBITMAP hb_Run12_Left;
HBITMAP hb_Run13_Left;
HBITMAP hb_Run14_Left;
HBITMAP hb_Tackle00;
HBITMAP hb_Tackle01;
HBITMAP hb_Tackle02;
HBITMAP hb_Tackle03;
HBITMAP hb_Tackle04;
HBITMAP hb_Tackle05;
HBITMAP hb_Tackle06;
HBITMAP hb_Tackle07;
HBITMAP hb_Jump_Right;
HBITMAP hb_Jump_Left;
HBITMAP hb_Yarare;
HBITMAP hb_BG;//ビットマップハンドル(背景用)

class PAINT{
		

public:
	player_info pla;
	~PAINT(){ DeleteObject(hb_Stand00), DeleteObject(hb_Stand01), DeleteObject(hb_Stand03), DeleteObject(hb_Stand04), DeleteObject(hb_Stand05), 
		DeleteObject(hb_Stand06), DeleteObject(hb_Stand07), DeleteObject(hb_Stand08), DeleteObject(hb_Stand09); }

	

	int Paint_Stand00_H(HDC);//普通状態の描画
	int Paint_Stand01_H(HDC);
	int Paint_Stand02_H(HDC);
	int Paint_Stand03_H(HDC);
	int Paint_Stand04_H(HDC);
	int Paint_Stand05_H(HDC);
	int Paint_Stand06_H(HDC);
	int Paint_Stand07_H(HDC);
	int Paint_Stand08_H(HDC);
	int Paint_Stand09_H(HDC);
	int Paint_Run00_H_Right(HDC);
	int Paint_Run01_H_Right(HDC);
	int Paint_Run02_H_Right(HDC);
	int Paint_Run03_H_Right(HDC);
	int Paint_Run04_H_Right(HDC);
	int Paint_Run05_H_Right(HDC);
	int Paint_Run06_H_Right(HDC);
	int Paint_Run07_H_Right(HDC);
	int Paint_Run08_H_Right(HDC);
	int Paint_Run09_H_Right(HDC);
	int Paint_Run10_H_Right(HDC);
	int Paint_Run11_H_Right(HDC);
	int Paint_Run12_H_Right(HDC);
	int Paint_Run13_H_Right(HDC);
	int Paint_Run14_H_Right(HDC);
	int Paint_Run00_H_Left(HDC);
	int Paint_Run01_H_Left(HDC);
	int Paint_Run02_H_Left(HDC);
	int Paint_Run03_H_Left(HDC);
	int Paint_Run04_H_Left(HDC);
	int Paint_Run05_H_Left(HDC);
	int Paint_Run06_H_Left(HDC);
	int Paint_Run07_H_Left(HDC);
	int Paint_Run08_H_Left(HDC);
	int Paint_Run09_H_Left(HDC);
	int Paint_Run10_H_Left(HDC);
	int Paint_Run11_H_Left(HDC);
	int Paint_Run12_H_Left(HDC);
	int Paint_Run13_H_Left(HDC);
	int Paint_Run14_H_Left(HDC);
	int Paint_Jump_Right_H(HDC);
	int Paint_Jump_Left_H(HDC);
	int Paint_Tackle00_H(HDC);

	int Paint_Stand00_D(HDC);//デブ状態の描画
	int Paint_Stand01_D(HDC);
	int Paint_Stand02_D(HDC);
	int Paint_Stand03_D(HDC);
	int Paint_Stand04_D(HDC);
	int Paint_Stand05_D(HDC);
	int Paint_Stand06_D(HDC);
	int Paint_Stand07_D(HDC);
	int Paint_Stand08_D(HDC);
	int Paint_Stand09_D(HDC);
	int Paint_Run00_D_Right(HDC);
	int Paint_Run01_D_Right(HDC);
	int Paint_Run02_D_Right(HDC);
	int Paint_Run03_D_Right(HDC);
	int Paint_Run04_D_Right(HDC);
	int Paint_Run05_D_Right(HDC);
	int Paint_Run06_D_Right(HDC);
	int Paint_Run07_D_Right(HDC);
	int Paint_Run08_D_Right(HDC);
	int Paint_Run09_D_Right(HDC);
	int Paint_Run10_D_Right(HDC);
	int Paint_Run11_D_Right(HDC);
	int Paint_Run12_D_Right(HDC);
	int Paint_Run13_D_Right(HDC);
	int Paint_Run14_D_Right(HDC);
	int Paint_Run00_D_Left(HDC);
	int Paint_Run01_D_Left(HDC);
	int Paint_Run02_D_Left(HDC);
	int Paint_Run03_D_Left(HDC);
	int Paint_Run04_D_Left(HDC);
	int Paint_Run05_D_Left(HDC);
	int Paint_Run06_D_Left(HDC);
	int Paint_Run07_D_Left(HDC);
	int Paint_Run08_D_Left(HDC);
	int Paint_Run09_D_Left(HDC);
	int Paint_Run10_D_Left(HDC);
	int Paint_Run11_D_Left(HDC);
	int Paint_Run12_D_Left(HDC);
	int Paint_Run13_D_Left(HDC);
	int Paint_Run14_D_Left(HDC);
	int Paint_Jump_Right_D(HDC);
	int Paint_Jump_Left_D(HDC);
	int Paint_Tackle00_D(HDC);

	int Paint_Stand00_P(HDC);//ポチャ状態の描画
	int Paint_Stand01_P(HDC);
	int Paint_Stand02_P(HDC);
	int Paint_Stand03_P(HDC);
	int Paint_Stand04_P(HDC);
	int Paint_Stand05_P(HDC);
	int Paint_Stand06_P(HDC);
	int Paint_Stand07_P(HDC);
	int Paint_Stand08_P(HDC);
	int Paint_Stand09_P(HDC);
	int Paint_Run00_P_Right(HDC);
	int Paint_Run01_P_Right(HDC);
	int Paint_Run02_P_Right(HDC);
	int Paint_Run03_P_Right(HDC);
	int Paint_Run04_P_Right(HDC);
	int Paint_Run05_P_Right(HDC);
	int Paint_Run06_P_Right(HDC);
	int Paint_Run07_P_Right(HDC);
	int Paint_Run08_P_Right(HDC);
	int Paint_Run09_P_Right(HDC);
	int Paint_Run10_P_Right(HDC);
	int Paint_Run11_P_Right(HDC);
	int Paint_Run12_P_Right(HDC);
	int Paint_Run13_P_Right(HDC);
	int Paint_Run14_P_Right(HDC);
	int Paint_Run00_P_Left(HDC);
	int Paint_Run01_P_Left(HDC);
	int Paint_Run02_P_Left(HDC);
	int Paint_Run03_P_Left(HDC);
	int Paint_Run04_P_Left(HDC);
	int Paint_Run05_P_Left(HDC);
	int Paint_Run06_P_Left(HDC);
	int Paint_Run07_P_Left(HDC);
	int Paint_Run08_P_Left(HDC);
	int Paint_Run09_P_Left(HDC);
	int Paint_Run10_P_Left(HDC);
	int Paint_Run11_P_Left(HDC);
	int Paint_Run12_P_Left(HDC);
	int Paint_Run13_P_Left(HDC);
	int Paint_Run14_P_Left(HDC);
	int Paint_Jump_Right_P(HDC);
	int Paint_Jump_Left_P(HDC);
	int Paint_Tackle00_P(HDC);

	int Paint_Stand00_Y(HDC);//ヤセ状態の描画
	int Paint_Stand01_Y(HDC);
	int Paint_Stand02_Y(HDC);
	int Paint_Stand03_Y(HDC);
	int Paint_Stand04_Y(HDC);
	int Paint_Stand05_Y(HDC);
	int Paint_Stand06_Y(HDC);
	int Paint_Stand07_Y(HDC);
	int Paint_Stand08_Y(HDC);
	int Paint_Stand09_Y(HDC);
	int Paint_Run00_Y_Right(HDC);
	int Paint_Run01_Y_Right(HDC);
	int Paint_Run02_Y_Right(HDC);
	int Paint_Run03_Y_Right(HDC);
	int Paint_Run04_Y_Right(HDC);
	int Paint_Run05_Y_Right(HDC);
	int Paint_Run06_Y_Right(HDC);
	int Paint_Run07_Y_Right(HDC);
	int Paint_Run08_Y_Right(HDC);
	int Paint_Run09_Y_Right(HDC);
	int Paint_Run10_Y_Right(HDC);
	int Paint_Run11_Y_Right(HDC);
	int Paint_Run12_Y_Right(HDC);
	int Paint_Run13_Y_Right(HDC);
	int Paint_Run14_Y_Right(HDC);
	int Paint_Run00_Y_Left(HDC);
	int Paint_Run01_Y_Left(HDC);
	int Paint_Run02_Y_Left(HDC);
	int Paint_Run03_Y_Left(HDC);
	int Paint_Run04_Y_Left(HDC);
	int Paint_Run05_Y_Left(HDC);
	int Paint_Run06_Y_Left(HDC);
	int Paint_Run07_Y_Left(HDC);
	int Paint_Run08_Y_Left(HDC);
	int Paint_Run09_Y_Left(HDC);
	int Paint_Run10_Y_Left(HDC);
	int Paint_Run11_Y_Left(HDC);
	int Paint_Run12_Y_Left(HDC);
	int Paint_Run13_Y_Left(HDC);
	int Paint_Run14_Y_Left(HDC);
	int Paint_Jump_Right_Y(HDC);
	int Paint_Jump_Left_Y(HDC);
	int Paint_Tackle00_Y(HDC);

	int Paint_Stand00_G(HDC);//ガリ状態の描画
	int Paint_Stand01_G(HDC);
	int Paint_Stand02_G(HDC);
	int Paint_Stand03_G(HDC);
	int Paint_Stand04_G(HDC);
	int Paint_Stand05_G(HDC);
	int Paint_Stand06_G(HDC);
	int Paint_Stand07_G(HDC);
	int Paint_Stand08_G(HDC);
	int Paint_Stand09_G(HDC);
	int Paint_Run00_G_Right(HDC);
	int Paint_Run01_G_Right(HDC);
	int Paint_Run02_G_Right(HDC);
	int Paint_Run03_G_Right(HDC);
	int Paint_Run04_G_Right(HDC);
	int Paint_Run05_G_Right(HDC);
	int Paint_Run06_G_Right(HDC);
	int Paint_Run07_G_Right(HDC);
	int Paint_Run08_G_Right(HDC);
	int Paint_Run09_G_Right(HDC);
	int Paint_Run10_G_Right(HDC);
	int Paint_Run11_G_Right(HDC);
	int Paint_Run12_G_Right(HDC);
	int Paint_Run13_G_Right(HDC);
	int Paint_Run14_G_Right(HDC);
	int Paint_Run00_G_Left(HDC);
	int Paint_Run01_G_Left(HDC);
	int Paint_Run02_G_Left(HDC);
	int Paint_Run03_G_Left(HDC);
	int Paint_Run04_G_Left(HDC);
	int Paint_Run05_G_Left(HDC);
	int Paint_Run06_G_Left(HDC);
	int Paint_Run07_G_Left(HDC);
	int Paint_Run08_G_Left(HDC);
	int Paint_Run09_G_Left(HDC);
	int Paint_Run10_G_Left(HDC);
	int Paint_Run11_G_Left(HDC);
	int Paint_Run12_G_Left(HDC);
	int Paint_Run13_G_Left(HDC);
	int Paint_Run14_G_Left(HDC);
	int Paint_Jump_Right_G(HDC);
	int Paint_Jump_Left_G(HDC);
	int Paint_Tackle00_G(HDC);
	
	int Paint_Yarare(HDC);

	void char_strc(player_info *);


};
void PAINT::char_strc(player_info *p){
	pla = *p;
}




/************普通状態************************************************************/
int PAINT::Paint_Stand00_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand01_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand01);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand02_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand02);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand03_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand03);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand04_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand04);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand05_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand05);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand06_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand06);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand07_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand07);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand08_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand08);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand09_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand09);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Right_H(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Left_H(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackle00_H(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 227, 394, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/********************************************************************************/

/***********************デブ状態*************************************************/
int PAINT::Paint_Stand00_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand01_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand01);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand02_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand02);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand03_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand03);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand04_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand04);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand05_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand05);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand06_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand06);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand07_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand07);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand08_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand08);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand09_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand09);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Right_D(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Left_D(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackle00_D(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 227, 394, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/

/***********************ポチャ状態************************************************/
int PAINT::Paint_Stand00_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand01_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand01);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand02_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand02);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand03_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand03);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand04_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand04);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand05_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand05);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand06_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand06);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand07_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand07);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand08_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand08);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand09_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand09);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Right_P(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Left_P(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackle00_P(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 227, 394, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/


/***********************ヤセ状態**************************************************/
int PAINT::Paint_Stand00_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand01_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand01);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand02_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand02);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand03_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand03);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand04_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand04);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand05_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand05);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand06_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand06);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand07_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand07);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand08_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand08);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand09_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand09);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Right_Y(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Left_Y(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackle00_Y(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 227, 394, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/


/***********************ガリ状態*************************************************/
int PAINT::Paint_Stand00_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand01_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand01);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand02_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand02);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand03_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand03);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand04_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand04);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand05_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand05);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand06_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand06);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand07_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand07);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand08_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand08);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Stand09_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand09);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 190, 381, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run00_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run00_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run01_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run01_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run02_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run02_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run03_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run03_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run04_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run04_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run05_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run05_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run06_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run06_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run07_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run07_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run08_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run08_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run09_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run09_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run10_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run10_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run11_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run11_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run12_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run12_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run13_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run13_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Run14_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Run14_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Right_G(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Left_G(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 272, 406, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackle00_G(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle00);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 227, 394, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/

