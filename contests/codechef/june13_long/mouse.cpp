#include <cstdio>
#include <cstring>
#include <vector>

#define MAX 10001
#define VI vector<int>
#define push push_back
#define println printf("\n")
using namespace std;

int m,n;
int ar[100][100];
VI dp[100][100];

inline int check(int x, int y) { return !(x < 0 || y < 0 || x >= m || y >= n); }
inline int find(VI::iterator a, VI::iterator b, int s)
{
	while(a != b)
	{
		if(*a == s) return 1;
		a++;
	}
	return 0;
}

int f(int x, int y)
{
	if(!check(x,y)) return MAX;
	if(x == m-1 && y == n-1) return dp[x][y].size();
	if(dp[x][y].size() > 0) return dp[x][y].size();
	int a = f(x,y+1), b = f(x+1,y);
	VI *v = a<b ? &dp[x][y+1] : &dp[x+1][y];
	if(a == b && check(x+1,y) && check(x,y+1))
	{
		int p = find(dp[x+1][y].begin(), dp[x+1][y].end(), ar[x][y+1]), q = find(dp[x][y+1].begin(), dp[x][y+1].end(), ar[x+1][y]);
		if(p + q == 1) v = p ? &dp[x+1][y] : &dp[x][y+1];
	}
	dp[x][y].assign((*v).begin(), (*v).end());
	if( check(x-1,y) && ar[x-1][y] && !find((*v).begin(),(*v).end(),ar[x-1][y]) ) dp[x][y].push(ar[x-1][y]);
	if( check(x+1,y) && ar[x+1][y] && !find((*v).begin(),(*v).end(),ar[x+1][y]) ) dp[x][y].push(ar[x+1][y]);
	if( check(x,y+1) && ar[x][y+1] && !find((*v).begin(),(*v).end(),ar[x][y+1]) ) dp[x][y].push(ar[x][y+1]);
	if( check(x,y-1) && ar[x][y-1] && !find((*v).begin(),(*v).end(),ar[x][y-1]) ) dp[x][y].push(ar[x][y-1]);
	return dp[x][y].size();
}

int main()
{
	int t; scanf("%d",&t);
	char s[101];
	while(t--)
	{
		int a,b,k=1;
		scanf("%d %d\n",&m,&n);
		for(a=0;a<m;a++)
		{
			gets(s);
			for(b=0;b<n;b++)
			{
				dp[a][b].clear();
				ar[a][b] = s[b]-48;
				if(ar[a][b]) ar[a][b] = k++;
			}
		}
		if(ar[m-1][n-1]) dp[m-1][n-1].push(ar[m-1][n-1]);
		if(ar[m-1][n-2]) dp[m-1][n-1].push(ar[m-1][n-2]);
		if(ar[m-2][n-1]) dp[m-1][n-1].push(ar[m-2][n-1]);
		f(0,0);
		for(a=0;a<m;a++,println) for(b=0;b<n;b++) printf("%3d",ar[a][b]);
		for(a=0;a<dp[0][0].size();a++) printf("%d ",dp[0][0][a]);
		println;
		for(a=0;a<dp[0][1].size();a++) printf("%d ",dp[0][1][a]);
		println;
		for(a=0;a<dp[1][0].size();a++) printf("%d ",dp[1][0][a]);
		println;
		for(a=0;a<dp[1][1].size();a++) printf("%d ",dp[1][1][a]);
		//printf("%d\n",f(0,0));
	}
	return 0;
}
