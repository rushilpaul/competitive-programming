#include <cstdio>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		long long int s=0;
		for(int a=0;a<n;a++)
		{
			long long q; scanf("%lld",&q);
			s += q;
			s %= n;
		}
		if(s)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

