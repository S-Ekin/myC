#pragma once
#include "Screen7.3.h";
#include <vector>;
using std::vector;
class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	vector<Screen> screens{ Screen(24, 80, ' ') };
};


//inline void Window_mgr::clear(ScreenIndex i) {
//	Screen& s = screens[i];
//	s.contents = String(s.height * s.width, ' ');
//}; 
