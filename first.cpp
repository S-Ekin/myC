/*
	�������ݽṹ���Լ�������ݵĲ���
*/
#include <iostream>;
using namespace std;
#include <string>;
int i = 23;
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price;
};
int _main() {
	Sales_data data1, data2;
	cin >> data1.bookNo >> data1.units_sold >> data1.price;
	data1.revenue = data1.price * data1.units_sold;
	cin >> data2.bookNo >> data2.units_sold >> data2.price;
	data2.revenue = data2.price * data2.units_sold;
	if (data1.bookNo == data2.bookNo) {
		auto total = data1.revenue + data2.revenue;
		cout << "�ܼۣ�" << total << endl;
	}
	else {
		cout << "�鱾�Ų���ͬ��"<<endl;
	}
	return 0;
}