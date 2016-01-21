#pragma once


#include "Paint_Player.h"

void PAINT::char_strc(player_info *p){
	pla = *p;
}

int PAINT::Paint_Player(HDC hdc){
	
	
 	if (obj->c_sts == HUTHU && obj2->a_flg == A_STAND1){
		Paint_Stand00_H(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_STAND1_Left){
		Paint_Stand00_H_Left(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK3_Right){
		Paint_Run02_H_Right(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK5_Right){
		Paint_Run04_H_Right(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK8_Right){
		Paint_Run07_H_Right(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK12_Right){
		Paint_Run11_H_Right(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK14_Right){
		Paint_Run13_H_Right(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK3_Left){
		Paint_Run02_H_Left(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK5_Left){
		Paint_Run04_H_Left(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK8_Left){
		Paint_Run07_H_Left(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK12_Left){
		Paint_Run11_H_Left(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_WALK14_Left){
		Paint_Run13_H_Left(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_JUMP){
		Paint_Jump_Right_H(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_JUMP_Left){
		Paint_Jump_Left_H(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_TACKLE){
		Paint_Tackle00_H(hdc);
		pla.width = 30;
	}
	if (obj->c_sts == HUTHU && obj2->a_flg == A_TACKLE_Left){
		Paint_Tackle01_H_Left(hdc);
		pla.width = 30;
	}


	//一番重い状態
	if (obj->c_sts == DEBU && obj2->a_flg == A_STAND1){
		Paint_Stand00_D(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_STAND1_Left){
		Paint_Stand00_D_Left(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK3_Right){
		Paint_Run02_D_Right(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK5_Right){
		Paint_Run04_D_Right(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK8_Right){
		Paint_Run07_D_Right(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK12_Right){
		Paint_Run11_D_Right(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK14_Right){
		Paint_Run13_D_Right(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK3_Left){
		Paint_Run02_D_Left(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK5_Left){
		Paint_Run04_D_Left(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK8_Left){
		Paint_Run07_D_Left(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK12_Left){
		Paint_Run11_D_Left(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_WALK14_Left){
		Paint_Run13_D_Left(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_JUMP){
		Paint_Jump_Right_D(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_JUMP_Left){
		Paint_Jump_Left_D(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_TACKLE){
		Paint_Tackle00_D(hdc);
		pla.width = 45;
	}
	if (obj->c_sts == DEBU && obj2->a_flg == A_TACKLE_Left){
		Paint_Tackle01_D_Left(hdc);
		pla.width = 45;
	}

	//一番中の上状態
	if (obj->c_sts == POTYA && obj2->a_flg == A_STAND1){
		Paint_Stand00_P(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_STAND1_Left){
		Paint_Stand00_P_Left(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK3_Right){
		Paint_Run02_P_Right(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK5_Right){
		Paint_Run04_P_Right(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK8_Right){
		Paint_Run07_P_Right(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK12_Right){
		Paint_Run11_P_Right(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK14_Right){
		Paint_Run13_P_Right(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK3_Left){
		Paint_Run02_P_Left(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK5_Left){
		Paint_Run04_P_Left(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK8_Left){
		Paint_Run07_P_Left(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK12_Left){
		Paint_Run11_P_Left(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_WALK14_Left){
		Paint_Run13_P_Left(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_JUMP){
		Paint_Jump_Right_P(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_JUMP_Left){
		Paint_Jump_Left_P(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_TACKLE){
		Paint_Tackle00_P(hdc);
		pla.width = 38;
	}
	if (obj->c_sts == POTYA && obj2->a_flg == A_TACKLE_Left){
		Paint_Tackle01_P_Left(hdc);
		pla.width = 38;
	}

	//中の下状態
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_STAND1){
		Paint_Stand00_Y(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_STAND1_Left){
		Paint_Stand00_Y_Left(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK3_Right){
		Paint_Run02_Y_Right(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK5_Right){
		Paint_Run04_Y_Right(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK8_Right){
		Paint_Run07_Y_Right(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK12_Right){
		Paint_Run11_Y_Right(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK14_Right){
		Paint_Run13_Y_Right(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK3_Left){
		Paint_Run02_Y_Left(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK5_Left){
		Paint_Run04_Y_Left(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK8_Left){
		Paint_Run07_Y_Left(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK12_Left){
		Paint_Run11_Y_Left(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_WALK14_Left){
		Paint_Run13_Y_Left(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_JUMP){
		Paint_Jump_Right_Y(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_JUMP_Left){
		Paint_Jump_Left_Y(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_TACKLE){
		Paint_Tackle00_Y(hdc);
		pla.width = 25;
	}
	if (obj->c_sts == TYOIYASE && obj2->a_flg == A_TACKLE_Left){
		Paint_Tackle01_Y_Left(hdc);
		pla.width = 25;
	}

	//一番軽い状態
	if (obj->c_sts == GARI && obj2->a_flg == A_STAND1){
		Paint_Stand00_G(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_STAND1_Left){
		Paint_Stand00_G_Left(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK3_Right){
		Paint_Run02_G_Right(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK5_Right){
		Paint_Run04_G_Right(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK8_Right){
		Paint_Run07_G_Right(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK12_Right){
		Paint_Run11_G_Right(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK14_Right){
		Paint_Run13_G_Right(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK3_Left){
		Paint_Run02_G_Left(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK5_Left){
		Paint_Run04_G_Left(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK8_Left){
		Paint_Run07_G_Left(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK12_Left){
		Paint_Run11_G_Left(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_WALK14_Left){
		Paint_Run13_G_Left(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_JUMP){
		Paint_Jump_Right_G(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_JUMP_Left){
		Paint_Jump_Left_G(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_TACKLE){
		Paint_Tackle00_G(hdc);
		pla.width = 22;
	}
	if (obj->c_sts == GARI && obj2->a_flg == A_TACKLE_Left){
		Paint_Tackle01_G_Left(hdc);
		pla.width = 22;
	}

	return 0;
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

int PAINT::Paint_Stand00_H_Left(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00_Left);
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

int PAINT::Paint_Tackle01_H_Left(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle01);
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

int PAINT::Paint_Stand00_D_Left(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00_Left);
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

int PAINT::Paint_Tackle01_D_Left(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle01);
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

int PAINT::Paint_Stand00_P_Left(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00_Left);
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

int PAINT::Paint_Tackle01_P_Left(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle01);
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

int PAINT::Paint_Stand00_Y_Left(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00_Left);
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

int PAINT::Paint_Tackle01_Y_Left(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle01);
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

int PAINT::Paint_Stand00_G_Left(HDC hdc)
{
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Stand00_Left);
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

int PAINT::Paint_Tackle01_G_Left(HDC hdc){
	// デバイスコンテキストハンドル
	HDC hdc_work;
	// メモリデバイスコンテキストを作成
	hdc_work = CreateCompatibleDC(hdc);
	// オブジェクトの選択
	SelectObject(hdc_work, hb_Tackle01);
	// 画像を転送する
	TransparentBlt(hdc, pla.x, pla.y, pla.width, pla.height, hdc_work, 0, 0, 227, 394, RGB(0, 0, 255));
	//デバイスコンテキストの解放
	DeleteDC(hdc_work);
	return 0;
}
/*********************************************************************************/
