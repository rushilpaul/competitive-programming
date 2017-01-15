//Program question at: http://www.codechef.com/FEB12/problems/LUCKY1
#include <cstdio>
using namespace std;

#define max 100000

int F(int n,int d)
{
	int s=0;
	while(n)
	{
		if(n%10 == d) s++; n/=10;
	}
	return s;
}

int main()
{
	unsigned short ar4[max], ar7[max];

	for(int a=0;a<max;a++)
	{
		ar4[a] = F(a+1,4);
		ar7[a] = F(a+1,7);
		if(a==0) continue;
		ar4[a] += ar4[a-1];
		ar7[a] += ar7[a-1];
	}
	return 0;
}
