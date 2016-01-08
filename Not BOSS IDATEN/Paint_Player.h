#pragma once

#include"player_info.h"
#include "Player_Move.h"
#include "Player_Status.h"





class PAINT{
	//HDC hdc;
	//ÉLÉÉÉâÉNÉ^Å[
	HBITMAP hb_Stand00 = (HBITMAP)LoadImage(NULL, TEXT("stand_000.bmp"),
	    IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Stand00_Left = (HBITMAP)LoadImage(NULL, TEXT("stand_000_left.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	

	HBITMAP hb_Run00_Right = (HBITMAP)LoadImage(NULL, TEXT("run_000.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run02_Right = (HBITMAP)LoadImage(NULL, TEXT("run_002.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run04_Right = (HBITMAP)LoadImage(NULL, TEXT("run_004.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run07_Right = (HBITMAP)LoadImage(NULL, TEXT("run_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run11_Right = (HBITMAP)LoadImage(NULL, TEXT("run_011.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run13_Right = (HBITMAP)LoadImage(NULL, TEXT("run_013.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HBITMAP hb_Run00_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_000.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run02_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_002.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run04_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_004.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run07_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run11_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_011.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Run13_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_013.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HBITMAP hb_Jump_Right = (HBITMAP)LoadImage(NULL, TEXT("run_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Jump_Left = (HBITMAP)LoadImage(NULL, TEXT("run_left_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HBITMAP hb_Tackle00 = (HBITMAP)LoadImage(NULL, TEXT("tackle_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP hb_Tackle01 = (HBITMAP)LoadImage(NULL, TEXT("tackle_left_007.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

public:
	player_info pla;
	~PAINT(){
 
 delete obj;
 delete obj2;
	}

	OIL *obj;
	MOVE  *obj2;

	PAINT(){
	obj = new(OIL);
	obj2 = new(MOVE);
	}

	int Paint_Stand00_H(HDC);//ïÅí èÛë‘ÇÃï`âÊ
	int Paint_Run00_H_Right(HDC);
	int Paint_Run02_H_Right(HDC);
	int Paint_Run04_H_Right(HDC);
	int Paint_Run07_H_Right(HDC);
	int Paint_Run11_H_Right(HDC);
	int Paint_Run13_H_Right(HDC);
	int Paint_Stand00_H_Left(HDC);
	int Paint_Run00_H_Left(HDC);
	int Paint_Run02_H_Left(HDC);
	int Paint_Run04_H_Left(HDC);
	int Paint_Run07_H_Left(HDC);
	int Paint_Run11_H_Left(HDC);
	int Paint_Run13_H_Left(HDC);
	int Paint_Jump_Right_H(HDC);
	int Paint_Jump_Left_H(HDC);
	int Paint_Tackle00_H(HDC);
	int Paint_Tackle01_H_Left(HDC);

	int Paint_Stand00_D(HDC);//ÉfÉuèÛë‘ÇÃï`âÊ
	int Paint_Run00_D_Right(HDC);
	int Paint_Run02_D_Right(HDC);
	int Paint_Run04_D_Right(HDC);
	int Paint_Run07_D_Right(HDC);
	int Paint_Run11_D_Right(HDC);
	int Paint_Run13_D_Right(HDC);
	int Paint_Stand00_D_Left(HDC);
	int Paint_Run00_D_Left(HDC);
	int Paint_Run02_D_Left(HDC);
	int Paint_Run04_D_Left(HDC);
	int Paint_Run07_D_Left(HDC);
	int Paint_Run11_D_Left(HDC);
	int Paint_Run13_D_Left(HDC);
	int Paint_Jump_Right_D(HDC);
	int Paint_Jump_Left_D(HDC);
	int Paint_Tackle00_D(HDC);
	int Paint_Tackle01_D_Left(HDC);

	int Paint_Stand00_P(HDC);//É|É`ÉÉèÛë‘ÇÃï`âÊ
	int Paint_Run00_P_Right(HDC);
	int Paint_Run02_P_Right(HDC);
	int Paint_Run04_P_Right(HDC);
	int Paint_Run07_P_Right(HDC);
	int Paint_Run11_P_Right(HDC);
	int Paint_Run13_P_Right(HDC);
	int Paint_Stand00_P_Left(HDC);
	int Paint_Run00_P_Left(HDC);
	int Paint_Run02_P_Left(HDC);
	int Paint_Run04_P_Left(HDC);
	int Paint_Run07_P_Left(HDC);
	int Paint_Run11_P_Left(HDC);
	int Paint_Run13_P_Left(HDC);
	int Paint_Jump_Right_P(HDC);
	int Paint_Jump_Left_P(HDC);
	int Paint_Tackle00_P(HDC);
	int Paint_Tackle01_P_Left(HDC);

	int Paint_Stand00_Y(HDC);//ÉÑÉZèÛë‘ÇÃï`âÊ
	int Paint_Run00_Y_Right(HDC);
	int Paint_Run02_Y_Right(HDC);
	int Paint_Run04_Y_Right(HDC);
	int Paint_Run07_Y_Right(HDC);
	int Paint_Run11_Y_Right(HDC);
	int Paint_Run13_Y_Right(HDC);
	int Paint_Stand00_Y_Left(HDC);
	int Paint_Run00_Y_Left(HDC);
	int Paint_Run02_Y_Left(HDC);
	int Paint_Run04_Y_Left(HDC);
	int Paint_Run07_Y_Left(HDC);
	int Paint_Run11_Y_Left(HDC);
	int Paint_Run13_Y_Left(HDC);
	int Paint_Jump_Right_Y(HDC);
	int Paint_Jump_Left_Y(HDC);
	int Paint_Tackle00_Y(HDC);
	int Paint_Tackle01_Y_Left(HDC);

	int Paint_Stand00_G(HDC);//ÉKÉäèÛë‘ÇÃï`âÊ
	int Paint_Run00_G_Right(HDC);
	int Paint_Run02_G_Right(HDC);
	int Paint_Run04_G_Right(HDC);
	int Paint_Run07_G_Right(HDC);
	int Paint_Run11_G_Right(HDC);
	int Paint_Run13_G_Right(HDC);
	int Paint_Stand00_G_Left(HDC);
	int Paint_Run00_G_Left(HDC);
	int Paint_Run02_G_Left(HDC);
	int Paint_Run04_G_Left(HDC);
	int Paint_Run07_G_Left(HDC);
	int Paint_Run11_G_Left(HDC);
	int Paint_Run13_G_Left(HDC);
	int Paint_Jump_Right_G(HDC);
	int Paint_Jump_Left_G(HDC);
	int Paint_Tackle00_G(HDC);
	int Paint_Tackle01_G_Left(HDC);
	
	int Paint_Yarare(HDC);
	
	int Paint_Player(HDC);

	void char_strc(player_info *);

};
