#pragma once

#include"player_info.h"
#include "Player_Move.h"
#include "Player_Status.h"





class PAINT{
	//HDC hdc;
	//ÉLÉÉÉâÉNÉ^Å[
	HBITMAP hb_Stand00 = (HBITMAP)LoadImage(NULL, TEXT("stand_000.bmp"),
	IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand01 = (HBITMAP)LoadImage(NULL, TEXT("stand_001.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand02 = (HBITMAP)LoadImage(NULL, TEXT("stand_002.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand03 = (HBITMAP)LoadImage(NULL, TEXT("stand_003.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand04 = (HBITMAP)LoadImage(NULL, TEXT("stand_004.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand05 = (HBITMAP)LoadImage(NULL, TEXT("stand_005.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand06 = (HBITMAP)LoadImage(NULL, TEXT("stand_006.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand07 = (HBITMAP)LoadImage(NULL, TEXT("stand_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand08 = (HBITMAP)LoadImage(NULL, TEXT("stand_008.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand09 = (HBITMAP)LoadImage(NULL, TEXT("stand_009.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HBITMAP hb_Run00_Right = (HBITMAP)LoadImage(NULL, TEXT("run_000.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run01_Right = (HBITMAP)LoadImage(NULL, TEXT("run_001.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run02_Right = (HBITMAP)LoadImage(NULL, TEXT("run_002.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run03_Right = (HBITMAP)LoadImage(NULL, TEXT("run_003.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run04_Right = (HBITMAP)LoadImage(NULL, TEXT("run_004.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run05_Right = (HBITMAP)LoadImage(NULL, TEXT("run_005.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run06_Right = (HBITMAP)LoadImage(NULL, TEXT("run_006.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run07_Right = (HBITMAP)LoadImage(NULL, TEXT("run_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run08_Right = (HBITMAP)LoadImage(NULL, TEXT("run_008.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run09_Right = (HBITMAP)LoadImage(NULL, TEXT("run_009.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run10_Right = (HBITMAP)LoadImage(NULL, TEXT("run_010.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run11_Right = (HBITMAP)LoadImage(NULL, TEXT("run_011.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run12_Right = (HBITMAP)LoadImage(NULL, TEXT("run_012.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run13_Right = (HBITMAP)LoadImage(NULL, TEXT("run_013.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run14_Right = (HBITMAP)LoadImage(NULL, TEXT("run_014.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HBITMAP hb_Run00_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_000.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run01_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_001.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run02_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_002.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run03_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_003.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run04_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_004.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run05_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_005.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run06_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_006.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run07_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run08_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_008.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run09_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_009.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run10_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_010.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run11_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_011.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run12_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_012.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run13_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_013.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run14_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_014.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HBITMAP hb_Jump_Right = (HBITMAP)LoadImage(NULL, TEXT("run_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Jump_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HBITMAP hb_Tackle00 = (HBITMAP)LoadImage(NULL, TEXT("tackle_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

public:
	player_info pla;
	~PAINT(){
 DeleteObject(hb_Stand00), DeleteObject(hb_Stand01), DeleteObject(hb_Stand03), DeleteObject(hb_Stand04), DeleteObject(hb_Stand05), 
		DeleteObject(hb_Stand06), DeleteObject(hb_Stand07), DeleteObject(hb_Stand08), DeleteObject(hb_Stand09);
 delete obj;
 delete obj2;
	}

	OIL *obj;
	MOVE  *obj2;
	PAINT *obj3;

	PAINT(){
	obj = new(OIL);
	obj2 = new(MOVE);

	}

	int Paint_Stand00_H(HDC);//ïÅí èÛë‘ÇÃï`âÊ
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

	int Paint_Stand00_D(HDC);//ÉfÉuèÛë‘ÇÃï`âÊ
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

	int Paint_Stand00_P(HDC);//É|É`ÉÉèÛë‘ÇÃï`âÊ
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

	int Paint_Stand00_Y(HDC);//ÉÑÉZèÛë‘ÇÃï`âÊ
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

	int Paint_Stand00_G(HDC);//ÉKÉäèÛë‘ÇÃï`âÊ
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
	
	int Paint_Player(HDC);

	void char_strc(player_info *);

};
