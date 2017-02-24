#include "tHead.h"

void tePaint(HDC hDC){
	//创建兼容性DC
	HDC hmemDC = CreateCompatibleDC(hDC);
	//创建一张纸
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDC, 350, 550);
	//关联起来
	SelectObject(hmemDC, hBitmapBack);

	PaintSqare(hmemDC);
	BitBlt(hDC, 0, 0, 350, 550, hmemDC, 0, 0, SRCCOPY);
	//释放DC
	BOOL DeletDC(hmenDC);
}

void PaintSqare(HDC hmemDC) {
	Rectangle(hmemDC, 0, 0, 240, 570);
}