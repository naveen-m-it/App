#include "Main.h"

LRESULT Main::WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    switch (uMsg) {
    case WM_PAINT:
    {
        HDC hdc = BeginPaint(hwnd, &ps);
        RECT rc;
        GetClientRect(hwnd, &rc);
        TextOutW(hdc, rc.right / 2, rc.bottom / 2, L"Hello, World!", 14);
        EndPaint(hwnd, &ps);
    }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

ATOM Main::OnCreate()
{
    WNDCLASSEXW wc = {};
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WinProc;
    wc.lpszClassName = L"App";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);

   return RegisterClassExW(&wc);
}

MSG Main::HandleMessage()
{
    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return msg;
}

void Main::OnStart()
{
    hwnd = CreateWindowExW(
        0,
        L"App",
        L"Window",
        WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );
}

HWND Main::getHWND()
{
    return hwnd;
}

Main::Main(HINSTANCE hInstance)
{
    this->hInstance = hInstance;

    if (!OnCreate()) {
        return;
    }
    OnStart();
    //HandleMessage();
    ShowWindow(hwnd, SW_NORMAL);
}

Main::~Main()
{
}
