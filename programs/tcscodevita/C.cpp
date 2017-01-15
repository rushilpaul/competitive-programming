#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

int main()
{
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++)
		scanf("%d",&ar[a]);
	sort(ar,ar+n);
	int x; scanf("%d",&x);
	for(int a=0;a<n;a++)
	{
		for(int b=a+1;b<n;b++)
		{
			int i = lower_bound(ar+b+1,ar+n,x-ar[a]-ar[b]) - ar;
			if(i < n and ar[a] + ar[b] + ar[i] == x)
			{
				printf("True");
				return 0;
			}
		}
	}
	printf("False");
}

