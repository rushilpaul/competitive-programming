#include <cstdio>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,k; scanf("%d %d",&n,&k);
		int ans = 0;
		for(int a=0;a<n;a++)
		{
			int x; scanf("%d",&x);
			if((x + k) % 7 == 0)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
