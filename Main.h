#pragma once
#include "Windows.h"

class Main
{
	HWND hwnd;
	HINSTANCE hInstance;
	static LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
	ATOM OnCreate();
	void OnStart();
public:
	MSG HandleMessage();
	HWND getHWND();
	Main(HINSTANCE);
	~Main();

};

