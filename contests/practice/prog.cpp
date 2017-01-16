#include <cstdio>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m; scanf("%d %d", &n, &m);
		long n2=1<<n;
		long m2=1<<m;
		double ans = 2*(n2-m2);
		printf("%.2f\n",ans);
	}
	return 0;
}
