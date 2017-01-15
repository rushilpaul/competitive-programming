// Program question at: http://www.codechef.com/OCT12/problems/DRGNBOOL
#include <stdio.h>
#include <string.h>
#define abs(x) x<0?-x:x
int main()
{
	int t, L[100]; scanf("%d\n",&t);
	while(t--)
	{
		int ans=0,a,n,m; scanf("%d %d",&n,&m);
		memset(L,0,100*sizeof(int));
		for(a=0;a<n;a++)
		{
			int c,l; scanf("%d %d",&c,&l);
			L[l-1] += c;
		}
		for(a=0;a<m;a++)
		{
			int c,l; scanf("%d %d",&c,&l);
			L[l-1] -= c;
		}
		for(a=0;a<100;a++)
			if(L[a] < 0) ans += abs(L[a]);
		printf("%d\n",ans);
	}
	return 0;
}
