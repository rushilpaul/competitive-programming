#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int r,g,b,m; scanf("%d %d %d %d",&r,&g,&b,&m);
		int maxr=0, maxg=0, maxb=0, k;
		for(int a=0;a<r;a++) { scanf("%d",&k); maxr = max(maxr,k); }
		for(int a=0;a<g;a++) { scanf("%d",&k); maxg = max(maxg,k); }
		for(int a=0;a<b;a++) { scanf("%d",&k); maxb = max(maxb,k); }
		int ar[3] = { maxr, maxg, maxb }, mx,i;
		while(m--)
		{
			mx = 0;
			for(int a=0;a<3;a++)
				if(ar[a] >= mx) { mx = ar[a]; i = a; }
			ar[i] /= 2;
		}
		mx = 0;
		for(int a=0;a<3;a++)
			mx = max(mx,ar[a]);
		printf("%d\n",mx);
	}
	return 0;
}
