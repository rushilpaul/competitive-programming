#include <stdio.h>

int gcd(int x, int y)
{
	if(x == y) return 0;
	else if(x/y >= 2) return 1;
	if(x/y == 1 && x%y) return 1-gcd(y,x%y);
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int i,j,a,n; scanf("%d",&n);
		int ans=0;
		for(a=0;a<n;a++)
		{
			scanf("%d %d",&i,&j);
			if(i < j) { i ^= j; j ^= i; i ^= j; }
			ans ^= gcd(i,j);
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
