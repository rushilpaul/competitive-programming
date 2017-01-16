//Program question at: http://www.codechef.com/BTCD2012/problems/EVILHACK
#include <stdio.h>
#include <math.h>
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int x,y; scanf("%d %d",&x,&y);
		if(!x || !y) { printf("0\n"); continue; }
		if(x == 1) { printf("%.0f\n",y%2 ? round(y/2.0) : y/2+1); continue; }
		if(y == 1) { printf("%.0f\n",x%2 ? round(x/2.0) : x/2+1); continue; }
		if(!(x%2)) x++;
		if(!(y%2)) y++;
		int sm = x<y ? x:y, lar = x>y ? x:y;
		printf("%d\n",(lar-sm)/2 + sm);
	}
	return 0;
}
