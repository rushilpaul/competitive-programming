#include <cstdio>
using namespace std;

int K,L;
int dp[1000001];

void f()
{
	dp[0] = 0;
	for(int a=1;a<=1000000;a++)
	{
		int v = dp[a-1];
		if(a-L >= 0) v &= dp[a-L];
		if(a-K >= 0) v &= dp[a-K];
		v = !v;
		dp[a] = v;
	}
}

int main()
{
	int t; scanf("%d %d %d",&K,&L,&t);
	f();
	while(t--)
	{
		int n; scanf("%d",&n);
		printf("%c",dp[n] ? 'A' : 'B');
	}
	return 0;
}
