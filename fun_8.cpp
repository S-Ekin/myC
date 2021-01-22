/*
	函数
	函数不能重名（除了重载），一般写函数的时候，就包括了函数的声明和定义，如下面的 【fact】
	如果在另外一个文件里再写一个同样的 fact 会报重复【定义】 ，注意 不是重复【声明】
	因为每一个文件声明只是在这个文件里有用,但是定义是全局的。（可以理解为声明是告诉编译器这个函数是存在的，不要报错。）
	如果不把声明提取出来，在【a】文件里写 【fact】-声明和定义了，在【b】文件里先声明一下，告诉编译器这个 fact是存在的，然后就可以直接调用了。如果再定义一次就会报错。
	所以为了避免重复再多个文件定义，就把定义放在头文件，相当于提出公共部分放在头文件，也可以把定义放在头文件。
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

// 为了正确判断数组的边界，操作数组时，传递首尾指针
void arrFn(int *beg, int *end) {
	while (beg != end)
	{
		cout << *beg++ << endl;
	}
}

// 数组引用参数 ,注意打括号的区别，以及标注数组大小
void arrRefrence(int (&arr)[10]) {
	for (auto i:arr)
	{
		cout << i << endl;
	}
}

// 可变数量的参数
void list() {
	initializer_list<string> ls{ "Asdf","asdfa" };
	initializer_list<int> int_ls({ 1,2,4 });
	initializer_list<int> ls_2 = { 1,3 };
	
	int s = 0;
	for (auto &a : int_ls) {
		s += a;
	}
	cout << s;
	return deFn();
}

// 返回引用的函数，用函数的返回值来初始化函数的返回类型（像变量初始化那样）。
string& fnRe(string& str) {
	// str = "Aer";
	return str;
}

auto fnReConst2(string& str) {// 返回常量字符的引用；
	return str;
};
int& fnReConst3(int& str) {// 返回常量字符的引用；
	return str;
};

const int& fnReConst(int& str) { 
	// 注意这里形参被实参的值初始化为 string 后，
	// 当函数执行完毕，形参也就没有了，其实返回的是空字符，未定义的
	return str;
}

void fnReTest() {
	string str = "asd";
	string& b = str;

	auto a = fnRe(b);

	a = "er";

//	fnRe(a) = "Er";

	cout << "a："  << a << " str "<< str << endl;
}

int fnVector() {
	return {1}; // 只能有一个
}

vector<int> fnVector2() {
	return{1,2,3};
}

bool str_subrange(const string& str1, const string& str2) {
	if (str1.size()==str2.size()) {
		return str1 == str2;
	}

	auto size = str1.size() < str2.size() ? str1.size() : str2.size();
	for (size_t i = 0; i <i !=size; i++)
	{
		if (str1[i]!=str2[i]) {
			return false;
		}

	}
	return false; // 不要漏掉
}

// 尾置返回类型
auto arrfn2(int (*a)[10])->int(*)[10]{
	return a;
}
// 返回数组指针的函数
string(& strArrFn())[10];

typedef string arrStr[10];
arrStr* strArrFn1(arrStr* arr) {
	return arr;
};

int arrTest[10] = {5,5,5,5,5};

int(*arrPtr)[10] = &arrTest;

decltype(arrTest)* strArrFn2() {
	return &arrTest;
};



int main_8(int argc, char *argv[]) {
	fnReTest();
	return 0;
}