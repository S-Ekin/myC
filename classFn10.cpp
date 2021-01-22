/*
	类学习
*/
#include <iostream>;
#include <string>;
using namespace std;
// 这里是声明以及定义 要是这里声明的和头文件声明的名称一样会对头文件声明的有影响，使用头文件里的数据初始化时，使用的是这里的初始化
typedef struct Sales_data1 
{
    // 常量成员函数 , const 是表明 隐含的this 所指向的是 常量 this: const Sales_data *const this;
	string isbn() const { return bookNo; };
	double avg_price1() const;
	Sales_data1& combine1(const Sales_data1 & rhs);

	// 数据成员
	string bookNo;
	unsigned unit_sold=0 ;
	double revenue = 0;

};

// 外部定义
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

		cout << "bookNO：" << total.bookNo << "  unit_sold：" << total.unit_sold << "  revenue: " << total.revenue << " 平均值： " << total.avg_price1() << endl;
	}
	else {
		cerr << "没有输入数据！";
	}
}

int main11() {
	salesFn();
	return 0;
}