#include <cstdio>
#include <cmath>
typedef long long LL;
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		LL n,k,l; scanf("%lld %lld %lld",&n,&k,&l);
		LL ar[n];
		for(int a=0;a<n;a++)
		{
			ar[a] = l % k;
			if(ar[a] == 0) ar[a] = k;
			if(l % k == 0) l = l/k;
			else l = l/k + 1;
		}
		for(int a=n-1;a>=0;a--) printf("%lld ",ar[a]);
		printf("\n");
	}
	return 0;
}

