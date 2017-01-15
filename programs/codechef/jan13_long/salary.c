//Program question at: http://www.codechef.com/JAN13/problems/SALARY
#include <stdio.h>
int main()
{
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
		int min=10000,a,n;
		scanf("%d\n",&n);
		int ar[n],ans=0;
		for(a=0;a<n;a++) { scanf("%d",&ar[a]); if(ar[a] < min) min = ar[a]; }
		for(a=0;a<n;a++) ans += (ar[a]-min);
		printf("%d\n",ans);
	}
	return 0;
}
