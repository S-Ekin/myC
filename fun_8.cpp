/*
	����
	���������������������أ���һ��д������ʱ�򣬾Ͱ����˺����������Ͷ��壬������� ��fact��
	���������һ���ļ�����дһ��ͬ���� fact �ᱨ�ظ������塿 ��ע�� �����ظ���������
	��Ϊÿһ���ļ�����ֻ��������ļ�������,���Ƕ�����ȫ�ֵġ����������Ϊ�����Ǹ��߱�������������Ǵ��ڵģ���Ҫ������
	�������������ȡ�������ڡ�a���ļ���д ��fact��-�����Ͷ����ˣ��ڡ�b���ļ���������һ�£����߱�������� fact�Ǵ��ڵģ�Ȼ��Ϳ���ֱ�ӵ����ˡ�����ٶ���һ�ξͻᱨ��
	����Ϊ�˱����ظ��ٶ���ļ����壬�ͰѶ������ͷ�ļ����൱������������ַ���ͷ�ļ���Ҳ���԰Ѷ������ͷ�ļ���
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

// Ϊ����ȷ�ж�����ı߽磬��������ʱ��������βָ��
void arrFn(int *beg, int *end) {
	while (beg != end)
	{
		cout << *beg++ << endl;
	}
}

// �������ò��� ,ע������ŵ������Լ���ע�����С
void arrRefrence(int (&arr)[10]) {
	for (auto i:arr)
	{
		cout << i << endl;
	}
}

// �ɱ������Ĳ���
void list() {
	initializer_list<string> ls{ "Asdf","asdfa" };
	initializer_list<int> int_ls({ 1,2,4 });
	initializer_list<int> ls_2 = { 1,3 };
	
	int s = 0;
	for (auto &a : int_ls) {
		s += a;
	}
	cout << s;
	return deFn();
}

// �������õĺ������ú����ķ���ֵ����ʼ�������ķ������ͣ��������ʼ����������
string& fnRe(string& str) {
	// str = "Aer";
	return str;
}

auto fnReConst2(string& str) {// ���س����ַ������ã�
	return str;
};
int& fnReConst3(int& str) {// ���س����ַ������ã�
	return str;
};

const int& fnReConst(int& str) { 
	// ע�������βα�ʵ�ε�ֵ��ʼ��Ϊ string ��
	// ������ִ����ϣ��β�Ҳ��û���ˣ���ʵ���ص��ǿ��ַ���δ�����
	return str;
}

void fnReTest() {
	string str = "asd";
	string& b = str;

	auto a = fnRe(b);

	a = "er";

//	fnRe(a) = "Er";

	cout << "a��"  << a << " str "<< str << endl;
}

int fnVector() {
	return {1}; // ֻ����һ��
}

vector<int> fnVector2() {
	return{1,2,3};
}

bool str_subrange(const string& str1, const string& str2) {
	if (str1.size()==str2.size()) {
		return str1 == str2;
	}

	auto size = str1.size() < str2.size() ? str1.size() : str2.size();
	for (size_t i = 0; i <i !=size; i++)
	{
		if (str1[i]!=str2[i]) {
			return false;
		}

	}
	return false; // ��Ҫ©��
}

// β�÷�������
auto arrfn2(int (*a)[10])->int(*)[10]{
	return a;
}
// ��������ָ��ĺ���
string(& strArrFn())[10];

typedef string arrStr[10];
arrStr* strArrFn1(arrStr* arr) {
	return arr;
};

int arrTest[10] = {5,5,5,5,5};

int(*arrPtr)[10] = &arrTest;

decltype(arrTest)* strArrFn2() {
	return &arrTest;
};



int main_8(int argc, char *argv[]) {
	fnReTest();
	return 0;
}