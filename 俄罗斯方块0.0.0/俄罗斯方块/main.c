#include "tHead.h"


LRESULT CALLBACK PelouSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM IParam);
int __stdcall WinMain(HINSTANCE hinstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//初始化窗口类
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

	//注册窗口类
	if (RegisterClassEx(&te) == 0) {
		//出错了
		int a = GetLastError();
		return 0;
	}
	
	hWnd = CreateWindowEx(WS_EX_TOPMOST, "tetrisemain" ,"俄罗斯方块", WS_SYSMENU | WS_MINIMIZEBOX,500,150,350,550,NULL,NULL,hinstance,NULL);
	if (hWnd == NULL) {
		return 0;
	}

	//显示窗口
	ShowWindow(hWnd, nCmdShow);

	/*hmap = LoadBitmap(hinstance,
		MAKEINTRESOURCE(IDB_SMALL));*/

	//消息循环
	while (GetMessage(&mSg, NULL, 0, 0))
	{
		TranslateMessage(&mSg);//翻译消息
		DispatchMessage(&mSg);		//分发消息

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
