/*
	类学习-用头文件实现
*/
#include <iostream>;
#include <string>;
#include "Sales_data.h";
using namespace std;

void salesFn2() {
	Sales_data total;
	while (read(cin, total))
	{
		Sales_data trans;
		while (read(cin,trans))
		{
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, trans);
				total = trans;
			}
		}
		print(cout, total);
	}
}

// 用构造函数初始化值
void salesFn3() {
	Sales_data total;
	Sales_data trans;
	if (total.isbn() == trans.isbn()) {
		total.combine(trans);
	}
	else {
		print(cout, trans);
		total = trans;
	}
	print(cout, total);
}

// 测试局部类 ,这里返回的是值，因为sum 保存就是值，不像指针其实是地址。所以返回的这个局部变量是可以用的。
 void addTest() {
	Sales_data a(cin);
	Sales_data b(cin);

	Sales_data sum = add(a, b);
	print(cout, sum);
}
 
 int main11() {
	 addTest();
	return 0;
}