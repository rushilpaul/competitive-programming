#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

int done[70][70];

LL f(LL p, LL n, int i, int j)
{
	if(p > n) return 0;
	if(done[i][j]) return 0;
	done[i][j] = 1;
	return 1+f(p*2,n,i+1,j)+f(p*3,n,i,j+1);
}

LL g(LL n)
{
	return f(2,n,1,0) + (n>=1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL L,R; scanf("%lld %lld",&L,&R);
		memset(done,0,sizeof(done));
		LL a = g(R);
		memset(done,0,sizeof(done));
		LL b = g(L-1);
		printf("%lld\n",a-b);
	}
	return 0;
}

