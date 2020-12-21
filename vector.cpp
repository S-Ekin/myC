#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

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
int main() {
	uPWord();
	return 0;
}