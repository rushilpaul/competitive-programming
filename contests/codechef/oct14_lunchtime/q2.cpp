// Program question: www.codechef.com/LTIME17/problems/ANDTUPLE
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define mod 1000000009

void read(int &n) { scanf("%d",&n); }
void read(LL &n) { scanf("%lld",&n); }
void read(double &n) { scanf("%f",&n); }
void read(long double &n) { scanf("%lf",&n); }

LL dp[64][5][4];

LL f(int i, int c, LL n, int k)
{
	if(i < 0) return c==0 ? 1 : 0;
	LL ans=0;
	int bit = (n & (1LL<<i)) ? 1 : 0;
	for(int s=0;s<=k;s++)
	{
		for(int c2=0;c2<=3;c2++)
			if( (s+c2)/2 == c && ((s+c2)&1) == bit)
			{
				LL &d = dp[i][s][c];
				if(d == -1) d = f(i-1,c2,n,k);
				ans = (ans + d) % mod;
			}
	}
	return ans;
}

int main()
{
	int t; read(t);
	while(t--)
	{
		for(int a=0;a<64;a++) for(int b=0;b<5;b++) for(int c=0;c<4;c++) dp[a][b][c] = -1;
		LL n; int k,bits=0; read(k); read(n);
		LL tmp = n;
		while(tmp) { bits++; tmp >>= 1; }
		printf("%lld\n",f(bits-1,0,n,k));
	}
	return 0;
}
