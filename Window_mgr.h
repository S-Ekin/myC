#pragma once
#include "Screen.h";
#include <vector>;
using std::vector;
class Window_mgr
{
private:
	vector<Screen> screens{ Screen(24, 80, ' ') };
};

