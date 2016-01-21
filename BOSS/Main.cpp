#pragma once
#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")


#include <windows.h>
#include <math.h>	// atan2()を使うために必要
#include <time.h>   // time()を使うのに必要
#include <assert.h>

//要素
#include"Boss\BossManager.h"
#include"Boss\BossAtackManager.h"
#include "Enemy\EnemyManager.h"
#include "Item\ItemManager.h"
#include"scroll.h"
#include"Block.h"
#include"timer.h"
#include"Ranking.h"
#include"SandStorm\SandStrom.h"


//ツール系
#include"Framerate\FrameRate.h"
#include"debugmsg.h"
#include<Thread>
#include<mmsystem.h>

//chara
#include "Paint_Player.h"
#include"player_info.h"

//設定等
#include"Option.h"



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// ウインドウプロシージャ関数


int SceneNum;

int Paint(HDC);
int Paint_BG(HDC,int);
int Init_Game();
int Get_Key(int);
int SceneChanger();

float S_time;		//現在のタイム
float r_time[5];					//int r_time[5];		//既存のタイム
char namae[15];


#define KEY_SPACE 32

HBITMAP menu_hb[5];	//タイトルやクリア画面

BYTE key_input_buff;// キーボード情報
BYTE key_buff[256];

HWND hWnd;


PAINT *paint_player_obj;
Scroll *scrobj;
Block *blobj;
EnemyManager *eobj;
BossManager *bsobj;
BossAtackManager *acobj;
ItemManager *iobj;
Timer *timeobj;

SandStrom sandstorm;
FrameRate frr;





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
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);      // ウィンドウ画面の色
	wc.lpszMenuName = NULL;                            // ウインドウメニュー（使用しない）
	wc.lpszClassName = TEXT("Window01");                // ウインドウクラス名

	// ウインドウクラスの登録
	if (!RegisterClass(&wc)) return FALSE;

	// ウインドウの作成
	hWnd = CreateWindow(
		TEXT("Window01"), TEXT("イダテン・チャッカー"),					// ウインドウのタイトル名
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,			// ウインドウスタイル
		CW_USEDEFAULT,												// ウィンドウの表示X座標
		CW_USEDEFAULT,												// ウィンドウの表示Y座標
		WINDOW_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,						// ウィンドウの幅
		WINDOW_HEIGHT + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// 高さ
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



static MCI_OPEN_PARMS mop;
static MCI_PLAY_PARMS mpp;
///////ウインドウプロシージャ関数//////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// 画像を読み込む準備
	HDC hdc;		// デバイスコンテキストハンドル
	PAINTSTRUCT ps; // ペイント構造体

	// バックバッファ用コンテキストハンドルと、ビットマップハンドルの準備
	static HDC hdc_back;	// 裏画面（バックバッファ）用デバイスコンテキストハンドル
	static HBITMAP hb_back;	// 裏画面（バックバッファ）用ビットマップハンドル


	switch (msg)
	{

	case MM_MCINOTIFY:
		if (wParam != MCI_NOTIFY_SUCCESSFUL) {
			return 0;
		}
		mciSendCommand((MCIDEVICEID)lParam, MCI_SEEK, MCI_SEEK_TO_START, 0);
		mciSendCommand((MCIDEVICEID)lParam, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

		break;
	case WM_USER + 1:	// ゲームループ（SendMessageから呼ばれる）

		// 結果の再描画　WM_PAINTを実行する
		InvalidateRect(hWnd, NULL, false);
		return 0;

	case WM_PAINT:	// 画面を描画する時の処理

		hdc = BeginPaint(hWnd, &ps);	// 描画の開始
		Paint(hdc_back);				// Paint関数へ
		


		//バックバッファに保存された画像を表画面に描画
		BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_back, 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);			// 描画の終了

		return 0;
	
	case WM_CREATE:

		mop.lpstrDeviceType = L"WaveAudio";
		mop.lpstrElementName = L"res/Sound/title.wav";
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
		mpp.dwCallback = (DWORD)hWnd;


		mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);


		frr.SetSampleNum(100);
		Init_Game();

		// 描画の開始
		hdc = GetDC(hWnd);
		// 互換デバイスコンテキストの作成
		hdc_back = CreateCompatibleDC(hdc);
		// 互換ビットマップの作成
		hb_back = CreateCompatibleBitmap(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);

		// オブジェクトの選択
		SelectObject(hdc_back, hb_back);
		// 描画の終了
		ReleaseDC(hWnd, hdc);

		//シーン用BITMAP
		menu_hb[Title] = (HBITMAP)LoadImage(NULL, TEXT("res/bgImage/title.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		menu_hb[End] = (HBITMAP)LoadImage(NULL, TEXT("res/bgImage/end.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		return 0;

	case WM_DESTROY:	// 最後にウインドウが閉じられた時の処理
		mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
		// デバイスコンテキストの解放
		DeleteDC(hdc_back);
		DeleteObject(hb_back);
		DeleteObject(menu_hb);
		PostQuitMessage(0);
		return 0;

	default:	// デフォルト処理
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

int Init_Game(){


	SceneNum = Title;


	return 0;
}







/*
オブジェクト優先度

Player Move
　|
  V
Scroll			背景描画のため。
  |
  V
Item
  |
  V
Player　Oil
　|
　V
 Enemy
  |
  V
BLOCK
  |
  V
Player　Paint


*/


int Paint(HDC hdc)
{
	static MCI_OPEN_PARMS SEOPEN;
	static MCI_PLAY_PARMS SEPLAY;

	static int cc;
	if (SceneNum == Title){
		Paint_BG(hdc,Title);		// 背景描画関数へ
		if (cc > 50){
			cc = Get_Key(cc);
			if (cc == 1){
			
					SEOPEN.lpstrDeviceType = L"WaveAudio";
					SEOPEN.lpstrElementName = L"res/SE/tackle.wav";

					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&SEOPEN);
					mciSendCommand(SEOPEN.wDeviceID, MCI_PLAY, 0, (DWORD)&SEPLAY);


					mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
					mop.lpstrElementName = L"res/Sound/stagebgm.wav";
					mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
					mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

			
				SceneChanger();
				eobj = new EnemyManager(SceneNum);
				iobj = new ItemManager(SceneNum);
				scrobj = new Scroll(SceneNum);
				blobj = new Block(SceneNum);
				paint_player_obj = new(PAINT);
				//oilobj = new(OIL);
				//paint_player_obj->obj2 = new(MOVE);

				timeobj = new(Timer);
				timeobj->WindowsTimer(hdc);		//windowsの起動からの時間の習得
				/*if (SceneNum == Boss)
				{
					bsobj = new BossManager(SceneNum);
				}*/

			}
		}

	}
	else if (SceneNum < 0){
		
		Paint_BG(hdc,-SceneNum);
		sandstorm.Start(hdc);

		if (cc > 1){

			mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);

			mop.lpstrElementName = L"res/Sound/stagebgm.wav";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
			mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

		

			SceneNum *= -1;	//マイナスの値になってるSceneNumを戻す
			delete scrobj;
			scrobj = new Scroll(SceneNum);

			delete blobj;
			blobj = new Block(SceneNum);

			delete eobj;
			if (SceneNum == Stage1 || SceneNum == Stage2){
				eobj = new EnemyManager(SceneNum);
			}
			delete bsobj;
			if (SceneNum == Boss){
				bsobj = new BossManager(SceneNum);
			}
			delete acobj;
			if (SceneNum == Boss){
				acobj = new BossAtackManager(SceneNum);
			}
			delete iobj;
			iobj = new ItemManager(SceneNum);
			if (SceneNum == Stage2){
				paint_player_obj->obj2->player.x = 120;
				paint_player_obj->obj2->player.y = 420;
			}
			if (SceneNum == Boss){
				paint_player_obj->obj2->player.x = 150;
				paint_player_obj->obj2->player.y = 600;
			}
			sandstorm.End();

			
		}
	}
	else if (SceneNum == Stage1 || SceneNum == Stage2){
		
		paint_player_obj->obj2->C_sts(paint_player_obj->obj->c_sts, &paint_player_obj->obj->Oil_Gage);
		paint_player_obj->obj2->Move();

		//Scroll
		scrobj->toPoint(&paint_player_obj->obj2->player);
		scrobj->scroll_kansu(hdc);
		//Block
		blobj->toPoint(&paint_player_obj->obj2->player);
		blobj->block_scroll(scrobj->Backimg_x, scrobj->Backimg_y);
		int aa = 0;
		aa = blobj->block_kansu(hdc);	//値を受け取っていたら次へ
		if (aa == 2){
			SceneNum++;
			SceneNum *= -1;
			cc = 0;
			sandstorm.Initialize(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
			//	DebugStringVal("%d", SceneNum, hdc, 200, 200, 20);
			sandstorm.Start(hdc);


			mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
			mop.lpstrElementName = L"res/Sound/SandStorm.wav";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
			mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, (DWORD)&mop);
		


			return 0;

		}


		//Enemy
		//-----------------------------
		eobj->chara_strc(&paint_player_obj->obj2->player);
		eobj->enemy_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
		eobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
		eobj->MainThread(hdc);

		paint_player_obj->obj->Item(eobj->GetDeadflag());		//アイテムを取得してゲージに変化があるか判断する(敵の場合は－１される）

		eobj->GetDeadflag(0);

		//オイルゲージ量など更新処理
		paint_player_obj->obj->Player_Sts();
		paint_player_obj->obj->Oil_Sts();


		//Item
		iobj->chara_strc(&paint_player_obj->obj2->player);
		iobj->item_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
		iobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
		iobj->MainThread(hdc);

		paint_player_obj->obj->Item(iobj->GetItemtype());		//アイテムを取得してゲージに変化があるか判断する
		//	DebugStringVal("%d", iobj->GetItemtype(), hdc, 300, 30, 20);

		iobj->GetItemtype(0);	//値の初期化。　しないとバグが出ます＾ｑ＾

		//オイルゲージ量など更新処理
		paint_player_obj->obj->Player_Sts();
		paint_player_obj->obj->Oil_Sts();


		//オイルとそのゲージの描画
		paint_player_obj->obj->Paint_Oil(hdc);
		paint_player_obj->obj->Paint_Gage(hdc);


		//移動量の最大値の抑制
		if (paint_player_obj->obj2->player.vx < -10)paint_player_obj->obj2->player.vx = -10;
		if (paint_player_obj->obj2->player.vy > 10)	paint_player_obj->obj2->player.vy = 10;

		paint_player_obj->obj2->player.x += paint_player_obj->obj2->player.vx;
		paint_player_obj->obj2->player.y += paint_player_obj->obj2->player.vy;

		//キャラが画面座標０より外へ出ないように抑制
		if (paint_player_obj->obj2->player.x < 0)	paint_player_obj->obj2->player.x = 0;
		if (paint_player_obj->obj2->player.y < 0)	paint_player_obj->obj2->player.y = 0;
		//	DebugStringFloat("%f",paint_player_obj->obj2->player.y,hdc,200,200,20);
		//以下描画処理
		paint_player_obj->char_strc(&paint_player_obj->obj2->player);
		paint_player_obj->Paint_Player(hdc);

		timeobj->StartTimer(hdc);	//プログラムが開始された時の時間の習得
		timeobj->ShowTime(hdc);

		
	}

	else if (SceneNum == Boss){

		paint_player_obj->obj2->C_sts(paint_player_obj->obj->c_sts, &paint_player_obj->obj->Oil_Gage);
		paint_player_obj->obj2->Move();

		//Scroll
		scrobj->toPoint(&paint_player_obj->obj2->player);
		scrobj->scroll_kansu(hdc);

		blobj->toPoint(&paint_player_obj->obj2->player);
		blobj->block_scroll(scrobj->Backimg_x, scrobj->Backimg_y);

		blobj->block_kansu(hdc);	//値を受け取っていたら次へ

		bsobj->chara_strc(&paint_player_obj->obj2->player);
		bsobj->BOSS_SCROLL(scrobj->BackMoveX, scrobj->BackMoveY);
		bsobj->STAGE_COOD(blobj->get_block_X(), blobj->get_block_Y());
		bsobj->MAIN(hdc);

		acobj->chara_strc(&paint_player_obj->obj2->player);
		acobj->Atack_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
		acobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
		acobj->Main(hdc);

		paint_player_obj->obj->Item(bsobj->GetDeadflag());		//アイテムを取得してゲージに変化があるか判断する(敵の場合は－１される）

		bsobj->GetDeadflag(0);

		//オイルゲージ量など更新処理
		paint_player_obj->obj->Player_Sts();
		paint_player_obj->obj->Oil_Sts();

		//Item
		iobj->chara_strc(&paint_player_obj->obj2->player);
		iobj->item_scroll(scrobj->BackMoveX, scrobj->BackMoveY);
		iobj->stage_coord(blobj->get_block_X(), blobj->get_block_Y());
		iobj->MainThread(hdc);

		paint_player_obj->obj->Item(iobj->GetItemtype());		//アイテムを取得してゲージに変化があるか判断する
		//	DebugStringVal("%d", iobj->GetItemtype(), hdc, 300, 30, 20);

		iobj->GetItemtype(0);	//値の初期化。　しないとバグが出ます＾ｑ＾

		//オイルゲージ量など更新処理
		paint_player_obj->obj->Player_Sts();
		paint_player_obj->obj->Oil_Sts();


		//オイルとそのゲージの描画
		paint_player_obj->obj->Paint_Oil(hdc);
		paint_player_obj->obj->Paint_Gage(hdc);

		//移動量の最大値の抑制
		if (paint_player_obj->obj2->player.vx < -10)paint_player_obj->obj2->player.vx = -10;
		if (paint_player_obj->obj2->player.vy > 10)	paint_player_obj->obj2->player.vy = 10;

		paint_player_obj->obj2->player.x += paint_player_obj->obj2->player.vx;
		paint_player_obj->obj2->player.y += paint_player_obj->obj2->player.vy;

		//キャラが画面座標０より外へ出ないように抑制
		if (paint_player_obj->obj2->player.x < 0)	paint_player_obj->obj2->player.x = 0;
		if (paint_player_obj->obj2->player.y < 0)	paint_player_obj->obj2->player.y = 0;
		//	DebugStringFloat("%f",paint_player_obj->obj2->player.y,hdc,200,200,20);

		//以下描画処理
		paint_player_obj->char_strc(&paint_player_obj->obj2->player);
		paint_player_obj->Paint_Player(hdc);

		timeobj->StartTimer(hdc);	//プログラムが開始された時の時間の習得
		timeobj->ShowTime(hdc);
		return 0;

	}
	
	/*else if (SceneNum == Boss) {
		if (cc > 10) {
			SceneNum = End;
			cc = 0;
		}
	}*/
	else if (SceneNum == End){
		Paint_BG(hdc,End);  //ed
		timeobj->ShowTime(hdc);//タイム描画
		Ranking_Load();		//ランキングロード
		Ranking_save(hdc);
		if (cc > 50){
			cc = Get_Key(cc);
			if (cc == 1){
				mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);

				mop.lpstrElementName = L"res/Sound/title.wav";
				mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
				mciSendCommand(mop.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mpp);

				SceneChanger();
				delete eobj;
				delete iobj;
				delete scrobj;
				delete blobj;
				delete paint_player_obj;
				delete timeobj;
				delete bsobj;
				delete acobj;
			}
		}
		
	}
	cc++;
	//DebugStringFloat("%2.2f", frr.GetFrameRate() / 10, hdc, 100, 50, 22);


	return 0;
}


///// キー入力関数 ///////////////////////////////////////////////////////
//スペースキーが押されていた場合１を返す
//それ以外は値をそのまま返します
int Get_Key(int count)
{
	GetKeyboardState(key_buff);
	key_input_buff = 0;

	if (key_buff[VK_SPACE] & 0x80){

		key_input_buff |= KEY_SPACE;
		return 1;
	}

	return count;
}

int Paint_BG(HDC hdc ,int Num){
	HDC hdc_work;
	hdc_work = CreateCompatibleDC(hdc);
	SelectObject(hdc_work, menu_hb[Num]);		// オブジェクトの選択
	BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_work, 0, 0, SRCCOPY);
	


	DeleteDC(hdc_work);// デバイスコンテキストの解放
	return 0;
}

int SceneChanger(){
	switch (key_input_buff)
	{
	case 32:
		
		if (SceneNum == Title){
			SceneNum = Stage2;
		}
		
		
		if (SceneNum == End){
			SceneNum = Title;
		}
		break;
	default:
		break;
	}
	return 0;
}

