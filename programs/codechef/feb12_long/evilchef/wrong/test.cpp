#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define VI vector<int>
#define VVI vector< VI >

void f()
{
	for(int a=0;a<5;a++)
		for(int b=0;b<5;b++)
			for(int c=0;c<5;c++)
				if(c==2) goto out;
	out:
	cout << "Finished\n";
}

int main()
{
	f();
	return 0;
	VVI ar(2,VI(3));
	VVI::iterator a = ar.begin();
	for(;a<ar.end();a++)
		{
			
			for(vector<int>::iterator b=(*a).begin();b!=(*a).end();b++)
				cin >> *b;
		}
	a = ar.begin();
	for(;a<ar.end();a++)
	{
		for(vector<int>::iterator b=(*a).begin();b!=(*a).end();b++) cout << *b << " ";
		cout << endl;
	}
	return 0;
}
