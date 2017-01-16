#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

namespace ns1
{
	class A
	{
		public:
		static const int a = 10;
	};
	struct man
	{
		char name[20];
		int sal;
		struct
		{
			int count;
			char mom[20],dad[20];
		}upper;
	};
}

union color
{
	int color;
	unsigned char argb[4];
};

int main()
{
	color c;
	c.color = 0x0ae6f0fa;
	cout << "ARGB = \n";
	for(int i=0;i<4;i++) cout << (int)c.argb[i] << " ";
	cout << endl;
	return 0;
}

