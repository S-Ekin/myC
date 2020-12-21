/*
	string 学习
*/
#include <string>;
#include <iostream>;
using namespace std;

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
int main1() {
	string str = "qer3fads!!!!!@q";
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
	return 0;
}