/*
表达式
*/
// 前置递增和后置递增 在指针上的使用
#include <iostream>;
#include <string>;
using namespace std;

void prtAdd() {
	int num[4] = { 1,2,3,4 };
	int(*ptr)[4] = &num; // 指向数组的指针
	auto p = begin(num);

	auto s = size(num);
	string str = "dasfd";
	char c = 'd';
	int n = 23;

	cout << "string 大小：" << sizeof(p) << endl;
	cout << "char 大小：" << sizeof(c) << endl;
	cout << "int 大小：" << sizeof(n) << endl;

	while (p != end(num))
	{
		cout << *p++ << endl; // 指针往下移动，但是返回的是未改变之前的指针，然后解引用
	}

	p = begin(num);

	while (p != end(num))
	{
		cout << *(++p) << endl; // 指针往下移动，返回移动后的指针，然后再解引用。/最后会输出一个未定义的值
	}
}

void test() {
	int x[10];
	int* p = x;
	auto d = 3.45 + 3;
	cout << sizeof(x) / sizeof(*x) << endl;
	// cout << sizeof(p) / sizeof(*p) << endl; // sizeof(p) 是指针所占的大小，不是 x
	cout << sizeof(x) / sizeof(*p) << endl;
}

void transform() {
	const char* cp = "stt";
	//	char* q = static_cast<char*>(cp); //错误 stati_cast 只能转换非底层的const
	//	char *st =	static_cast<string>(cp); // 错误
	string t = static_cast<string>(cp);
	//	const_cast<string>(cp); // 错误 const_cast只能改变常量属性
	const_cast<char*>(cp);
}
void excise() {
	int c = 4;
	double b = 3.5;
	for (size_t i = 0; i < 4; i++)
	{
		c *= static_cast<int>(b);
	}
	const char* pc = "asdf";
	c = static_cast<int>(*pc);
}

void excise2() {
	const string str = "动阀";
	int i; double d; const string* ps = &str; const char* pc = "w"; void* pv;
	// 旧式写法
	pv = (void*)ps;
	i = int(*pc);
	pv = &d;
	pc = (char*)pv;
	// c++写法
	pv = static_cast<void*>(const_cast<string*>(ps));
	i = static_cast<int>(*pc);
	pv = static_cast<void*>(&d);
	pc = static_cast<char*>(pv);
}

int main_6() {
	excise();
	return 0;
}