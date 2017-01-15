//Program question at: http://www.codechef.com/COOK21/problems/RESIST/
#include <stdio.h>
typedef unsigned long long LL;

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a,n;
		LL p=1,q=1,mod;
		scanf("%d %llu",&n,&mod);
		if (n==1) { printf("1\n"); continue; }
		while(n-- != 1)
		{
			p += q;
			while(p > mod) p-=mod;
			q += p;
			while(q > mod) q-=mod;
		}
		printf("%d/%d\n",(int)p,(int)q);
	}
	return 0;
}
