#include "tHead.h"


LRESULT CALLBACK PelouSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM IParam);
int __stdcall WinMain(HINSTANCE hinstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//��ʼ��������
	WNDCLASSEX te;
	HWND hWnd;
	MSG mSg;
	HBITMAP hmap;


	te.cbClsExtra = 0;
	te.cbSize = sizeof(WNDCLASSEX);
	te.cbWndExtra = 0;
	te.hbrBackground = (HBRUSH)COLOR_WINDOW;
	te.hCursor = LoadCursor(NULL, IDC_ARROW);
	te.hIcon = LoadIcon(hinstance,MAKEINTRESOURCE(102));
	te.hIconSm = NULL;
	te.hInstance = hinstance;
	te.lpfnWndProc = PelouSi;
	te.lpszClassName = "tetrisemain";
	te.lpszMenuName = NULL;
	te.style = CS_HREDRAW | CS_VREDRAW;

	//ע�ᴰ����
	if (RegisterClassEx(&te) == 0) {
		//������
		int a = GetLastError();
		return 0;
	}
	
	hWnd = CreateWindowEx(WS_EX_TOPMOST, "tetrisemain" ,"����˹����", WS_SYSMENU | WS_MINIMIZEBOX,500,150,350,550,NULL,NULL,hinstance,NULL);
	if (hWnd == NULL) {
		return 0;
	}

	//��ʾ����
	ShowWindow(hWnd, nCmdShow);

	/*hmap = LoadBitmap(hinstance,
		MAKEINTRESOURCE(IDB_SMALL));*/

	//��Ϣѭ��
	while (GetMessage(&mSg, NULL, 0, 0))
	{
		TranslateMessage(&mSg);//������Ϣ
		DispatchMessage(&mSg);		//�ַ���Ϣ

	}

	return 0;
}
LRESULT CALLBACK PelouSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM IParam) {
	PAINTSTRUCT pt;
	HDC hDC;

	switch (nMsg) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &pt);
		tePaint(hDC);
		EndPaint(hWnd, &pt);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, nMsg, wParam, IParam);
}
