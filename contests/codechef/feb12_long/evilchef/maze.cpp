#include <iostream>
#include <cstdio>
using namespace std;

int k,m,n,index;
char ***maze;
bool *maze_path;
int **D, **start, **end;
char path[10001];

bool check(int x, int y)
{
	if( x<0 || y<0) return 0;
	int n=0;
	for(int a=0;a<k;a++)
	{
		maze_path[a] = 0;
		if(x >= D[a][0] || y >= D[a][1]) { n++; continue; }
		char &ch = maze[a][x][y];
		if(ch == '#' || ch == '*') { n++; continue; }
		maze_path[a] = 1;
	}
	return n!=k;
}

bool solve(int x, int y)
{
	if(check(x,y)) return 0;
	path[index++] = 'N';
	for(int 
	if(maze_path	
	if(solve(x+1,y)) return 1;
	index--;

	path[index++] = '
	

}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> k;
		D = new int*[k];
		maze = new char**[k];
		maze_path = new int[k];
		for(int a=0;a<k;a++)
		{
			//scanf("%d %d",&m,&n);
			cin >> m >> n;
			D[a] = new int[2];
			D[a][0] = m; D[a][1] = n;
			maze[a] = new char*[m];
			for(int b=0;b<m;b++)
			{
				maze[a][b] = new char[n];
				for(int c=0;c<n;c++)
				{
					char ch = maze[a][b][c];
					if(ch == 'S') { start[a][0] = b; start[a][1] = c; }
					if(ch == 'E') { end[a][0] = b; end[a][1] = c; }
					cin >> maze[a][b][c];
				}
			}
		}
		solve(start[0][0], start[0][1]);
	}
	return 0;
}
