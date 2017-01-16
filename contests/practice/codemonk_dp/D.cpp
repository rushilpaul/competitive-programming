// https://www.hackerearth.com/code-monk-dynamic-programming/algorithm/samu-and-shooting-game/
#include <bits/stdc++.h>
typedef long double LD;
using namespace std;

LD dp[1001][1001], p1,p2;
char done[1001][1001];
int x,y;

LD f(int n, int w)
{
	if(w <= 0) return 1;
	if(n <= 0) return 0;
	LD &ret = dp[n][w];
	if(done[n][w])
		return ret;
	LD ans = max(f(n-1,w-x) * p1 + f(n-1,w) * (1-p1), f(n-1,w-y) * p2 + f(n-1,w) * (1-p2));
	done[n][w] = 1;
	return ret = ans;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,w;
		scanf("%d %d %d %d %Lf %Lf",&x,&y,&n,&w,&p1,&p2);
		p1 /= 100.0;
		p2 /= 100.0;
		memset(done,0,sizeof(done));
		LD ans = f(n,w);
		printf("%.6lf\n", (double)ans * 100);
	}
	return 0;
}

