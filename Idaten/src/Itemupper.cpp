#include "Itemupper.h"


Itemupper::Itemupper(int x,int y)
{
	item.x = x;
	item.y = y;
	 item_hb = (HBITMAP)LoadImage(NULL, TEXT("itemup.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	 itemtype = 1;
	 item.onActive = 1;
}


Itemupper::~Itemupper()
{
}
