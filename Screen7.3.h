#pragma once
#include <iostream>;
#include <string>;
using std::string;
// class Window_mgr;
class Screen
{
	// friend void Window_mgr::clear(Window_mgr::ScreenIndex); // 不需要额外 include Window_mgr;
public:
	typedef string::size_type pos;     //	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {};
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {};

	char get() const { return contents[cursor]; };
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);
	void some_member() const;
	Screen& set(char);
	Screen& set(pos, pos, char);

	Screen& display(std::ostream& os) {
		do_display(os);
		return *this;
	};
	const Screen& display(std::ostream& os) const {
		do_display(os);
		return *this;
	};

private:
	mutable size_t access_ctr = 0; // 可以在const 成员函数都可以改变
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

private:
	void do_display(std::ostream& os) const {
		os << contents;
	}
};

char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}
inline
Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

void Screen::some_member() const {
	++access_ctr;
}

inline
Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch) {
	contents[r * width + col] = ch;
	return *this;
}

// 不需要额外 include Window_mgr;
