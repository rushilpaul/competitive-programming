#include <cstdio>
#include <iostream>
using namespace std;

class A
{
	public:
	int a;
	A() {}
	A(int a) : a(a) {}
	A(A& ob) // copy constructor
	{
		cout << ob.a << endl;
		a = ob.a;
	}
	A operator=(A &ob)
	{
		a = ob.a;
		cout << "copying " << ob.a << endl;
	}
};

int main()
{
	A ob(A(1));
}
