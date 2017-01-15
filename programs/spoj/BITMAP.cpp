#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m; scanf("%d %d\n",&n,&m);
		char ar[n][m+1];
		for(int a=0;a<n;a++)
			scanf("%s",ar[a]);
		
		queue< pair<int,int> > q;
		int ans[n][m];
		
		for(int a=0;a<n;a++)
			for(int b=0;b<m;b++)
			{
				ans[a][b] = 100000;
				if(ar[a][b] == '1')
				{
					q.push(make_pair(a,b));
					ans[a][b] = 0;
				}
			}

		while(q.size())
		{
			int x = q.front().first, y = q.front().second;
			int cur = ans[x][y];

			if(x-1 >= 0 and ans[x-1][y] == 100000)
			{
				ans[x-1][y] = min(ans[x-1][y], cur+1);
				q.push(make_pair(x-1,y));
			}
			if(x+1 < n and ans[x+1][y] == 100000)
			{
				ans[x+1][y] = min(ans[x+1][y], cur+1);
				q.push(make_pair(x+1,y));
			}
			if(y-1 >= 0 and ans[x][y-1] == 100000)
			{
				ans[x][y-1] = min(ans[x][y-1], cur+1);
				q.push(make_pair(x,y-1));
			}
			if(y+1 < m and ans[x][y+1] == 100000)
			{
				ans[x][y+1] = min(ans[x][y+1], cur+1);
				q.push(make_pair(x,y+1));
			}
			q.pop();
		}
		for(int a=0;a<n;a++,printf("\n"))
			for(int b=0;b<m;b++) printf("%d ",ans[a][b]);
	}
	return 0;
}
