#include <stdio.h>
#include <string.h>
#define max 10000000
int route[10000][2], time[10000],n,done[10000],cache[1000][1000],init;

void solve(int u, int v, int w)
{
	int a, left;
	for(a=0;a<n;a++)
	{
		if(done[a]) continue;
		left = 0;
		if(route[a][0] == u) left = 1;
		else if(route[a][1] == u) left = 2;
		if(!left) continue;

		if( (v == route[a][1] && left == 1) || (v == route[a][0] && left == 2) )
		{			
			if(cache[init][v] > w+time[a]) cache[init][v] = w+time[a];
			continue;
		}
		done[a] = 1;
		if(left == 1)
			solve(route[a][1],v,w+time[a]);
		else
			solve(route[a][0],v,w+time[a]);
		done[a] = 0;
	}
}

int main()
{
	int a,b,q;
	scanf("%d",&n);
	for(a=0;a<n;a++) scanf("%d %d %d",&route[a][0],&route[a][1],&time[a]);
	memset(done,0,sizeof(int)*10000);
	for(a=0;a<1000;a++) for(b=0;b<1000;b++) cache[a][b] = max;

	for(a=0;a<n-1;a++)
	for(b=a+1;b<n;b++)
	{
		init = a;
		solve(a,b,0);
	}

	scanf("%d",&q);
	int u,v;
	while(q--)
	{
		scanf("%d %d",&u,&v);
		printf("%d\n",cache[u][v]);
	}

	return 0;
}
