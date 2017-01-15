//Program question at: http://www.codechef.com/MAY12/problems/CHEFLUCK
#include <stdio.h>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,r,k=0; scanf("%d",&n);
		r = n%7;
		while( (r+3*k) % 4) k++;
		int ans = n-r-7*k;
		if(ans < 0) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
