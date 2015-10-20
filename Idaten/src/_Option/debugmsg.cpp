#include"debugmsg.h"

///// 文字の表示関数 /////////////////////////////////////////////////////
int Str_Put(HDC hdc, int x, int y, int font_size, UINT color, TCHAR *str)
{
	HFONT hfont, oldfont;

	hfont = CreateFont(
		font_size,					// フォントの高さ
		0,							// 文字送り方向の角度
		0,							// ベースラインの角度
		0,							// フォントの太さ
		FW_DONTCARE,				// 平均文字幅
		FALSE, //or TRUE			// 斜体にするかどうか
		FALSE,						// 下線を付けるかどうか
		FALSE,						// 取り消し線を付けるかどうか
		SHIFTJIS_CHARSET,			// 文字セットの識別子
		OUT_DEFAULT_PRECIS,			// 出力精度
		CLIP_DEFAULT_PRECIS,		// クリッピング精度
		DEFAULT_QUALITY,			// 出力品質
		DEFAULT_PITCH | FF_DONTCARE,// ピッチとファミリ
		//			TEXT("ＭＳ 明朝")			// フォント名
		TEXT("HG創英角ﾎﾟｯﾌﾟ体")
		);

	if (hfont == NULL)
	{
		MessageBox(NULL, TEXT("フォント失敗"), TEXT("Error"), MB_OK);
		return 0;
	}

	SetBkMode(hdc, TRANSPARENT);			//背景の透過
	SetTextColor(hdc, color);				//色指定
	oldfont = (HFONT)SelectObject(hdc, hfont);//フォント指定

	//表示 (2バイト文字使用のため char → TCHAR に変更)
	TextOut(hdc, x, y, (LPCWSTR)str, lstrlen(str));

	SelectObject(hdc, oldfont);				//フォント指定戻し
	DeleteObject(hfont);

	return 0;
}
