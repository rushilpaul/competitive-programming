#include <stdio.h>
#include <string.h>
#define MAX 10001
#define println printf("\n")
int m,n, ar[100][100], dp[100][100], dp2[100][100], s;
int pathx[100], pathy[100];
char str[101];

inline int min(int a, int b) { return a<b?a:b; }
inline int check(int x, int y) { return !(x < 0 || y < 0 || x >= m || y >= n); }

int sum(int x, int y)
{
	if(!check(x,y)) return MAX;
	if(x == m-1 && y == n-1) return dp[x][y];
	if(dp2[x][y] != -1) return dp2[x][y];
	dp2[x][y] = dp[x][y] + min( sum(x+1,y), sum(x,y+1) );
	return dp2[x][y];
}

int f(int x, int y, int i, int d)
{
	if(!check(x,y)) return 0;
	if(x == m-1 && y == n-1)
	{
		if(d + dp[x][y] == s) { pathx[i] = x; pathy[i] = y; return 1; }
		else return 0;
	}
	pathx[i] = x; pathy[i] = y;
	if(f(x+1,y,i+1,d+dp[x][y])) return 1;
	if(f(x,y+1,i+1,d+dp[x][y])) return 1;
	return 0;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d\n",&m,&n);
		for(a=0;a<m;a++)
		{
			gets(str);
			for(b=0;b<n;b++)
			{
				dp[a][b] = 0;
				dp2[a][b] = -1;
				ar[a][b] = str[b]-48;
			}
		}
		for(a=0;a<m;a++) for(b=0;b<n;b++)
			if(ar[a][b])
			{
				dp[a][b]++;
				if(check(a,b+1)) dp[a][b+1]++;
				if(check(a,b-1)) dp[a][b-1]++;
				if(check(a+1,b)) dp[a+1][b]++;
				if(check(a-1,b)) dp[a-1][b]++;
			}
		for(a=0;a<m;a++,println) for(b=0;b<n;b++) printf("%2d",ar[a][b]);
		s = sum(0,0);
		f(0,0,0,0);
		int x,y; s = 0;
		for(a=0;a<m+n-1;a++)
		{
			x = pathx[a]; y = pathy[a];
			if(ar[x][y]==1) { s++; ar[x][y] = 2; }
			if(check(x+1,y) && (ar[x+1][y]==1)) { s++; ar[x+1][y] = 2; }
			if(check(x-1,y) && (ar[x-1][y]==1)) { s++; ar[x-1][y] = 2; }
			if(check(x,y+1) && (ar[x][y+1]==1)) { s++; ar[x][y+1] = 2; }
			if(check(x,y-1) && (ar[x][y-1]==1)) { s++; ar[x][y-1] = 2; }
		}
		printf("%d\n",s);
	}	return 0;
}
