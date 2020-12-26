/*
	string 学习
*/
#include <string>;
#include <iostream>;
using namespace std;

// 注意字符字面量 和 字符是不同的。概念和操作方法都不同

 void compareStr() {
	string s1;
	string s2;
	cin >> s1 >> s2;

	if (s1 == s2) {
		cout << "s1: " << s1 << " s2: " << s2 << endl;
	}
	else {
		string tem = s1;
		if (s1.size() > s2.size()) {
			tem = s1;
		}
		else {
			tem = s2;
		}
		cout << "长： " << tem << endl;
	};
}

 string joinStr() {
	 string str;
	 string tem;
	 while (cin >> tem) {
		 str += tem;
	 }

	 return str;
 }
 void optStr() {
	string str = "qer3fads!!!!!@q";
	const char* p = "asdf";
	decltype(str.size()) punt_cnt = 0;
	string res ="";
	for (auto &tem:str)
	{
		if (!ispunct(tem)) {
			res += tem;
		}
	}
	
	cout<< "去除标点符号："<<res<<endl;
	
	string a = "asdf";
	char & b = a[2];
	auto g = &b;
	char h = 'a';
	auto j = &h;
	cout<< "引用再引用："<<g<<endl;
	cout<< "引用char："<<&h<<endl;
//	string str2 = "qer3fads!!!!!";
//	int index = 0;
//	while (index < str2.size()) {
//		str2[index] = 'x';
//		index++;
//	}

//	cout << str2 <<endl;
//	string t;
//	cout << " 空字符:"<< t[0] << endl;
 }

 // 标准库string 比较
 void StringOpt() {
	 string str1 = "我是谁！";
	 string str2 = "大噶";
	 string str3 = str1;
	 string str4 = str1 + "---" + str2;
	 if (str1 != str3) {
		 cout << "不同" << endl;
	 }
	 else {
		 cout << "相同" << endl;
	 }
	 cout << str4 << endl;
 }

 void charOpt() {
	//  char sa = "的"; 错误
	 char s = '的';
	 const char* str = "是随";
	 // const char str_1[] = 'd动阀'; // 错误
	//  const char str_2[] = {'额',"大师傅"}; 第二个元素错误
	const char str_3[] = {'额','的'};
	 const char str1[] = "我是谁！";
	 const char str2[] = "大噶";
	 // const char str3[] = str1; 不能直接复制，因为是数组
	 char str3[100]; // 要保证足够大
	 strcpy_s(str3, str1); // 复制
	 char str4[100] = "";
	 strcat_s(str4, str2);
	 cout << "str4: " << str4 << " str3: " << str3 << endl;
	 if (str1 != str3) {
		 cout << "不同" << endl;
	 }
	 else {
		 cout << "相同" << endl;
	 }
 }
int main() {
	charOpt();
	return 0;
}
