#include <cstdio>
#define mod 1000000007LL
typedef long long LL;
int main()
{
	int n,k,a; scanf("%d %d",&n,&k);
	int ar[n];
	LL ans=1;
	for(a=0;a<n;a++) scanf("%d",&ar[a]);
	for(a=0;a<n-1;a++)
	{
		if(ar[a] == 1) continue;
		for(int b=a+1;b<n;b++)
		if(ar[b] < ar[a]) { ans *= (b-a+1); ans%=mod; break; }
	}
	printf("%lld\n",ans);
	return 0;
}
