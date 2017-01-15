#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m; scanf("%d %d",&n,&m);
		int ar[n],mx=0;
		for(int a=0;a<n;a++)
		{
			scanf("%d",&ar[a]);
			mx = max(mx,ar[a]);
		}
		if(n == 1) { printf("Yes\n"); continue; }
		int diff = 0;
		for(int a=0;a<n;a++)
			diff += (mx - ar[a]);
		m -= diff;
		if(m == 0 || (m > 0 && m % n == 0)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
