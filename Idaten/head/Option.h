#pragma once

//////////////ブロック/////////////
#define MAP_WIDTH  220   //画面の横幅、  ブロックの横の要素数
#define MAP_HEIGHT 48    //画面の縦幅　　ブロックの縦の要素数
  
#define CHIP_SIZE   30   //一つのブロックのサイズ 

#define PLAYER_HEIGHT 640
#define PLAYER_WIDTH  1280


#define WINDOW_WIDTH	1100					//画面横サイズ
#define WINDOW_HEIGHT	360						//画面縦サイズ

#define BLOCK_PAINT_X  WINDOW_WIDTH/CHIP_SIZE		//ブロック横個数
#define BLOCK_PAINT_Y  WINDOW_HEIGHT/CHIP_SIZE		//ブロック縦個数


#define MAX_LENGTH 21  //横用めり込み許容値 
#define MAX_LENGTH02 20 //縦用めり込み許容値


//////////////////////////////////////////////////////


// マクロの定義
#define KEY_UP		1
#define KEY_LEFT	2
#define KEY_RIGHT	8


//敵
#define ENEMYMAX 5
#define ENEMY_SPAWN_INTERVAL 200

//アイテム
#define ITEM_SPAWN_INTERVAL 100