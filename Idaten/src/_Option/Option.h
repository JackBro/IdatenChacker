#pragma once

//////////////ブロック/////////////
#define MAP_WIDTH  220   //画面の横幅、  ブロックの横の要素数
#define MAP_HEIGHT 48    //画面の縦幅　　ブロックの縦の要素数


#define BLOCK_PAINT_X  WINDOW_WIDTH/CHIP_SIZE		//ブロック横個数
#define BLOCK_PAINT_Y  WINDOW_HEIGHT/CHIP_SIZE		//ブロック縦個数

#define STAGE2_WIDTH 320
#define STAGE2_HEIGHT 48

#define BOSS_STAGE_WIDTH 220
#define BOSS_STAGE_HEIGHT 48

#define CHIP_SIZE   30   //一つのブロックのサイズ 

#define PLAYER_HEIGHT 640
#define PLAYER_WIDTH  1280

//画面サイズは１６：９
#define WINDOW_WIDTH	(16*70)					//画面横サイズ 1120
#define WINDOW_HEIGHT	(9*70)					//画面縦サイズ	630



#define MAX_LENGTH 21  //横用めり込み許容値 
#define MAX_LENGTH02 20 //縦用めり込み許容値


//////////////////////////////////////////////////////


// マクロの定義
#define KEY_UP		1
#define KEY_LEFT	2
#define KEY_RIGHT	8


//敵
#define ENEMYMAX 4
#define ENEMY_SPAWN_INTERVAL 100

//アイテム
#define ITEM_SPAWN_INTERVAL 80

enum Scene{ Title, End, Stage1,Stage2, Boss};