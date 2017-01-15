#include <cstdio>
using namespace std;

int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n,r; scanf("%d %d", &n,&r);
		int c = n-r;
		if( n-r > r)
		{
			c = r;
			r = n-c;
		}
		double tmp=1;
		for(double i=r+1,j=1;i<=n;i++)
		{
			tmp = tmp * (i/j);
			if(j<c) j++;
			else j=1;
		}
		long ans = (long)tmp, copy = ans;
		int n10=0, n2=0;
		while(copy!=0)
		{
			n10++; copy /= 10;
		}
		while(ans != 0)
		{
			n2++; ans >>= 1;
		}
		printf("%d %d\n", n10, n2);
	}
	return 0;
}

