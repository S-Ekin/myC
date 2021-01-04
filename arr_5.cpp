/*
数组 ************************ 始终记住使用数组的名字时， 会被替换为指向数组首元素的指针  *********************

*/
#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;
// 数组声明和初始化
void initArr() {
	const unsigned sz = 3;
	int arr[sz] = { 0 ,1, 3 };
	string arr2[sz] = { "加班","abc" }; //
	const char strArr[7] = "abcdef"; // 字符串字面量最后得结尾还有一个空字， 上面的初始化得没有

	// 注意修饰符： * 、& 放括号外和括号内的区别，
	// int * (&arr)[10] 放外面代表的是，含有10个指向int 类型的指针。

	// 引用数组。数组的成员不能是引用类型。
	auto& arr_refence = arr;
	int(&arr_refence2)[sz] = arr;

	// 数组的指针
	int(*arr_point)[sz] = &arr;
	auto* arr_point2 = &arr;

	// 成员是指针的数组
	int* arr_ptr[2] = {&arr[0],&arr[1]};

	// 复杂的 
	int* ptr[sz];
	int* (&arr_ptr_refence)[sz] = ptr;
	// 等价
	auto& arr3 = ptr;

	string sa[3];
	int num[3];
	for (size_t i = 0; i < size(num); i++)
	{
		cout <<"int: "<< num[i] << " string: " << sa[i]<< endl;
	}

}

// 多维数组 
void arrFn() {
	int arr[3][4] = { {1,2,3},{4,5,6},{7}};

	for (auto p = arr; p != arr + 3; ++p) {
		for (auto q = p; q != p + 4; ++q) {
			cout << *q << endl;
		}
	}
}

// 类型别名的数组

void typeArr() {
	
	using int_arr = int[4];
	typedef int int_arr1[4];

	int_arr arr = {};
	int_arr* p = &arr;
	int_arr1* p1 = &arr;

}

// 数组遍历
void arrIter() {
	int arr[10];
	int index = 0;
	for (int& i : arr) {
		i = index;
		++index;
	}

	int arr_copy[10];
	vector<int> v_arr;
	
	index = 0;
	for (int i : arr) {
		arr_copy[index] = i;
	//	v_arr[index] = i; 错误不能用下标来设置vector,因为初始化是 v_arr是一个空的vector,肯定是没有任何下标的；
		v_arr.push_back(i);
		++index;
	}

	for (size_t i = 0; i < 10; i++)
	{
		v_arr[i] = v_arr[i] * 2;
		cout << " arr: " << arr_copy[i] << " vector: " << v_arr[i] << endl;
	}
}

// 数组和指针
void arrAndPtr() {
	int arr[3] = { 2,3,4 };
	auto a2(arr); // 实际上是一个指针。编译器会把用到数组的地方替换成指向该数组的第一个元素的指针。
	*a2 = 45;
	decltype(arr) a3 = { 1,2,4 };
	cout << arr[0];
	int* p = arr;
	int *c = p++;
}

// 首尾指针
void beginAndEnd() {

	int arr[3] = { 1,2,3 };
	int* p = begin(arr);
	int g = p[2]; //这个2是相对 p指向的元素在数组里的索引位置
	int *num(p);
	int num3(*p);
	int *num1(p);
	while ( p != end(arr))
	{
		cout << *p << "  " << num<< endl;
		++p;
	}
}

void setArr() {
	int arr[3] = { 1,2,3 };
	int* pbeg = begin(arr);
	int* pend = end(arr);
	while (pbeg != pend) {
		*pbeg = 0;
		++pbeg;
	}

	for (auto i:arr)
	{
		cout << i << endl;

	}
}
int main5() {
	setArr();
	return 0;
}