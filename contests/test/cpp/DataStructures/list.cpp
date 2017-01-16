#include <iostream>
#include <list>
using namespace std;

void add(list<int> L, int n);

void add(list<int> *L, int n)
{
	(*L).push_back(n);
}

int main()
{
	list<int> ar;
	for(int a=0;a<10;a++)
		add(&ar,a+1);
	ar.reverse();
	for(list<int>::iterator i = ar.begin(); i != ar.end(); i++)
		cout << *i << " ";
	cout << endl;
	return 0;
}
