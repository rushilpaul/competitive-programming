#include <cstdio>
using namespace std;

int **map, *num, n, con;

bool solve(int s, int e)
{ 
	for(int a=0;a<num[s];a++)
	{
		if(map[s][a] == e)
		{
			con++;
			if(con==2) return 1;
			continue;
		}
		if(solve(map[s][a],e)) return 1;
	}
	return 0;
}

int main()
{
	int tt; scanf("%d\n",&tt);
	for(int t=1;t<=tt;t++)
	{
		start: int fuck=0;
		scanf("%d",&n);
		map = new int*[n];
		num = new int[n];
		for(int a=0;a<n;a++)
		{
			scanf("%d",&num[a]);
			if(!num[a]) continue;
			map[a] = new int[num[a]];
			for(int b=0;b<num[a];b++)
				scanf("%d",&map[a][b]);
		}
		printf("Case #%d: ",t);
		for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
		{
			con=0;
			if(a!=b)
			{
			printf("%d %d -> ", a,b);
			if(solve(a,b)) { printf("Yes\n"); goto start; }
			printf("%d\n", con);
			}
		}
		printf("No\n");
	}
	return 0;
}
