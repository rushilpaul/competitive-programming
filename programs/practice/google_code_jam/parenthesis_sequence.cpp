// https://code.google.com/codejam/contest/4214486/dashboard#s=p3
#include <cstdio>
#include <cstring>
#include <cassert>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;

ULL dp[101][101];
char done[101][101];
int n, flag;

LL f(int i, int j)
{
	ULL &ret = dp[i][j];
	if(i > n or j > n or j > i)
		return ret = 0;
	if(n-i == 0 or n-j == 0)
		return ret = 1;
	if(done[i][j])
		return ret;
	done[i][j] = 1;
	ULL ans = f(i+1,j) + f(i,j+1);
	if(ans > 1000000000000000000LLU)
	{
		ans = 1000000000000000001LLU;
		done[i][j] = 2;
	}
	return ret = ans;
}

int main()
{
	int tt; scanf("%d",&tt);
	for(int t=1;t<=tt;t++)
	{
		printf("Case #%d: ",t);
		ULL k;
		scanf("%d %llu",&n,&k);
		memset(dp,0,sizeof(dp));
		memset(done,0,sizeof(done));
		flag = 0;
		f(0,0);
		dp[n][n] = 1;
		
		int i=0,j=0;
		if(k > dp[1][0] or flag)
		{
			printf("Doesn't Exist!\n");
			continue;
		}
		while(k>=0)
		{
			if(k == 1)
			{
				for(int a=0;a<n-i;a++)
					printf("(");
				for(int a=0;a<n-j;a++)
					printf(")");
				break;
			}

			if(k > dp[i+1][j] and done[i+1][j] != 2)
			{
				k -= dp[i+1][j];
				j++;
				printf(")");
			}
			else
			{
				i++;
				printf("(");
			}
		}
	}
	return 0;
}
