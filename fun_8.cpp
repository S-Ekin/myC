/*
	����
*/
#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

// ����׳�
int fact() {
	cout << "������һ�����֣�������׳�" << endl;
	int sum;
	cin >> sum;
	int a = sum;
	while (--sum) {
		a *= sum;
	}
	cout << a;
	return a;
}

int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

// ��̬����
int staticFn(int a) {
	static int b = a; // ��̬������һֱ���ڣ��ڶ��ε���ʱ����ʹ����һ�δ��ڵ�ֵ�������ٳ�ʼ��
	cout << b << " " << endl;
	return ++b;
}

// ����������
 struct ABC { int a, b; void AB( float tem1, float tem2 ); void ABCD(); };
void deFn() {
 // �� fun_9 �ﶨ��
	ABC a; a.AB( 10, 20 ); 
	auto b = a.a;
	float d = 25.6;
	int c = d;
	cout << c << " "<< b ;
}

// ָ�����
void prtFn(int* ptr) {
	*ptr = 45; // �ı���ʵ��ָ����ָ��ģ���������ģ�int
	int c = 56;
	ptr = &c; // �ı����β�ָ���ַ������û�иı�ʵ��ָ��ĵ�ַ
}
void str(const int & g) { //������ֱ��������ֵ����ʼ���βΣ�Ҫ��û��const ���С�c++ ����ʹ������ֵ��ʼ����������

}
void prtFnCall() {
	int a = 12;
	int* p = &a;

	cout << a << " " << &p << endl;
	prtFn(p);
	cout << a << " " << &p << endl;
	// ����ֵ-��������
	str(1);
}

// ϰ��6.17
void has(string a) {
	bool has = false;
	for ( char c:a )
	{
		char b = c;
		if (b == toupper(b)) {
			has = true;
			break;
		}
	}

	cout << has;
}

int main() {
	has("aaaaAdf");
	return 0;
}