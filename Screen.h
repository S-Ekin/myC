#pragma once
#include <iostream>;
#include <string>;
using std::string;

class Screen
{
public:
	typedef string::size_type pos;     //	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {};
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {};

	char get() const { return contents[cursor]; };
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);
	void some_member() const;
private:
	mutable size_t access_ctr = 0; // 可以在const 成员函数都可以改变
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
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
