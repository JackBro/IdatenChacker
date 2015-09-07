#include "Itemclass.h"


Itemclass::Itemclass()
{
	item.x = 0;
	item.y = 0;
	item.width = 40;
	item.height = 50;
	item.onActive = 0;

	itemID = 0;
}


Itemclass::~Itemclass()
{
}


//•`‰æ—p
int Itemclass::Item_paint(HDC hdc){

	itemhdc = hdc;

	if (item.onActive & 1){

		HDC hdc_work;
		hdc_work = CreateCompatibleDC(hdc);
		SelectObject(hdc_work, item_hb);
		int ex = item.x;
		int ey = item.y;

		TransparentBlt(hdc, ex, ey, item.width, item.height, hdc_work, 0, 0, item.width, item.height, RGB(0, 0, 255));
		DeleteDC(hdc_work);

	}
	return 0;


}

int Itemclass::chara_strc(player_info *tp){
	plstats = tp;
	return 0;
}

int Itemclass::hit_itemcheck(){
	if (item.onActive & 1){
		//“–‚½‚è”»’è@ŽlŠpŒ`
		int ex = item.x;
		int ey = item.y;
		int ew = ex + item.width;
		int eh = ey + item.height;
		int px = (int)plstats->x;
		int py = (int)plstats->y;
		int pw = px + plstats->width;
		int ph = py + plstats->height;

		if (ex <= pw && px <= ew && ey <= ph && py <= eh){
			item.onActive = 0;
			return itemtype;
		}
	}
	return 0;
}


int Itemclass::item_scroll(int x, int y){
	item.x += x;
	item.y += y;
	return 0;
}