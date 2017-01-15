//Program question at: http://www.codechef.com/MAY12/problems/MEDIAN
#include <stdio.h>

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n], max=0,t=0,a;
		for(a=0;a<n;a++) { int m; scanf("%d",&m); if(m > max) max = m; ar[a] = m; }
		for(a=0;a<n;a++) if(ar[a] == max) t++;
		a=0;
		if(n==1) { printf("0\n"); continue; }
		while (n>0)
		{
			t <<= 1;
			n -= t;
			a++;
		}
		printf("%d\n",a);
	}
	return 0;
}
