/*
���ʽ
*/
// ǰ�õ����ͺ��õ��� ��ָ���ϵ�ʹ��
#include <iostream>;
#include <string>;
using namespace std;

void prtAdd() {
	int num[4] = { 1,2,3,4 };
	int(*ptr)[4] = &num; // ָ�������ָ��
	auto p = begin(num);

	auto s = size(num);
	string str = "dasfd";
	char c = 'd';
	int n = 23;

	cout << "string ��С��" << sizeof(p) << endl;
	cout << "char ��С��" << sizeof(c) << endl;
	cout << "int ��С��" << sizeof(n) << endl;

	while (p != end(num))
	{
		cout << *p++ << endl; // ָ�������ƶ������Ƿ��ص���δ�ı�֮ǰ��ָ�룬Ȼ�������
	}

	p = begin(num);

	while (p != end(num))
	{
		cout << *(++p) << endl; // ָ�������ƶ��������ƶ����ָ�룬Ȼ���ٽ����á�/�������һ��δ�����ֵ
	}
}

void test() {
	int x[10];
	int* p = x;
	auto d = 3.45 + 3;
	cout << sizeof(x) / sizeof(*x) << endl;
	// cout << sizeof(p) / sizeof(*p) << endl; // sizeof(p) ��ָ����ռ�Ĵ�С������ x
	cout << sizeof(x) / sizeof(*p) << endl;
}

void transform() {
	const char* cp = "stt";
	//	char* q = static_cast<char*>(cp); //���� stati_cast ֻ��ת���ǵײ��const
	//	char *st =	static_cast<string>(cp); // ����
	string t = static_cast<string>(cp);
	//	const_cast<string>(cp); // ���� const_castֻ�ܸı䳣������
	const_cast<char*>(cp);
}
void excise() {
	int c = 4;
	double b = 3.5;
	for (size_t i = 0; i < 4; i++)
	{
		c *= static_cast<int>(b);
	}
	const char* pc = "asdf";
	c = static_cast<int>(*pc);
}

void excise2() {
	const string str = "����";
	int i; double d; const string* ps = &str; const char* pc = "w"; void* pv;
	// ��ʽд��
	pv = (void*)ps;
	i = int(*pc);
	pv = &d;
	pc = (char*)pv;
	// c++д��
	pv = static_cast<void*>(const_cast<string*>(ps));
	i = static_cast<int>(*pc);
	pv = static_cast<void*>(&d);
	pc = static_cast<char*>(pv);
}

int main_6() {
	excise();
	return 0;
}