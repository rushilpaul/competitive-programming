//Program question at: http://www.codechef.com/COOK06/problems/CHEFTEAM
#include <stdio.h>
typedef unsigned long long LL;
LL hcf(LL x, LL y)
{
	return (!x || !y) ? x+y : hcf(y,x%y);
}

int main(void)
{
	int t; scanf("%d",&t);
	while(t--)
	{
		LL n,k,a=1,ans=1; scanf("%llu %llu", &n, &k);
		if(n-k == 1 || k==1) { printf("%llu\n",n); continue; }
		else if(n==k || k==0) { printf("%d\n",1); continue; }
		if(k > n-k) k = n-k;
		for(a=1;a<=k;a++)
		{
			int h = hcf(ans,a);
			ans = (ans/h) * ((n-a+1) / (a/h));
		}
		printf("%llu\n",ans);
	}
	return 0;
}
