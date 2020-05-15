#include <Windows.h>

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
	wc.lpfnWndProc = DefWindowProc;
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

	ShowWindow(hwnd, SW_SHOW);
	while (true);
	return 0;
}