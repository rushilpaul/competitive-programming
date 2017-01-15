//Program question at: http://www.codechef.com/AUG12/problems/DRANGE
#include <stdio.h>
typedef long long LL;
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a,n,m; scanf("%d %d\n",&n,&m);
		LL ar[n], min=1, max=n;
		int op,x,y,k,tmp;
		for(a=0;a<n;a++) ar[a] = (LL)(a+1);
		for(a=0;a<m;a++)
		{
			scanf("%d %d %d %d",&op,&x,&y,&k);
			x--; y--; tmp = x;
			for(;x<=y;x++)
				ar[x] = op == 1 ? ar[x]+k : ar[x]-k;
			if(ar[tmp] < min) min = ar[tmp];
			if(ar[y] > max) max = ar[y];
		}
		printf("%lld\n",max-min);
	}
	return 0;
}
