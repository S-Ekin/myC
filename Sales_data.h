/*
	Sales_data �Ķ���
*/
#ifndef SALES_DATA
#define SALES_DATA
#include <string>;
#include <iostream>;
using std::string;
using std::istream;
using std::ostream;
class Sales_data
{
	friend istream& read(istream& is, Sales_data& a);
	friend ostream& print(ostream& is,const Sales_data& a);
public:
	 //��ʼֵ�б�
	Sales_data() = default; // 	Sales_data() :revenue(7.0) {};	 //��ʾ�س�ʼ��
	Sales_data(string& s) :bookNo(s) {};
	Sales_data(istream& is);

	//������Ա���� , const �Ǳ��� ������this ��ָ����� ���� this: const Sales_data *const this;
	string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data& rhs);


private:
	// ���ݳ�Ա
	string bookNo= "A12";
	int unit_sold = 0;
	double revenue = 0;
	// double avg_price() const;	
	inline double avg_price() const;
};
istream& read(istream& is, Sales_data& a) {
	is >> a.bookNo >> a.unit_sold >> a.revenue;
	return is;
}
ostream& print(ostream& os, const Sales_data& total) {
	os << "bookNO��" << total.bookNo << "  unit_sold��" << total.unit_sold << "  revenue: " << total.revenue << " ƽ��ֵ�� " << total.avg_price();
	return os;
}

// ���캯��
Sales_data::Sales_data(istream& is) {
	read(is, *this);
}

// �ⲿ����
double Sales_data::avg_price() const {
	if (!unit_sold) {
		return 0;
	}
	else {
		return revenue / unit_sold + 1000;
	}
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	unit_sold += rhs.unit_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data& a, const Sales_data& b) {
	Sales_data total = a;
	total.combine(b);
	return total;
}

#endif // !SALES_DATA
