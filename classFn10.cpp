/*
	��ѧϰ
*/
#include <iostream>;
#include <string>;
using namespace std;
// �����������Լ����� Ҫ�����������ĺ�ͷ�ļ�����������һ�����ͷ�ļ���������Ӱ�죬ʹ��ͷ�ļ�������ݳ�ʼ��ʱ��ʹ�õ�������ĳ�ʼ��
typedef struct Sales_data1 
{
    // ������Ա���� , const �Ǳ��� ������this ��ָ����� ���� this: const Sales_data *const this;
	string isbn() const { return bookNo; };
	double avg_price1() const;
	Sales_data1& combine1(const Sales_data1 & rhs);

	// ���ݳ�Ա
	string bookNo;
	unsigned unit_sold=0 ;
	double revenue = 0;

};

// �ⲿ����
double Sales_data1::avg_price1() const {
	if (!unit_sold) {
		return 0;
	}
	else {
		return 13 / unit_sold;
	}
}

Sales_data1& Sales_data1::combine1(const Sales_data1& rhs) {
	unit_sold += rhs.unit_sold;
	revenue += rhs.revenue;
	return *this;
}



void salesFn() {
	Sales_data1 total;
	if(cin >> total.bookNo >> total.unit_sold >> total.revenue)
	{
		Sales_data1 trans;
		while (cin >> trans.bookNo >> trans.unit_sold>>trans.revenue)
		{
			if (total.isbn() == trans.isbn()) {
				total.combine1(trans);
			}
			else {
				cout << "bookNo: " << trans.bookNo << endl;
				total = trans;
			}
		}

		cout << "bookNO��" << total.bookNo << "  unit_sold��" << total.unit_sold << "  revenue: " << total.revenue << " ƽ��ֵ�� " << total.avg_price1() << endl;
	}
	else {
		cerr << "û���������ݣ�";
	}
}

int main11() {
	salesFn();
	return 0;
}