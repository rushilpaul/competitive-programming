#include <cstdio>

#define MAX 100001
int A[MAX], ans[MAX];

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		for(int a=0;a<n;a++)
			scanf("%d", &A[a]);

		ans[n-1] = 1;
		for(int a=n-2;a>=0;a--)
		{
			if(1ll * A[a] * A[a+1] < 0)
				ans[a] = ans[a+1] + 1;
			else
				ans[a] = 1;
		}
		for(int a=0;a<n;a++)
			printf("%d ", ans[a]);
		printf("\n");
	}
	return 0;
}
