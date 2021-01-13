#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

// 定义和声明 ，再fun_8 使用这里的定义
struct ABC { float b, a; void AB(float tem1, float tem2); long ABCD(float); };
void ABC::AB(float tem1, float tem2) {
	cout << tem1 + 3.4 << " " << tem2 + 5.6 << endl;
	a = tem1 + 3.4;
	b = tem2 + 0;
	cout << b << endl;
}