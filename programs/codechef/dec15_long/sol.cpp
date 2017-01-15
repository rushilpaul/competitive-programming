#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MAX 21
int n,m,ans;
int s;
int ar[MAX][MAX], dp[MAX][MAX][MAX][MAX][MAX][MAX][2];
int best[MAX][MAX];

int f(int i, int j, int Z, int L, int R, int B, int shape)
{
	if(Z < 0 or L < 0 or R < 0 or B < 0) return -1;
	if(i == n)
	{
		int cur = s - (Z + L + R + B);
		if(cur > ans)
		{
			ans = cur;
			memcpy(best,ar,sizeof(ar));
		}
		return cur;
	}
	if(j == m) return -1;
	
	int ans = -1;
	int &ret = dp[i][j][Z][L][R][B][shape];
	if(ret >= 0) return ret;

	if(j == 0)
	{
		ar[i][0] = '-';
		ans = f(i,j+1,Z,L,R,B,0);

		ar[i][0] = 'L';
		ans = max(ans,f(i,j+1,Z,L-1,R,B,0));

		ar[i][0] = 'R';
		ans = max(ans, f(i,j+1,Z,L,R-1,B,1));

		ar[i][0] = 'B';
		ans = max(ans, f(i,j+1,Z,L,R,B-1,1));

		ar[i][0] = 'Z';
		ans = max(ans, f(i,j+1,Z-1,L,R,B,0));
		return ret = ans;
	}
	int flag = !(ar[i][j-1] == 'B' or ar[i][j-1] == 'R');

	ar[i][j] = '-';
	ans = f((j == m-1 ? i+1:i), (j == m-1 ? 0:j+1), Z,L,R,B,0);

	ar[i][j] = 'Z';
	ans = max(ans, f((j == m-1 ? i+1:i), (j == m-1 ? 0:j+1),  Z-1,L,R,B,0));

	ar[i][j] = 'R';
	ans = max(ans, f((j == m-1 ? i+1:i), (j == m-1 ? 0:j+1), Z,L,R-1,B,1));

	if(flag)
	{
		ar[i][j] = 'L';
		ans = max(ans, f((j == m-1 ? i+1:i), (j == m-1 ? 0:j+1), Z,L-1,R,B,0));
		ar[i][j] = 'B';
		ans = max(ans, f((j == m-1 ? i+1:i), (j == m-1 ? 0:j+1), Z,L,R,B-1,1));
	}
	return ret = ans;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		int Z,L,R,B;
		cin >> n >> m >> Z >> L >> R >> B;
		s = Z + L + R + B;
		for(int a=0;a<n;a++) for(int b=0;b<m;b++) ar[a][b] = '-';
		ans = -1;
		ans = f(0,0,Z,L,R,B,0);
		//for(int a=0;a<n;a++,printf("\n")) for(int b=0;b<m;b++) printf("%c ",best[a][b]);
		cout << ans << endl;
	}
	return 0;
}

