/*
���� ************************ ʼ�ռ�סʹ�����������ʱ�� �ᱻ�滻Ϊָ��������Ԫ�ص�ָ��  *********************

*/
#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;
// ���������ͳ�ʼ��
void initArr() {
	const unsigned sz = 3;
	int arr[sz] = { 0 ,1, 3 };
	string arr2[sz] = { "�Ӱ�","abc" }; //
	const char strArr[7] = "abcdef"; // �ַ������������ý�β����һ�����֣� ����ĳ�ʼ����û��

	// ע�����η��� * ��& ��������������ڵ�����
	// int * (&arr)[10] �����������ǣ�����10��ָ��int ���͵�ָ�롣

	// �������顣����ĳ�Ա�������������͡�
	auto& arr_refence = arr;
	int(&arr_refence2)[sz] = arr;

	// �����ָ��
	int(*arr_point)[sz] = &arr;
	auto* arr_point2 = &arr;

	// ��Ա��ָ�������
	int* arr_ptr[2] = {&arr[0],&arr[1]};

	// ���ӵ� 
	int* ptr[sz];
	int* (&arr_ptr_refence)[sz] = ptr;
	// �ȼ�
	auto& arr3 = ptr;

	string sa[3];
	int num[3];
	for (size_t i = 0; i < size(num); i++)
	{
		cout <<"int: "<< num[i] << " string: " << sa[i]<< endl;
	}

}

// ��ά���� 
void arrFn() {
	int arr[3][4] = { {1,2,3},{4,5,6},{7}};

	for (auto p = arr; p != arr + 3; ++p) {
		for (auto q = p; q != p + 4; ++q) {
			cout << *q << endl;
		}
	}
}

// ���ͱ���������

void typeArr() {
	
	using int_arr = int[4];
	typedef int int_arr1[4];

	int_arr arr = {};
	int_arr* p = &arr;
	int_arr1* p1 = &arr;

}

// �������
void arrIter() {
	int arr[10];
	int index = 0;
	for (int& i : arr) {
		i = index;
		++index;
	}

	int arr_copy[10];
	vector<int> v_arr;
	
	index = 0;
	for (int i : arr) {
		arr_copy[index] = i;
	//	v_arr[index] = i; ���������±�������vector,��Ϊ��ʼ���� v_arr��һ���յ�vector,�϶���û���κ��±�ģ�
		v_arr.push_back(i);
		++index;
	}

	for (size_t i = 0; i < 10; i++)
	{
		v_arr[i] = v_arr[i] * 2;
		cout << " arr: " << arr_copy[i] << " vector: " << v_arr[i] << endl;
	}
}

// �����ָ��
void arrAndPtr() {
	int arr[3] = { 2,3,4 };
	auto a2(arr); // ʵ������һ��ָ�롣����������õ�����ĵط��滻��ָ�������ĵ�һ��Ԫ�ص�ָ�롣
	*a2 = 45;
	decltype(arr) a3 = { 1,2,4 };
	cout << arr[0];
	int* p = arr;
	int *c = p++;
}

// ��βָ��
void beginAndEnd() {

	int arr[3] = { 1,2,3 };
	int* p = begin(arr);
	int g = p[2]; //���2����� pָ���Ԫ���������������λ��
	int *num(p);
	int num3(*p);
	int *num1(p);
	while ( p != end(arr))
	{
		cout << *p << "  " << num<< endl;
		++p;
	}
}

void setArr() {
	int arr[3] = { 1,2,3 };
	int* pbeg = begin(arr);
	int* pend = end(arr);
	while (pbeg != pend) {
		*pbeg = 0;
		++pbeg;
	}

	for (auto i:arr)
	{
		cout << i << endl;

	}
}
int main5() {
	setArr();
	return 0;
}