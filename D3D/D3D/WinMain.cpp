//TODO: Move window creation out of main
//TODO: msg handling 

#include <d3d.h>
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(69);	
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
){
	const auto pClassName = "D3D";

	//register windows class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	//create window instance
	HWND hwnd = CreateWindowEx(
		0, pClassName, "D3D",
		WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);

	//show the window 
	ShowWindow(hwnd, SW_SHOW);

	//msg
	MSG msg;
	while (GetMessage(&msg,nullptr,0,0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}