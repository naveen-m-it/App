#include "Windows.h"
#include "Main.h"

INT WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ PWSTR pCmdLine,
	_In_ INT nCmdShow
	) 
{
	Main* win = new Main(hInstance);
	MSG msg = win->HandleMessage();
	return msg.wParam;
}