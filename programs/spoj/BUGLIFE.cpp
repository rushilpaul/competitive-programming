#include <bits/stdc++.h>
using namespace std;

vector<int> nodes[2000];
int visited[2000];

int main()
{
	int tt; scanf("%d",&tt);
	for(int t=1;t<=tt;t++)
	{
		int n,m; scanf("%d %d",&n,&m);
		memset(visited,0,sizeof(visited));
		for(int a=0;a<n;a++) nodes[a].clear();
		for(int a=0;a<m;a++)
		{
			int i,j; scanf("%d %d",&i,&j);
			i--; j--;
			nodes[i].push_back(j);
			nodes[j].push_back(i);
		}
		int flag = 1;
		for(int i=0;i<n and flag;i++)
		{
			if(visited[i]) continue;
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			while(q.size() and flag)
			{
				int u = q.front();
				q.pop();
				int size = nodes[u].size();
				for(int a=0;a<size;a++)
				{
					if(visited[nodes[u][a]] == visited[u])
					{
						flag = 0;
						break;
					}
					if(visited[nodes[u][a]] == 0)
					{
						visited[nodes[u][a]] = visited[u] == 1 ? 2 : 1;
						q.push(nodes[u][a]);
					}
				}
			}
		}
		printf("Scenario #%d:\n%s\n",t, flag ? "No suspicious bugs found!" : "Suspicious bugs found!");
	}
	return 0;
}

