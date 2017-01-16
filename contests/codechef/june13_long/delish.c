#include <stdio.h>
typedef long long LL;
inline LL max(int a, int b) { return a>b ? a:b; }
inline LL min(int a, int b) { return a<b ? a:b; }
inline LL abs(LL a) { return a>0?a:-a; }
inline int sign(int a, int b) { return (a>0 && b>0) || (a<0 && b<0); }
int ar[10000];
LL sum[10000];

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,n,pos=0,neg=0;
		scanf("%d",&n);
		for(a=0;a<n;a++)
		{
			scanf("%d",&ar[a]);
			if(!ar[a]) { n--; a--; continue; }
			if(ar[a] > 0) pos++;
			else neg++;
			if(a) sum[a] = sum[a-1] + ar[a];
			else sum[0] = ar[0];
		}
		if(!n) { printf("0\n"); continue; }
		LL ans=0;
		if( (pos > 0 && neg == 0) || (pos == 0 && neg > 0) )
		{
			LL total = sum[n-1];
			for(a=0;a<n;a++)
				ans = max(ans, abs(abs(ar[a]) - max(abs(a?sum[a-1]:0), abs(total)-abs(sum[a]))) );
		}
		else
		{
			pos = neg = 0;
			int p=0,q=0;
			if(ar[0] > 0) p = ar[0]; else q = ar[0];
			for(a=1;a<n;a++)
			{
				if(!sign(ar[a-1],ar[a]))
				{
					pos = max(pos,p);
					neg = min(neg,q);
					p = q = 0;
				}
				if(ar[a] > 0) p += ar[a];
				else q += ar[a];
			}
			pos = max(pos,p);
			neg = min(neg,q);
			ans = abs(pos-neg);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
