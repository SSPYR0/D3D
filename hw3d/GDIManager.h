#pragma once
#include"MyWin.h"
class GDIManager
{
public:
	GDIManager();
	~GDIManager();

private:
	static ULONG_PTR token;
	static int refCount;
};

