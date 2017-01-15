// https://www.hackerrank.com/contests/ie-cse-summer-codeheat/challenges/marbles-1
#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

int main()
{
	int m,n; scanf("%d %d",&n,&m);
	LD ans = 0;
	int L = min(n,m);
	LD P = (n-1)*m;
	for(int i=n-L;i<=n-1;i++)
	{
		LD term = 1;
		for(int j=0;j<=i-1;j++)
			term *= (P-j)/(i-j);
		for(int j=0;j<=n-i-1;j++)
			term *= (LD)(m-j) / (n-i-j);
		for(int j=0;j<=n-1;j++)
			term *= (LD)(n-j) / (m*n-j);
		term /= n;
		term *= (n-i) * (n-i);
		ans += term;
	}
	printf("%.16Lf\n",ans);
	return 0;
}
