#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main()
{
	while(1)
	{
		int L,R;
		scanf("%d %d",&L,&R);
		if(L == -1) break;
		int n = R-L+1;
		int ar[n][n];
		printf("%5d",0);
		for(int a=0;a<n;a++) printf("%5d",a+L);
		printf("\n\n");
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(!b) printf("%5d",a+L);
				ar[a][b] = (a+L) ^ (b+L);
				printf("%5d",ar[a][b]);
			}
			printf("\n");
		}
	}
	return 0;
}
