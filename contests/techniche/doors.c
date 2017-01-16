//Program question at: http://www.codechef.com/BTCD2012/problems/DOORS
#include <stdio.h>
#include <math.h>
int main()
{
	int a,t; scanf("%d\n",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		printf("%d\n",(int)sqrt(n));
	}
	return 0;
}
