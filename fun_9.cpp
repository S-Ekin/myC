#include <iostream>;
#include <string>;
#include <vector>;
#include <cassert>;
using namespace std;

// 定义和声明 ，再fun_8 使用这里的定义
struct ABC { float b, a; void AB(float tem1, float tem2); long ABCD(float); };
void ABC::AB(float tem1, float tem2) {
	cout << tem1 + 3.4 << " " << tem2 + 5.6 << endl;
	a = tem1 + 3.4;
	b = tem2 + 0;
	cout << b << endl;
}

// 内联函数
inline int fn() {
	return 34;
}

constexpr int fn2() {
	return 23;
}
constexpr size_t scale(size_t cnt) {
	return fn2() * cnt;
}

void constFnTest() {
	scale(2);
	const int a = 4;
	scale(a); // 报错，a不是常量表达式；
}

// scale(2); // 报错 函数外只能定义全局变量或者对象 ，而不能执行语句及调用函数 。

#define NDEBUG
void assertFn() {
	int a = 100;
	assert(a > 100); // true 什么也不做， false终止程序
}

using Iter = vector<int>::const_iterator;

void print(Iter first, Iter last)
{
#ifndef NDEBUG
	cout << "vector size: " << last - first << endl;
#endif
	if (first == last)
	{
		cout << "over!" << endl;
		return;
	}
	cout << *first << " ";
	print(++first, last);
}
// 指向函数的指
void fn(int&) {
	void (*pf)() = constFnTest;
	pf = 0;
	pf = nullptr;
	pf = assertFn;
}

// 函数别名
typedef int Fun(string&, int);
typedef decltype(print) Fun2;

// 函数指针别名
typedef int (*Fun4)(string&);
typedef decltype(print)* Fun3;

// 直接声明返回函数指针的函数
int (*f1(int))(int*, int);

string(*fw(int))[10];

auto f5(int)->int(*)[10];
using f6 = int(int);
int fg6(int a) {
	return 6;
}

int fg7() {
	vector<f6*> v1;
	v1.push_back(fg6);
	return 8;
}

int add(int a, int b) {
	return a + b;
}

int min(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divisoion(int a, int b) {
	return b!=0? a / b : 0;
}

void ptrFnTest() {
	vector<decltype(add)*> fn;
	fn.push_back(add);
	fn.push_back(min);
	fn.push_back(multiply);
	fn.push_back(divisoion);

	for (auto f : fn) {
		cout << f(4, 2) << endl;
	}
}
// 局部变量测
string fnTest1() {
	return "fasdf";
}
int main9() {
	string c = "asd";
	cout << &c << endl;
	string& b = c;
	auto a = fnTest1();
	cout << a;
	return 0;
}