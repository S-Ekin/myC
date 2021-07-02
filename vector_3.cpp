#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

void initVector() {
	int a = 34;
	int& r = a;
	vector<int> v = {r};
	auto v1 = v;
}

// 添加
void pushFn() {
	string word;
	vector<string> text;
	while (cin >> word) {
		text.push_back(word);
	}
	cout << text.size() << "  " << text[2] << endl;
}

// for 遍历
void forFn() {
	vector<int> v(10, 4);
//	vector<int> a = vector<int>(10, 4);
	int index = 0;
	for (auto& i : v) {
		index++;
		i = index + i;
		cout << i << endl;
	}
}
// 大写转换输出
void uPWord() {
	string word;
	vector<string> v;
	while (cin >> word) {
		v.push_back(word);
	}

	for (auto& str : v) {
		for (char& s : str) {
			s = toupper(s);
		}
	}
	for (string i : v) {
		cout << i << endl;
	}
}
// 计算容器里的值
void count() {
	vector<int> arr;
	int t;
	while (cin >> t)
	{
		arr.push_back(t);
	}

	auto size = arr.size();

	for (size_t i= 0; i < size; i+=2)
	{
		if (i+1 < size) {
			int sum = arr[i] + arr[i + 1];
			cout << sum << endl;
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		int sum = arr[i] + arr[size - 1 - i];
		cout << sum << endl;
	}

}
int main3() {
	uPWord();
	return 0;
}