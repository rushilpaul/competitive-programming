// Find the sum of the maximum sum increasing subsequence
#include <cstdio>

int main()
{
	int n; scanf("%d",&n);
	int ar[n], L[n];
	for(int a=0;a<n;a++)
	{
		scanf("%d",&ar[a]);
		L[a] = ar[a];
	}
	for(int a=1;a<n;a++)
		for(int b=0;b<a;b++)
			if(ar[a] > ar[b] and L[b] + ar[a] > L[a])
				L[a] = L[b] + ar[a];
	int ans = -999;
	for(int a=0;a<n;a++)
		if(L[a] > ans)
			ans = L[a];
	printf("%d\n",ans);
	return 0;
}
