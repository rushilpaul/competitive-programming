#include <stdio.h>
#include <string.h>
int m,n;

int valid(int x, int y)
{
	if(x<0 || y<0 || x>=m || y>=n) return 0;
	return 1;
}

int main()
{
	int p;
	for(p=1;;p++)
	{
		int a,b;
		scanf("%d %d",&m,&n);
		if(m == 0) return 0;
		char s[m][n+1];
		gets(s[0]);
		for(a=0;a<m;a++) gets(s[a]);
		int ar[m][n];
		memset(ar,0,sizeof(int)*m*n);
		int x,y;
		for(x=0;x<m;x++)
		for(y=0;y<n;y++)
			if(s[x][y] == '*')
			{
				if(valid(x,y+1)) ar[x][y+1]++;
				if(valid(x,y-1)) ar[x][y-1]++;
				if(valid(x-1,y)) ar[x-1][y]++;
				if(valid(x+1,y)) ar[x+1][y]++;
		
				if(valid(x+1,y+1)) ar[x+1][y+1]++;
				if(valid(x+1,y-1)) ar[x+1][y-1]++;
				if(valid(x-1,y+1)) ar[x-1][y+1]++;
				if(valid(x-1,y-1)) ar[x-1][y-1]++;
			}
		printf("Field #%d\n",p);
		for(a=0;a<m;a++,printf("\n")) for(b=0;b<n;b++)
		{
			if(s[a][b] == '*') printf("*");
			else printf("%d",ar[a][b]);
		}
		printf("\n");
	}
}
