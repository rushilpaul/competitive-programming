#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back

LL dp[50][50];
string s;

LL f(int i, int j)
{
	LL &ret = dp[i][j];
	if(j-i+1 <= 1) return ret = 0;
	if(ret >= 0) return ret;
	if((s[i] == '(' and s[j] == ')') or (s[i] == '[' and s[j] == ']'))
	{
		ret = 1;
		repab(a,i+1,j-2)
			repab(b,a+1,j-1)
				ret += f(a,b);
	}
	else
		ret = 0;
	return ret;
}

class BracketSequenceDiv1
{
	public:	
		long long count(string s)
		{
			memset(dp,-1,sizeof(dp));
			::s = s;
			int n = s.length();
			LL ans = 0;
			rep(i,n-1)
				repab(j,i+1,n-1)
					ans += f(i,j);
			return ans;
		}
};

