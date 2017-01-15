#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int n;
int done[51][51], cost[51][51];

int find(int v)
{
	int flag = 0;
	for(int a=1;a<=n;a++)
		if(done[v][a] == 0)
		{
			flag = 1;
			break;
		}
	if(!flag)
		return -1;
	// check complete

	int maxcost = INT_MIN;
	int choice;
	for(int a=1;a<=n;a++)
	{
		if(done[v][a]) continue;
		done[v][a] = 1;
		int flag = 0;
		for(int b=1;b<=n;b++)
		{
			if(done[a][b]) continue;
			done[a][b] = 1;
			flag = 1;
			int flag2 = 0;
			for(int c=1;c<=n;c++)
			{
				if(done[b][c]) continue;
				flag2 = 1;
				if(cost[v][a] - cost[a][b] + cost[b][c] > maxcost)
				{
					maxcost = cost[v][a] - cost[a][b] + cost[b][c];
					choice = a;
				}
			}
			done[a][b] = 0;
			if(!flag2)
			{
				if(cost[v][a] - cost[a][b] > maxcost)
				{
					maxcost = cost[v][a] - cost[a][b];
					choice = a;
				}
			}
		}
		done[v][a] = 0;
		if(!flag)
		{
			if(cost[v][a] > maxcost)
			{
				maxcost = cost[v][a];
				choice = a;
			}
		}
	}
	return choice;
}

int bestnode, entry;

void init()
{
	int m=INT_MIN;
	for(int a=1;a<=n;a++)
	{
		int in = 0, out = 0;
		for(int b=1;b<=n;b++)
		{
			out += cost[a][b];
			in += cost[b][a];
		}
		if(in-out >= 0 and in-out > m)
		{
			m = in-out;
			bestnode = a;
		}
	}
	int outmax = 0;
	for(int a=1;a<=n;a++)
		outmax = max(outmax, cost[bestnode][a]);
	int smallest = outmax;
	for(int a=1;a<=n;a++)
	{
		if(a == bestnode) continue;
		if(cost[bestnode][a] < smallest)
		{
			smallest = cost[bestnode][a];
			entry = a;
			break;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		for(int b=1;b<=n;b++)
		{
			if(a == b)
				done[a][b] = 1;
			scanf("%d",&cost[a][b]);
		}
	}

	init();

	int m = INT_MIN, i,j;
	/*
	for(int a=1;a<=n;a++)
	{
		int c = find(a);
		if(cost[a][c] > m)
		{
			m = cost[a][c];
			i = a;
			j = c;
		}
	}
	*/
	i = entry;
	j = bestnode;
	int myscore=0, compscore=0;
	printf("%d %d\n",i,j);
	myscore += cost[i][j];
	fflush(stdout);
	done[i][j] = 1;
	while(1)
	{
		int u,v;
		int ret = scanf("%d %d",&u,&v);
		if(ret <= 0 or ret == EOF) break;
		assert(done[u][v] == 0);
		done[u][v] = 1;
		compscore += cost[u][v];
			
		//int c = find(v);
		int c = bestnode;
		if(done[v][c])
			c = find(v);
		if(c == -1)
			break;
		assert(done[v][c] == 0);
		done[v][c] = 1;
		myscore += cost[v][c];
		
		printf("%d %d\n",v,c);
		fflush(stdout);
	}
	//fprintf(stderr, "FS: %d\n", myscore - compscore);
	return 0;
}

