#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int m; scanf("%d",&m);
		double p; scanf("%lf",&p);
		double val = 1e9 * p * (1 - pow(-p,m-1)) / (1+p);
		printf("%lf %lf\n",1e9-val,val);
	}
	return 0;
}

