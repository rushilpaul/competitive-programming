#include <stdio.h>
#include <string.h>
typedef long long LL;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		LL m;
		int a,b,n; scanf("%d %lld",&n,&m);
		LL ar[n];
		for(a=0;a<n;a++) scanf("%lld",&ar[a]);
		for(a=0;a<n;a++)
		for(b=0;b<n-a-1;b++)
			if(ar[b] < ar[b+1])
			{
				LL tmp = ar[b];
				ar[b] = ar[b+1];
				ar[b+1] = tmp;
			}
		for(a=0;a<n;a++)
		{
			m -= ar[a];
			if(m <= 0) { printf("%d\n",a+1); goto next; }
		}
		if(m > 0) printf("-1\n");
		next:;
	}
}
