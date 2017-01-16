#include <cstdio>
using namespace std;
typedef long long LL;

inline LL pow_(int n, int k)
{
	LL ans=1;
	for(int a=0;a<k;a++) ans *= n;
	return ans;
}

int main()
{
	int t,m; scanf("%d %d",&t,&m);
	while(t--)
	{
		int n,k; scanf("%d %d",&n,&k);
		long ans=1;
		LL npk = pow_(n,k);
		for(int a=0;a<npk;a++)
		{
			ans *= 3;
			if(ans >= m) ans %= m;
		}
		printf("%ld\n",ans);
	}
	return 0;
}
