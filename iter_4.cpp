/*
	迭代器
*/
#include <string>;
#include <iostream>;
#include <vector>;
using namespace std;
// 关键子 箭头运算符
void iter() {
	string s("sadfasdf");
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it); // 注意这里的*代表的不是指针，是引用；
	}
	cout << s << endl;
	for (auto i = s.begin(); i != s.end() && !isspace(*i); i++)
	{
		*i = toupper(*i);
	}
	cout << s << endl;
}

void iteratorVetor() {
	vector<string> arr{ "我", "是一个","程序员","！" };
	for (auto word = arr.cbegin(); word != arr.cend() && !word->empty(); word++) {
		cout << *word << endl;
	}
}

void countIterator() {
	vector<int> arr;
	int t;
	while (cin >> t)
	{
		arr.push_back(t);
	}

	auto size = arr.end() - arr.begin();

	//for (auto i = arr.begin(); i != arr.end(); ++i)
	//{
	//	if (i + 1 < arr.end()) {
	//		int sum = *i + *(i + 1);
	//		cout << "相邻 :" << sum << endl;
	//	}
	//}

	for (auto i = arr.begin(); i != arr.end(); i++)
	{	
		auto s = arr.end() - i -1 + arr.begin();
		int sum = *i + *s;

		cout << "首尾：" << sum << endl;
	}
}
int main4() {
	countIterator();
	string str("abcdef");
	string::iterator s = str.begin();
	string::const_iterator b = str.begin();
	auto a = str.cbegin();
	auto c = str.cbegin();
	// *b = '3';
	*s = *(c + 2);
	return 0;
}