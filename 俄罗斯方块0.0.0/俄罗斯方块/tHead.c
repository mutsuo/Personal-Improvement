#include "tHead.h"

void tePaint(HDC hDC){
	//����������DC
	HDC hmemDC = CreateCompatibleDC(hDC);
	//����һ��ֽ
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDC, 350, 550);
	//��������
	SelectObject(hmemDC, hBitmapBack);

	PaintSqare(hmemDC);
	BitBlt(hDC, 0, 0, 350, 550, hmemDC, 0, 0, SRCCOPY);
	//�ͷ�DC
	BOOL DeletDC(hmenDC);
}

void PaintSqare(HDC hmemDC) {
	Rectangle(hmemDC, 0, 0, 240, 570);
}