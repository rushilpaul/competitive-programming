#include <stdio.h>
#include <string.h>
#define br printf("\n")
int primes[2501];

void init()
{
	memset(primes,1,sizeof(int)*2501);
	int a,b;
	for(a=2;a<=50;a++)
	{
		if(!primes[a]) continue;
		for(b=a*a;b<=2500;b+=a)
			primes[b] = 0;
	}
}

int main()
{
	init();
	int t,T; scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		printf("Case #%d:\n",t);
		int r,c,clear,m,a,b; scanf("%d %d %d",&r,&c,&m);
		clear = r*c - m;
		if(r == 1 || c == 1)
		{
			int k=0;
			for(a=0;a<r;a++,br)
			for(b=0;b<c;b++)
				if(!a && !b) printf("c");
				else if(k++ < r*c-m-1) printf(".");
				else printf("*");
			continue;
		}
		if(!primes[clear])
		{
			int p=2;
			while( (clear % p) || (p > r || clear/p > c) ) p++;
			for(a=0;a<r;a++,br)
			for(b=0;b<c;b++)
			{
				if(!a && !b) { printf("c"); continue; }
				if(a < p && b < clear/p) printf(".");
				else printf("*");
			}
		}
		else printf("Impossible\n");
	}
	return 0;
}
