#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define PI 3.141592653589793238462643383279502884197

vector<string> split(string S, string D)
{
	vector<string> ar;
	int pos = 0, last = 0;
	while( (pos = S.find(D,last)) != string::npos)
	{
		string sub = S.substr(last,pos-last);
		if(sub.length() > 0)
			ar.push_back(sub);
		last = pos + D.length();
	}
	string sub = S.substr(last);
	if(sub.length() > 0)
		ar.push_back(sub);
	return ar;
}

char s[50][50];
int n,m;
int vis[50][50];

set< pair<int,int> > pos;

int check(int i, int j) { return i >= 0 and j >= 0 and i < n and j < m and s[i][j] != '@' and s[i][j] != '#'; }

void fill(int i, int j, int previ, int prevj)
{
	if(!check(i,j) or vis[i][j]) return;
	if(s[i][j] != '+' and s[i][j] != '*') { pos.insert({i,j}); return; }

	vis[i][j] = 1;
	fill(i,j+1, i,j);
	fill(i,j-1, i,j);
	fill(i+1,j, i,j);
	fill(i-1,j, i,j);
}

int reach(int i, int j)
{
	if(!check(i,j) or vis[i][j]) return 0;
	vis[i][j] = 1;
	if(s[i][j] == 'o') return 1;
	return reach(i,j+1) or reach(i,j-1) or reach(i+1,j) or reach(i-1,j);
}

char backup[50][50];

int main()
{
	cin >> n >> m;
	rep(a,n) { cin >> s[a]; strcpy(backup[a],s[a]); }

	int sx,sy;
	rep(a,n)
		rep(b,m)
			if(s[a][b] == '*') sx = a, sy = b;
	
	fill(sx,sy,sx,sy);
	for(auto e : pos)
		s[e.first][e.second] = '@';
	
	//rep(a,n) printf("%s\n",s[a]);

	int ans = pos.size();
	for(auto e : pos)
	{
		memset(vis,0,sizeof(vis));
		int i = e.first, j = e.second;
		s[i][j] = backup[i][j];
		if(!reach(i,j))
			ans--;
		else
			s[i][j] = '@';
	}
	cout << ans << endl;
	return 0;
}

