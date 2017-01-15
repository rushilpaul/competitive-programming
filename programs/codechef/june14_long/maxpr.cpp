#include <cstdio>
#define mod 1000000007
typedef long long LL;
using namespace std;

LL pow2(int p)	// 2^p
{
	if(p == 0) return 1;
	LL a = pow2(p/2);
	if(p&1) return (a*a*2)%mod;
	else return (a*a)%mod;
}

int f(int *ar, int n, int last, int cd, int i)
{
	if(i == n) return 0;
	int ans = 0;
	for(int a=i;a<n;a++)
	{
		if(ar[a] != last+cd) ans = (ans+pow2(n-a-1)) % mod;
		else ans = (ans + f(ar,n,ar[a],cd,a+1)) % mod;
	}
	return ans;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n];
		for(int a=0;a<n;a++) scanf("%d",ar+a);
		int ans = 0;
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
		{
			ans = (ans + f(ar,n,ar[b],ar[b]-ar[a],b+1)) % mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
