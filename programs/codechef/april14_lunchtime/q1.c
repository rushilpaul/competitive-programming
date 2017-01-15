#include <stdio.h>
int abs(int x) { x<0?-x:x; }
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,b,m,n; scanf("%d %d",&n,&m);
		int board[n][n];
		for(a=0;a<n;a++) for(b=0;b<n;b++) board[a][b] = 0;
		int ar[m][2],ans=0;
		for(a=0;a<m;a++) 
		{
			scanf("%d %d",&ar[a][0],&ar[a][1]);
			board[ar[a][0]-1][ar[a][1]-1] = -1;
		}
		
		for(a=0;a<m;a++)
		{
			int x = ar[a][0], y = ar[a][1];
			x--; y--;
			if(x+1 < n && y+2 < n && board[x+1][y+2] != -1) board[x+1][y+2]++;
			if(x+1 < n && y-2 >= 0 && board[x+1][y-2] != -1) board[x+1][y-2]++;
			if(x-1 >= 0 && y+2 < n && board[x-1][y+2] != -1) board[x-1][y+2]++;
			if(x-1 >= 0 && y-2 >= 0 && board[x-1][y-2] != -1) board[x-1][y-2]++;
			if(x+2 < n && y+1 < n && board[x+2][y+1] != -1) board[x+2][y+1]++;
			if(x+2 < n && y-1 >= 0 && board[x+2][y-1] != -1) board[x+2][y-1]++;
			if(x-2 >= 0 && y+1 < n && board[x-2][y+1] != -1) board[x-2][y+1]++;
			if(x-2 >= 0 && y-1 >= 0 && board[x-2][y-1] != -1) board[x-2][y-1]++;
		}
		int c;
		for(a=0;a<n;a++)
		for(b=0;b<n;b++)
			if(board[a][b] >= 2)
			{
				for(c=0;c<m;c++)
					if(ar[c][0]-1 == a || ar[c][1]-1 == b || (abs(ar[c][0]-1-a) == abs(ar[c][1]-1-b))) break;
				if(c != m) continue;
				ans++;
			}
		printf("%d\n",ans);
	}
}
