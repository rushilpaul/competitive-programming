#include <stdio.h>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		long long n,ans; scanf("%lld\n",&n);
		ans = (n*(n-1))/2;
		char ch;
		fscanf(stdin,"%*d");
		printf("%lld\n",ans);
	}
	return 0;
}
