#pragma once
#include "Window.h"
#include "MyTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	MyTimer timer;
};