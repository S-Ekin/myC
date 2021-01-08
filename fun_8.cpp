/*
	函数
*/
#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

// 计算阶乘
int fact() {
	cout << "请输入一个数字，计算其阶乘" << endl;
	int sum;
	cin >> sum;
	int a = sum;
	while (--sum) {
		a *= sum;
	}
	cout << a;
	return a;
}

int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

// 静态变量
int staticFn(int a) {
	static int b = a; // 静态变量会一直存在，第二次调用时，会使用上一次存在的值，不会再初始化
	cout << b << " " << endl;
	return ++b;
}

// 定义与声明
 struct ABC { int a, b; void AB( float tem1, float tem2 ); void ABCD(); };
void deFn() {
 // 在 fun_9 里定义
	ABC a; a.AB( 10, 20 ); 
	auto b = a.a;
	float d = 25.6;
	int c = d;
	cout << c << " "<< b ;
}

// 指针参数
void prtFn(int* ptr) {
	*ptr = 45; // 改变了实参指针所指向的（函数外面的）int
	int c = 56;
	ptr = &c; // 改变了形参指针地址，但是没有改变实参指针的地址
}
void str(const int & g) { //可以在直接用字面值来初始化形参，要是没有const 则不行。c++ 允许使用字面值初始化常量引用

}
void prtFnCall() {
	int a = 12;
	int* p = &a;

	cout << a << " " << &p << endl;
	prtFn(p);
	cout << a << " " << &p << endl;
	// 字面值-常量引用
	str(1);
}

// 习题6.17
void has(string a) {
	bool has = false;
	for ( char c:a )
	{
		char b = c;
		if (b == toupper(b)) {
			has = true;
			break;
		}
	}

	cout << has;
}

int main() {
	has("aaaaAdf");
	return 0;
}