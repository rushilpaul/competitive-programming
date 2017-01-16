#include <stdio.h>
#include <string.h>
#define MAX 10001
int m,n,dp[100][100],ar[100][100],done[10001],ans;
char s[10001];

inline int min(int a, int b) { return a<b?a:b; }
inline int check(int x, int y) { return !(x<0 || y<0 || x>=m || y>=n); }

int f(int x, int y)
{
	if(!check(x,y)) return MAX;
	int p=0;
	if(x == m-1 && y == n-1)
	{
		if(ar[x][y] && !done[ar[x][y]]) p++;
		if(ar[x][y-1] && !done[ar[x][y-1]]) p++;
		if(ar[x-1][y] && !done[ar[x-1][y]]) p++;
		return p;
	}
	if(ar[x][y] && !done[ar[x][y]]) { done[ar[x][y]] = 1; p++; }
	if(check(x-1,y) && ar[x-1][y] && !done[ar[x-1][y]]) { done[ar[x-1][y]] = 1; p++; }
	if(check(x+1,y) && ar[x+1][y] && !done[ar[x+1][y]]) { done[ar[x+1][y]] = 1; p++; }
	if(check(x,y-1) && ar[x][y-1] && !done[ar[x][y-1]]) { done[ar[x][y-1]] = 1; p++; }
	if(check(x,y+1) && ar[x][y+1] && !done[ar[x][y+1]]) { done[ar[x][y+1]] = 1; p++; }
	int r = f(x,y+1), r1 = f(x+1,y);
	r = min(r,r1);
	
	done[ar[x][y]] = 0;
	if(check(x-1,y)) done[ar[x-1][y]] = 0;
	if(check(x+1,y)) done[ar[x+1][y]] = 0;
	if(check(x,y-1)) done[ar[x][y-1]] = 0;
	if(check(x,y+1)) done[ar[x][y+1]] = 0;
	return r+p;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,b,k=1;
		scanf("%d %d\n",&m,&n);
		for(a=0;a<m;a++)
		{
			gets(s);
			for(b=0;b<n;b++)
			{
				ar[a][b] = s[b]-48;
				if(ar[a][b]) ar[a][b] = k++;
			}
		}
		memset(done,0,sizeof(int)*10001);
		memset(dp,0,sizeof(int)*10000);
		printf("%d\n",f(0,0));
	}
}
