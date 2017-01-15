#include <stdio.h>

int fact(int n)
{ return n<=1 ? 1 : n*fact(n-1); }

inline int nCr(int n, int r)
{ return fact(n) / (fact(r) * fact(n-r)); }

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int score[11],a,b;
		for(a=0;a<11;a++) scanf("%d",&score[a]);
		for(a=0;a<11;a++)
		for(b=0;b<10;b++)
			if(score[b]<score[b+1])
			{
				score[b] ^= score[b+1];
				score[b+1] ^= score[b];
				score[b] ^= score[b+1];
			}
		int k; scanf("%d",&k);
		int m = score[k-1], tot=0, n=0;
		for(a=0;a<11;a++)
			if(score[a] == m) { tot++;
			if(a<k) n++; }
		printf("%d\n",nCr(tot,n));
	}
	return 0;
}
