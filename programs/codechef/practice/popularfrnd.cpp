//Program question at: http://www.codechef.com/problems/LOKBIL
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

typedef vector<int> VI;
bool path[100];

int find(VI *ar, int **cache, int start, int end)
{
	if(start == end) return 0;
	int &c = cache[start][end];
	if(c) return c;
	path[start] = 1;
	int m = 100;
	for(VI::iterator i=ar[start].begin();i!=ar[start].end();i++)
	{
		if(path[*i]) continue;
		m = min(m, find(ar, cache, *i, end)+1 );
		if(*i != end)
		cache[*i][end] = cache[end][*i] = m;
	}
	path[start] = 0;
	return m;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		VI ar[n];
		int **cache = new int*[n];
		for(int a=0;a<n;a++)
		{
			path[a] = 0;
			cache[a] = new int[n];
			for(int j=0;j<n;j++) cache[a][j] = 0;
			char s[256], *tok;
			gets(s);
			tok = strtok(s," ");
			while(tok)
				{
					int f = atoi(tok)-1;
					cache[a][f] = cache[f][a] = 1;
					ar[a].push_back(f);
					tok = strtok(NULL," ");
				}
		}
			
		int ans=10000, popular=-1;
		for(int i=0;i<n;i++)
		{
			int t=0;
			for(int j=0;j<n;j++)
			{
				if(j<=i) { t += cache[i][j]; continue; }
				cache[i][j] = cache[j][i] = find(ar, cache, i, j);
				t += cache[i][j];
			}
			if(t != 0)
			if(t < ans) { ans = t; popular = i; }
		}
		printf("%d %.6f\n", popular+1, ans*1.0/n);
	}
	return 0;
}

