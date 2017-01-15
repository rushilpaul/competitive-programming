//Program question at: http://www.codechef.com/JAN13/problems/LEALCO
#include <stdio.h>
int ar[17],n,k,m,ans,min;

inline int verify()
{
	int a,b,max,f;
	for(a=0;a<=n-k;a++)
	{
		max=f=0;
		for(b=a;b<a+k;b++)
			if(ar[b] > max) max = ar[b];
		for(b=a;b<a+k;b++)
			if(ar[b] == max) f++;
		if(f >= m) return 0;
	}
	return 1;
}

void solve(int i)
{
	if(i >= n)
	{
		if(verify())
			if(ans < min) min = ans;
		return;
	}
	solve(i+1);
	ar[i]++;
	ans++;
	solve(i+1);
	ans--;
	ar[i]--;
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a;
		min = 10000; ans = 0;
		scanf("%d %d %d",&n,&k,&m);
		for(a=0;a<n;a++) scanf("%d",&ar[a]);
		if(m == 1) { printf("-1\n"); continue; }
		solve(0);
		if(min == 10000) min = -1;
		printf("%d\n",min);
	}
	return 0;
}
