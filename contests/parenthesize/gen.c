// Q 2
#include <stdio.h>
#include <string.h>
int main()
{
	int done[10000];
	while(1)
	{
		int ans=1,a,n; scanf("%d",&n);
		if(!n) break;
		int D[8];
		memset(done,0,sizeof(int)*10000);
		done[n] = 1;
		while(1)
		{
			n *= n;
			memset(D,0,sizeof(int)*8);
			for(a=7;a>=0 && n;a--)
			{
				D[a] = n%10;
				n /= 10;
			}
			for(a=2;a<6;a++) n = 10*n + D[a];
			if(done[n]) { printf("%d\n",ans); break; }
			ans++;
			done[n] = 1;
		}
	}
	return 0;
}
