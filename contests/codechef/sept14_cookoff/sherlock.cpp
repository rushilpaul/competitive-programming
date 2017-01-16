#include <cstdio>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d\n",&n);
		char s[1001];
		char grid[1000][1001];
		for(int a=0;a<n;a++)
		{
			gets(s);
			for(int b=0;b<n;b++) grid[a][b] = s[b];
		}
		for(int a=0;a<n;a++)
		{
			int flag = 0;
			for(int b=n-1;b>=0;b--)
			{
				if(grid[a][b] == '#') flag = 1;
				if(flag && grid[a][b] == '.') grid[a][b] = '!';
			}
		}
		for(int b=0;b<n;b++)
		{
			int flag = 0;
			for(int a=n-1;a>=0;a--)
			{
				if(grid[a][b] == '#') flag = 1;
				if(flag && grid[a][b] == '.') grid[a][b] = '!';
			}
		}
		int count=0;
		for(int a=0;a<n;a++)
		for(int b=0;b<n;b++) if(grid[a][b] == '.') count++;
		printf("%d\n",count);
	}
	return 0;
}