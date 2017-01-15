//Program question at: http://www.codechef.com/OCT12/problems/NEWSCH
#include <stdio.h>
#include <string.h>

int main()
{
	int r,c,a,b; scanf("%d %d",&r,&c);
	int ar[r][c],flag=1;
	for(a=0;a<r;a++) for(b=0;b<c;b++)
	{
		scanf("%d",&ar[a][b]);
		if(flag && ar[a][b] > 0) { printf("%d\n%d\n",a,b); flag = 0; }
	}
	return 0;
}
