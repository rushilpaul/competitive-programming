#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define pb push_back

#define MAX 100001
int G[MAX], F[MAX];
int times1[MAX], times2[MAX];
int vis[MAX], intime, max_len;

void dfs(int u)
{
	if(vis[u])
	{
		max_len = max(max_len, intime - vis[u]);
		return;
	}
	vis[u] = intime++;
	if(G[u] != -1)
		dfs(G[u]);
}

void dfs2(int u, int *times)
{
	if(times[u] != -1) return;
	times[u] = intime++;
	if(G[u] != -1)
		dfs2(G[u], times);
}

int main()
{
	int n; scanf("%d",&n);
	for(int a=0;a<n;a++)
	{
		int u; scanf("%d",&u);
		G[a] = u;
	}
	for(int a=0;a<n;a++)
	{
		if(G[a] != -1 and !vis[a])
		{
			intime = 1;
			dfs(a);
		}
	}
	printf("%d\n",max_len);

	// 2nd part
	for(int a=0;a<n;a++)
		if(G[a] != -1) F[G[a]]++;

	int max_in = 0;
	for(int a=0;a<n;a++)
		max_in = max(max_in, F[a]);
		
	printf("%d\n",max_in);
	
	// 3rd part
	int u,v; scanf("%d %d",&u,&v);

	fill(times1, times1+n, -1);
	fill(times2, times2+n, -1);
	
	intime = 0;
	dfs2(u,times1);
	intime = 0;
	dfs2(v,times2);
	int best_node = -1, min_dist = INT_MAX;

	for(int a=0;a<n;a++)
	{
		if(times1[a] != -1 and times2[a] != -1 and times1[a] + times2[a] < min_dist)
		{
			min_dist = times1[a] + times2[a];
			best_node = a;
		}
	}
	printf("%d\n",best_node);

	return 0;
}

