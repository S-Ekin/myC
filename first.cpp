#include <iostream>;
#include "Sales.item.h";
using namespace std;

int main() {
	Sales_item a, b;
	std::cin >> a >> b ;
	if (a.isbn() == b.isbn()) {
		cout << "��ͬ";
	}
	else {
		cout << "����ͬһ�鼮";
	}
		return 0;
}
