#pragma comment(lib,"msimg32.lib")
#include<windows.h>
#include"Player_Status.h"
#include "Paint_Player.h"
#include"player_info.h"
#include "Player_Move.h"
#include"scroll.h"
#include "ItemManager.h"
#include<memory>	//unique_ptr	などを使うために必要



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//ウィンドウプロシージャ関数

int Paint(HDC);
int Init_Game();//初期化関数


PAINT Pobj;//オブジェクト宣言
OIL Oobj;
MOVE Mobj;
Scroll Sobj;


std::unique_ptr<ItemManager>iobj(new ItemManager);

//バックバッファ用
static HDC hdc_back;
static HBITMAP hb_back;


/////ウィンドウプロシージャ関数//////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;//ペイント構造体

	switch (msg)
	{
	case WM_USER+1:
		Mobj.Move();
		
		InvalidateRect(hWnd, NULL, false);
		return 0;

	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);
		

		Paint(hdc_back);
		BitBlt(hdc, 0, 0, 1100, 450, hdc_back, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_CREATE:
		
		Init_Game();//ゲーム初期化関数へ
	

		// 描画の開始
		hdc = GetDC(hWnd);

		//※※※ 追加 (BackBuffer領域の作成)※※※※※※※※※※※※※※
		// 互換デバイスコンテキストの作成
		hdc_back = CreateCompatibleDC(hdc);
		// 互換ビットマップの作成
		hb_back = CreateCompatibleBitmap(hdc, 1100, 450);
		// オブジェクトの選択
		SelectObject(hdc_back, hb_back);
		//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

		// 互換デバイスコンテキストの作成
		hdc = CreateCompatibleDC(NULL);
		// 描画の終了
		ReleaseDC(hWnd, hdc);
		

		hb_Player = (HBITMAP)LoadImage(NULL, TEXT("Player.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk_Right = (HBITMAP)LoadImage(NULL, TEXT("run1_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk2_Right = (HBITMAP)LoadImage(NULL, TEXT("run2_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk3_Right = (HBITMAP)LoadImage(NULL, TEXT("run3_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk4_Right = (HBITMAP)LoadImage(NULL, TEXT("run4_right.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk_Left = (HBITMAP)LoadImage(NULL, TEXT("run1_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk2_Left = (HBITMAP)LoadImage(NULL, TEXT("run2_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk3_Left = (HBITMAP)LoadImage(NULL, TEXT("run3_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Walk4_Left = (HBITMAP)LoadImage(NULL, TEXT("run4_left.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Jump = (HBITMAP)LoadImage(NULL, TEXT("Jump.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hb_Tackl = (HBITMAP)LoadImage(NULL, TEXT("Tackl.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		Oobj.hb_OilGage = (HBITMAP)LoadImage(NULL, TEXT("Oil.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		Oobj.hb_OilPower = (HBITMAP)LoadImage(NULL, TEXT("OilPower.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				
		return 0;

	case WM_DESTROY:
		//DeleteDC(hdc_back);
		//オブジェクトの解放
		//DeleteObject(hb_back);
		
		DeleteObject(hb_Player);
		DeleteObject(hb_Walk_Right);
		DeleteObject(hb_Walk2_Right);
		DeleteObject(hb_Walk3_Right);
		DeleteObject(hb_Walk4_Right);
		DeleteObject(hb_Walk_Left);
		DeleteObject(hb_Walk2_Left);
		DeleteObject(hb_Walk3_Left);
		DeleteObject(hb_Walk4_Left);
		DeleteObject(hb_Jump);
		DeleteObject(hb_Tackl);
		DeleteObject(Oobj.hb_OilGage);
		DeleteObject(Oobj.hb_OilPower);


		PostQuitMessage(0);
		return 0;	
		
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
/////メイン描画/////////
int Paint(HDC hdc)
{
	
	Oobj.Player_Sts();
	Oobj.Oil_Sts();
	Mobj.C_sts(Oobj.c_sts,&Oobj.Oil_Gage);
	

	Sobj.toPoint(&player);
	Sobj.scroll_kansu(hdc);

	iobj->chara_strc(player);
	iobj->item_scroll(Sobj.BackMoveX, Sobj.BackMoveY);
	iobj->MainLoop(hdc);
	

	Oobj.Item(iobj->GetItemtype());
	iobj->GetItemtype(0);



	Oobj.Paint_Oil(hdc);
	Oobj.Paint_Gage(hdc);

	Pobj.char_strc(&player);
	if (Oobj.c_sts == HUTHU && a_flg == A_STAND){
		Pobj.Paint_Player_H(hdc);//自機描画関数へ
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_H_Right(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_JUMP){
		Pobj.Paint_Jump_H(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_TACKL){
		Pobj.Paint_Tackl_H(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_H_Left(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_H_Left(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_H_Left(hdc);
	}
	if (Oobj.c_sts == HUTHU && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_H_Left(hdc);
	}

	if (Oobj.c_sts == DEBU && a_flg == A_STAND){
		Pobj.Paint_Player_D(hdc);//自機描画関数へ
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_D_Right(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_JUMP){
		Pobj.Paint_Jump_D(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_TACKL){
		Pobj.Paint_Tackl_D(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_D_Left(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_D_Left(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_D_Left(hdc);
	}
	if (Oobj.c_sts == DEBU && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_D_Left(hdc);
	}

	if (Oobj.c_sts == POTYA && a_flg == A_STAND){
		Pobj.Paint_Player_P(hdc);//自機描画関数へ
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_P_Right(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_JUMP){
		Pobj.Paint_Jump_P(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_TACKL){
		Pobj.Paint_Tackl_P(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_P_Left(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_P_Left(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_P_Left(hdc);
	}
	if (Oobj.c_sts == POTYA && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_P_Left(hdc);
	}

	if (Oobj.c_sts == TYOIYASE && a_flg == A_STAND){
		Pobj.Paint_Player_Y(hdc);//自機描画関数へ
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_Y_Right(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_JUMP){
		Pobj.Paint_Jump_Y(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_TACKL){
		Pobj.Paint_Tackl_Y(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_Y_Left(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_Y_Left(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_Y_Left(hdc);
	}
	if (Oobj.c_sts == TYOIYASE && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_Y_Left(hdc);
	}

	if (Oobj.c_sts == GARI && a_flg == A_STAND){
		Pobj.Paint_Player_G(hdc);//自機描画関数へ
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK1_Right){
		Pobj.Paint_Walk1_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK2_Right){
		Pobj.Paint_Walk2_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK3_Right){
		Pobj.Paint_Walk3_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK4_Right){
		Pobj.Paint_Walk4_G_Right(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK1_Left){
		Pobj.Paint_Walk1_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK2_Left){
		Pobj.Paint_Walk2_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK3_Left){
		Pobj.Paint_Walk3_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_WALK4_Left){
		Pobj.Paint_Walk4_G_Left(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_JUMP){
		Pobj.Paint_Jump_G(hdc);
	}
	if (Oobj.c_sts == GARI && a_flg == A_TACKL){
		Pobj.Paint_Tackl_G(hdc);
	}

	return 0;
}




/////初期化関数//////////
int Init_Game()
{
	player.x = 100;
	player.y = 200;
	player.width = 100;
	player.height = 100;
	player.attack_x = 30;
	player.attack_mukou = 90;

	x = 0;
	grv = 1;
	player.c_flg = STAND;
	a_flg = A_STAND;
	a_cnt = 0;
	return 0;
}


/////メイン関数///////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	MSG msg;

	// ウインドウクラス構造体
	ZeroMemory(&wc, sizeof(WNDCLASS));
	wc.style = CS_HREDRAW | CS_VREDRAW;         // ウインドウスタイル
	wc.lpfnWndProc = (WNDPROC)WndProc;                // ウインドウプロシージャアドレス
	wc.cbClsExtra = 0;                               // 補助領域サイズ（使用しない）
	wc.cbWndExtra = 0;                               // 補助領域サイズ（使用しない）
	wc.hInstance = hInstance;                       // インスタンスハンドル
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // アイコン
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);     // マウスカーソル
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);       // ウィンドウ画面の色
	wc.lpszMenuName = NULL;                            // ウインドウメニュー（使用しない）
	wc.lpszClassName = TEXT("Window01");                // ウインドウクラス名

	// ウインドウクラスの登録
	if (!RegisterClass(&wc))return FALSE;

	// ウインドウの作成
	HWND hWnd = CreateWindow(
		TEXT("Window01"), TEXT("char"),					// ウインドウのタイトル名
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,			// ウインドウスタイル
		CW_USEDEFAULT,												// ウィンドウの表示X座標
		CW_USEDEFAULT,												// ウィンドウの表示Y座標
		1100 + GetSystemMetrics(SM_CXDLGFRAME) * 2,						// ウィンドウの幅
		450 + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// 高さ
		NULL,														// 親ウインドウ
		NULL,														// ウインドウメニュー
		hInstance,													// インスタンスハンドル
		NULL);														 // WM_CREATE情報

	// ウインドウの表示
	ShowWindow(hWnd, nCmdShow);                         // 表示状態の設定
	UpdateWindow(hWnd);                                 // クライアント領域の更新

	// メッセージループ
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else
		{
			// WM_USER+1へ　(ここがゲームループ)
			SendMessage(hWnd, WM_USER + 1, 0, 0);

			// スリープ関数へ
			Sleep(20);
		}
	}

	return msg.wParam;
}
