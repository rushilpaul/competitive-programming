#include <stdio.h>

int main()
{
	int n; scanf("%d\n",&n);
	int ar[n][2],ans=0,max,a,b;
	for(a=0;a<n;a++) scanf("%d %d", &ar[a][0], &ar[a][1]);
	for(a=0;a<n-2;a++)
	{
		double m = (ar[a+1][1]-ar[a][1]) / (ar[a+1][0]-ar[a][0]);
		max=0;
		for(b=a+2;b<n;b++)
			if ( (ar[b][1]-ar[a][1]) / (ar[b][0]-ar[a][0]) == m ) max++;
			
		if(max > ans) ans = max;
	}
	printf("%d\n",ans+2);
	return 0;
}
