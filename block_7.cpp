/*
	����
*/
#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

void countReapt() {
	string str;
	string old="";
	string maxStr="";
	int num = 0;
	int max = 0;
	while (cin >> str)
	{
		if (old == "") {
			++num;
			old = str;
			maxStr = old;
			max = num;
		}
		else if (old == str) {
			++num;
			if (max < num) {
				max = num;
				maxStr = str;
			}
		}
		else {
			num = 1;
			old = str;
		}
	}

		cout<< "max: " << max << " str: " << maxStr<< endl;
}

// ��������
void str_ask() {
	string rsp;
	do
	{
		string a;
		string b;
		cin >> a >> b;
		if (a.size() > b.size()) {
			cout << "a��" << endl;
		}
		else {
			cout << "b��" << endl;
		}
		cout << "�Ƿ�������룿" << endl;
		cin >> rsp;
	} while (!rsp.empty() && rsp[0]!='n');

}

// �쳣����
void error() {
	string arr[3] = {};
	vector<string> strArr = {};
	// throw std::runtime_error("asdf");
	try
	{
		throw std::runtime_error("asdf");
	}
	catch (exception err)
	{
		cout << err.what();
	}
}

void divider() {
	int a, b;
	int c;
	while (cin >> a >> b)
	{
		try
		{
			if (b==0) {
				throw runtime_error("dfas");
			}
			 c = a / b;
			 cout << c;
		}
		catch (runtime_error err)
		{
			cout << err.what() << "�Ƿ���Ҫ��������,y n" << endl;
			char c;
			cin >> c;
			if (c!='y') {
				// ����ѭ��
				break;
			}
		}
	}
}

int main_7() {
	divider();
	return 0;
}