#include <stdio.h>
int ar[100][100], rowmin[100], colmin[100], m,n;

int checkrow(int r, int num)	// checks if row r contains only num
{
	int a;
	for(a=0;a<n;a++) if(ar[r][a] != num) return 0;
	return 1;
}

int checkcol(int c, int num)	// checks if col c contains only num
{
	int a;
	for(a=0;a<m;a++) if(ar[a][c] != num) return 0;
	return 1;
}

int main()
{
	int a,b,tc,t; scanf("%d\n",&tc);
	for(t=1;t<=tc;t++)
	{
		int min; scanf("%d %d\n",&m,&n);
		for(a=0;a<m;a++) for(b=0;b<n;b++) scanf("%d",&ar[a][b]);
		for(a=0;a<m;a++)
		{
			min = ar[a][0];
			for(b=1;b<n;b++)
				if(ar[a][b] < min) min = ar[a][b];
			rowmin[a] = min;
		}
		for(a=0;a<n;a++)
		{
			min = ar[0][a];
			for(b=1;b<m;b++)
				if(ar[b][a] < min) min = ar[b][a];
			colmin[a] = min;
		}
		for(a=0;a<m;a++)
		for(b=0;b<n;b++)
		{
			if(ar[a][b] != rowmin[a]) continue;
			if(!checkrow(a,rowmin[a]))
			{
				if(rowmin[a] == colmin[b] && !checkcol(b,rowmin[a])) goto NO;
			}
		}
		printf("Case #%d: YES\n",t);
		continue;
		NO:
		printf("Case #%d: NO\n",t);
	}
}
