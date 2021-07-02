/*
	Sales_data 的定义
*/
#ifndef SALES_DATA
#define SALES_DATA
#include <string>;
#include <iostream>;
using namespace std;
class Sales_data
{
	friend istream& read(istream& is, Sales_data& a);
	friend ostream& print(ostream& is, const Sales_data& a);
public:
	//委托构造函数
	Sales_data(string a, int b, double c) : bookNo(a), unit_sold(b), revenue(c) {
		std::cout << "委托构造函数" << endl;
	}

	//初始值列表
	Sales_data() = default; // 	Sales_data() :revenue(7.0) {};	 //显示地初始化
//	Sales_data(string& s) :bookNo(s) {};
	Sales_data(string& s) : Sales_data("", 0, 0) {};
	Sales_data(istream& is) : Sales_data() {
		read(is, *this);
	};

	//常量成员函数 , const 是表明 隐含的this 所指向的是 常量 this: const Sales_data *const this;
	string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data& rhs);

	int avg_price();

private:
	// 数据成员
	string bookNo = "A12";
	int unit_sold = 0;
	double revenue = 0;
	inline double avg_price() const;
};
istream& read(istream& is, Sales_data& a) {
	is >> a.bookNo >> a.unit_sold >> a.revenue;
	return is;
}
ostream& print(ostream& os, const Sales_data& total) {
	os << "bookNO：" << total.bookNo << "  unit_sold：" << total.unit_sold << "  revenue: " << total.revenue << " 平均值： " << total.avg_price();
	return os;
}

// 构造函数 使用委托构造函数后，函数体得直接写在类里面
//Sales_data::Sales_data(istream& is) {
//	read(is, *this);
//}

// 外部定义
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
inline
int Sales_data::avg_price() {
	return unit_sold / revenue;
}

#endif // !SALES_DATA
