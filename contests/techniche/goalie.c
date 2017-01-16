//Program question at: http://www.codechef.com/BTCD2012/problems/GOALIE
#include <stdio.h>
#include <math.h>

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		start:;
		int n; scanf("%d",&n);
		if(n==1) { printf("1\n"); continue; }
		long long a = 1;
		while(a<=n) { a <<= 1; if(a==n) { printf("1\n"); goto start; } }
		a >>= 1;
		printf("%lld\n",2*(n%a+1)-1);
	}
	return 0;
}
