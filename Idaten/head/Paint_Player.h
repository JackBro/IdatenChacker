#pragma once
#pragma comment(lib,"msimg32.lib")
#include"player_info.h"
#include<Windows.h>


HBITMAP hb_Player;
HBITMAP hb_Walk_Right;
HBITMAP hb_Walk2_Right;
HBITMAP hb_Walk3_Right;
HBITMAP hb_Walk4_Right;
HBITMAP hb_Walk_Left;
HBITMAP hb_Walk2_Left;
HBITMAP hb_Walk3_Left;
HBITMAP hb_Walk4_Left;
HBITMAP hb_Tackl;
HBITMAP hb_Jump;
HBITMAP hb_Yarare;
HBITMAP hb_BG;//ビットマップハンドル(背景用)

class PAINT{
		

public:
	player_info pla;
	~PAINT(){ DeleteObject(hb_Player); }

	

	int Paint_Player_H(HDC);//普通状態の描画
	int Paint_Walk1_H_Right(HDC);
	int Paint_Walk2_H_Right(HDC);
	int Paint_Walk3_H_Right(HDC);
	int Paint_Walk4_H_Right(HDC);
	int Paint_Walk1_H_Left(HDC);
	int Paint_Walk2_H_Left(HDC);
	int Paint_Walk3_H_Left(HDC);
	int Paint_Walk4_H_Left(HDC);
	int Paint_Jump_H(HDC);
	int Paint_Tackl_H(HDC);

	int Paint_Player_D(HDC);//デブ状態の描画
	int Paint_Walk1_D_Right(HDC);
	int Paint_Walk2_D_Right(HDC);
	int Paint_Walk3_D_Right(HDC);
	int Paint_Walk4_D_Right(HDC);
	int Paint_Walk1_D_Left(HDC);
	int Paint_Walk2_D_Left(HDC);
	int Paint_Walk3_D_Left(HDC);
	int Paint_Walk4_D_Left(HDC);
	int Paint_Jump_D(HDC);
	int Paint_Tackl_D(HDC);

	int Paint_Player_P(HDC);//ポチャ状態の描画
	int Paint_Walk1_P_Right(HDC);
	int Paint_Walk2_P_Right(HDC);
	int Paint_Walk3_P_Right(HDC);
	int Paint_Walk4_P_Right(HDC);
	int Paint_Walk1_P_Left(HDC);
	int Paint_Walk2_P_Left(HDC);
	int Paint_Walk3_P_Left(HDC);
	int Paint_Walk4_P_Left(HDC);
	int Paint_Jump_P(HDC);
	int Paint_Tackl_P(HDC);

	int Paint_Player_Y(HDC);//ヤセ状態の描画
	int Paint_Walk1_Y_Right(HDC);
	int Paint_Walk2_Y_Right(HDC);
	int Paint_Walk4_Y_Right(HDC);
	int Paint_Walk3_Y_Right(HDC);
	int Paint_Walk1_Y_Left(HDC);
	int Paint_Walk2_Y_Left(HDC);
	int Paint_Walk3_Y_Left(HDC);
	int Paint_Walk4_Y_Left(HDC);
	int Paint_Jump_Y(HDC);
	int Paint_Tackl_Y(HDC);

	int Paint_Player_G(HDC);//ガリ状態の描画
	int Paint_Walk1_G_Right(HDC);
	int Paint_Walk2_G_Right(HDC);
	int Paint_Walk3_G_Right(HDC);
	int Paint_Walk4_G_Right(HDC);
	int Paint_Walk1_G_Left(HDC);
	int Paint_Walk2_G_Left(HDC);
	int Paint_Walk3_G_Left(HDC);
	int Paint_Walk4_G_Left(HDC);
	int Paint_Jump_G(HDC);
	int Paint_Tackl_G(HDC);
	
	int Paint_Yarare(HDC);

	void char_strc(player_info *);


};
void PAINT::char_strc(player_info *p){
	pla = *p;
}




/************普通状態************************************************************/
int PAINT::Paint_Player_H(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Player);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_H_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_H_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_H(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_H(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackl);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/********************************************************************************/

/***********************デブ状態*************************************************/
int PAINT::Paint_Player_D(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Player);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width + 20, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_D_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_D_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_D(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width + 100, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_D(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackl);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/

/***********************ポチャ状態************************************************/
int PAINT::Paint_Player_P(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Player);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_P_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_P_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_P(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_P(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackl);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/


/***********************ヤセ状態**************************************************/
int PAINT::Paint_Player_Y(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Player);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 160, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_Y_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_Y_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_Y(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_Y(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackl);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/


/***********************ガリ状態*************************************************/
int PAINT::Paint_Player_G(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Player);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 139, 166, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_G_Right(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Right);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk1_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk2_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk2_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk3_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk3_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Walk4_G_Left(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Walk4_Left);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 60, 120, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Jump_G(HDC hdc){
	//デバイスコンテキストハンドル
	HDC hdc_work;
	//メモリデバイスコンテキストの作成
	hdc_work = CreateCompatibleDC(hdc);
	//オブジェクトの選択
	SelectObject(hdc_work, hb_Jump);
	//画像転送
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 207, 204, RGB(255, 255, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}

int PAINT::Paint_Tackl_G(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackl);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 215, 189, RGB(0, 0, 0));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/

