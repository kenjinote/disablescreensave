#define UNICODE
#pragma comment(linker,"/opt:nowin98")
#include<windows.h>

TCHAR szClassName[]=TEXT("Disable ScreenSaver");

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE:
			CreateWindow(TEXT("Button"),TEXT("スクリーンセーバー無効"),WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX,8,8,256,32,hWnd,(HMENU)100,((LPCREATESTRUCT)(lParam))->hInstance,0);
			break;
		case WM_SYSCOMMAND:
			if(IsDlgButtonChecked(hWnd,100)&&wParam==SC_SCREENSAVE)
				break;
			else
				return DefWindowProc(hWnd,msg,wParam,lParam);
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd,msg,wParam,lParam);
	}
	return 0;
}

EXTERN_C void __cdecl WinMainCRTStartup()
{
	MSG msg;
	HINSTANCE hInstance=GetModuleHandle(0);
	WNDCLASS wndclass={CS_HREDRAW|CS_VREDRAW,WndProc,0,0,hInstance,0,LoadCursor(0,IDC_ARROW),(HBRUSH)(COLOR_WINDOW+1),0,szClassName};
	RegisterClass(&wndclass);
	HWND hWnd=CreateWindow(szClassName,TEXT("Disable ScreenSaver"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,CW_USEDEFAULT,0,0,0,hInstance,0);
	ShowWindow(hWnd,SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	ExitProcess(0);
}

#if _DEBUG
void main(){}
#endif
