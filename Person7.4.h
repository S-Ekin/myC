#ifndef ex7_04;
#define ex7_04;
#include <string>;
#include <iostream>;
using std::string; using std::istream; using std::ostream;
class Person {
	// ��Ԫ
	friend ostream& print(ostream& os, const Person& a);
	friend istream& read(istream& is, Person& a);
private:
	string adress;
	string name;
public: 
	Person() = default;
	Person(string a, string b) :name(a),adress(b){}
	auto get_name()const ->string const& { return name; }; // this ��const �����ĳ�Ա���ص�Ҳ����const
	auto get_adress()const ->string const& { return adress; };
 };

ostream& print(ostream& os, const Person& a) {
	os << a.adress<<" "<< a.name;
	return os;
}
istream& read(istream& is, Person& a) {
	is >> a.name >> a.adress;
	return is;
}



#endif // !ex7_04;

