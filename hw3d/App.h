#pragma once
#include "Window.h"
#include "MyTimer.h"
#include "ImguiManager.h"

class App
{
public:
	App();
	~App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
	bool show_demo_window = true;
private:
	ImguiManager imgui;
	Window wnd;
	MyTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	static constexpr size_t nDrawables = 180;
};