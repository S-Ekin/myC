/*
	��ѧϰ-��ͷ�ļ�ʵ��
*/
#include <iostream>;
#include <string>;
#include "Sales_data.h";
using namespace std;

void salesFn2() {
	Sales_data total;
	while (read(cin, total))
	{
		Sales_data trans;
		while (read(cin,trans))
		{
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, trans);
				total = trans;
			}
		}
		print(cout, total);
	}
}

// �ù��캯����ʼ��ֵ
void salesFn3() {
	Sales_data total;
	Sales_data trans;
	if (total.isbn() == trans.isbn()) {
		total.combine(trans);
	}
	else {
		print(cout, trans);
		total = trans;
	}
	print(cout, total);
}

// ���Ծֲ��� ,���ﷵ�ص���ֵ����Ϊsum �������ֵ������ָ����ʵ�ǵ�ַ�����Է��ص�����ֲ������ǿ����õġ�
 void addTest() {
	Sales_data a(cin);
	Sales_data b(cin);

	Sales_data sum = add(a, b);
	print(cout, sum);
}
 
 int main11() {
	 addTest();
	return 0;
}