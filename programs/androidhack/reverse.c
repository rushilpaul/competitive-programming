//Program question at: http://www.codechef.com/ANDR2012/problems/A112
#include <stdio.h>

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a,b; scanf("%d %d",&a,&b);
		int na=0, nb=0;
		while (a) { na = na*10 + a%10; a/=10; }
		while (b) { nb = nb*10 + b%10; b/=10; }
		na += nb;
		while(!(na%10)) na/=10;
		while(na) { printf("%d",na%10); na/=10; }
		printf("\n");
	}
	return 0;
}
