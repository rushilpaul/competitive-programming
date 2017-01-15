#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

int L;
int dp[100000][3];
int ar[100000][3];
int path1[100000], path2[100000];

int f(int i, int j, int *P)
{
	if(i == L) return 0;
	int &r = dp[i][j];
	if(r >= 0) return r;
	int cost1 = f(i+1,j,P) + ar[i][j];
	int cost2 = f(i+1,j == 0 ? 2:0,P) + ar[i][j] + ar[i][1];
	if(cost1 < cost2)
		P[i] = j;
	else
		P[i] = j == 0 ? 2:0;
	return r = min(cost1,cost2);
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n; scanf("%d",&n);
	L = n/3 + 1;
	for(int a=0;a<L;a++)
	{
		if(a == L-1)
		{
			int i,j; scanf("%d %d",&i,&j);
			ar[a][0] = i;
			ar[a][1] = INT_MAX/5;
			ar[a][2] = j;
			continue;
		}
		int i,j,k; scanf("%d %d %d",&i,&j,&k);
		ar[a][0] = i;
		ar[a][1] = k;
		ar[a][2] = j;
	}
	int cost1 = INT_MAX, cost2 = f(0,2,path2);
	for(int a=0;a<L;a++) printf("%d ",path2[a]);
	if(cost1 < cost2)
		printf("A");
	else
		printf("B");
	/*
	for(int a=0;a<L;a++)
	{
		if(path[a] == -1) continue;
		if(path[a] != path[a+1])
			printf("C");
		printf("%c",path[a] == 0 ? 'A' : 'B');
	}
	*/
	printf(" %d\n",min(cost1,cost2));
	return 0;
}

