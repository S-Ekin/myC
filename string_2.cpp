/*
	string ѧϰ
*/
#include <string>;
#include <iostream>;
using namespace std;

// ע���ַ������� �� �ַ��ǲ�ͬ�ġ�����Ͳ�����������ͬ

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
		cout << "���� " << tem << endl;
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
	
	cout<< "ȥ�������ţ�"<<res<<endl;
	
	string a = "asdf";
	char & b = a[2];
	auto g = &b;
	char h = 'a';
	auto j = &h;
	cout<< "���������ã�"<<g<<endl;
	cout<< "����char��"<<&h<<endl;
//	string str2 = "qer3fads!!!!!";
//	int index = 0;
//	while (index < str2.size()) {
//		str2[index] = 'x';
//		index++;
//	}

//	cout << str2 <<endl;
//	string t;
//	cout << " ���ַ�:"<< t[0] << endl;
 }

 // ��׼��string �Ƚ�
 void StringOpt() {
	 string str1 = "����˭��";
	 string str2 = "���";
	 string str3 = str1;
	 string str4 = str1 + "---" + str2;
	 if (str1 != str3) {
		 cout << "��ͬ" << endl;
	 }
	 else {
		 cout << "��ͬ" << endl;
	 }
	 cout << str4 << endl;
 }

 void charOpt() {
	//  char sa = "��"; ����
	 char s = '��';
	 const char* str = "����";
	 // const char str_1[] = 'd����'; // ����
	//  const char str_2[] = {'��',"��ʦ��"}; �ڶ���Ԫ�ش���
	const char str_3[] = {'��','��'};
	 const char str1[] = "����˭��";
	 const char str2[] = "���";
	 // const char str3[] = str1; ����ֱ�Ӹ��ƣ���Ϊ������
	 char str3[100]; // Ҫ��֤�㹻��
	 strcpy_s(str3, str1); // ����
	 char str4[100] = "";
	 strcat_s(str4, str2);
	 cout << "str4: " << str4 << " str3: " << str3 << endl;
	 if (str1 != str3) {
		 cout << "��ͬ" << endl;
	 }
	 else {
		 cout << "��ͬ" << endl;
	 }
 }
int main() {
	charOpt();
	return 0;
}
