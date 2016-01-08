#include "Itemdowner.h"


Itemdowner::Itemdowner(int x, int y)
{
	item.x = x;
	item.y = y;
	item_hb = (HBITMAP)LoadImage(NULL, TEXT("itemdown.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	itemtype = -1;
	item.onActive = 1;
}


Itemdowner::~Itemdowner()
{
}
