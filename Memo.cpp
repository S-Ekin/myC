#include <iostream>
using namespace std;

class Memo
{
public:
	virtual void Call() { cout << "Memo Call!" << endl; };
};

class Tiger :public Memo
{
public:
	virtual void Call() { cout << "Tiger Call!" << endl; };
	void text() { cout << "text" << endl; }
};

class Lion :public Memo
{
public:
	void Call() { cout << "Lion Call!" << endl; };
};

class Cat :public Memo
{
public:
	void Call() { cout << "Cat Call!" << endl; };
};

void Show(Memo* p)
{
	p->Call();
}

void Show(Memo m)
{
	m.Call();
}
int _main()
{
	Memo m;
	Memo* pm = &m;

	Tiger t;
	Tiger* pt = &t;

	Lion l;
	Lion* pl = &l;

	Cat c;
	Cat* pc = &c;

	m.Call();
	t.Call();
	m = t;
	t.text();
//	m.text(); //´íÎó
	//m = l;
	//m.Call();
	//
	//pm->Call();
	//pm = pt;
	//pm->Call();
	//pm = pl;
	//pm->Call();

	/*m.Call();
	t.Call();
	l.Call();
	c.Call();

	pm->Call();
	pt->Call();
	pl->Call();

	m = t;
	m.Call();
	pm->Call();

	pm = pt;
	pm->Call();
	*/

	return 0;
}