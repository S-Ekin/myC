#include <iostream>;
#include "Sales.item.h";
using namespace std;

int main() {
	Sales_item a, b;
	std::cin >> a >> b ;
	if (a.isbn() == b.isbn()) {
		cout << "相同";
	}
	else {
		cout << "不是同一书籍";
	}
		return 0;
}
