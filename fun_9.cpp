#include <iostream>;
#include <string>;
#include <vector>;
#include <cassert>;
using namespace std;

// ��������� ����fun_8 ʹ������Ķ���
struct ABC { float b, a; void AB(float tem1, float tem2); long ABCD(float); };
void ABC::AB(float tem1, float tem2) {
	cout << tem1 + 3.4 << " " << tem2 + 5.6 << endl;
	a = tem1 + 3.4;
	b = tem2 + 0;
	cout << b << endl;
}

// ��������
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
	scale(a); // ����a���ǳ������ʽ��
}

// scale(2); // ���� ������ֻ�ܶ���ȫ�ֱ������߶��� ��������ִ����估���ú��� ��

#define NDEBUG
void assertFn() {
	int a = 100;
	assert(a > 100); // true ʲôҲ������ false��ֹ����
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
// ָ������ָ
void fn(int&) {
	void (*pf)() = constFnTest;
	pf = 0;
	pf = nullptr;
	pf = assertFn;
}

// ��������
typedef int Fun(string&, int);
typedef decltype(print) Fun2;

// ����ָ�����
typedef int (*Fun4)(string&);
typedef decltype(print)* Fun3;

// ֱ���������غ���ָ��ĺ���
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
// �ֲ�������
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