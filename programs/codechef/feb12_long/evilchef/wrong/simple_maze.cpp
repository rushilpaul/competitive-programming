//Program question at: http://www.codechef.com/FEB12/problems/SMVSEVIL
#include <cstdio>
#include <iostream>
using namespace std;

int sx,sy,ex,ey,m,n;
char **maze;
char path[10001];
void print();

bool check(int x, int y)
{
	if(x<0 || x>=m || y<0 || y>=n) return 0;
	char &ch = maze[x][y];
	if(ch == '#' || isdigit(ch)) return 0;
	if(ch == '.' || (x == ex && y == ey)) return 1;	// valid
	return 0;
}

bool solve(int x, int y)
{
	if(check(x,y)==1) return 0;
	char &mem = maze[x][y], ch = mem;
	if(ch == 'E') return 1;
	mem = '*';
	if(solve(x-1,y)) return 1;
	if(solve(x+1,y)) return 1;
	if(solve(x,y-1)) return 1;
	if(solve(x,y+1)) return 1;
	mem = ch;
	return 0;
}

int k=0;
bool solve2(int x, int y, int num)
{
	if(x == ex && y == ey) return 1;
	int n = check(x-1,y), s = check(x+1,y), e = check(x,y+1), w = check(x,y-1);
	if(n) maze[x-1][y] = num;
	if(s) maze[x+1][y] = num;
	if(e) maze[x][y+1] = num;
	if(w) maze[x][y-1] = num;

	if(n)
	if(solve2(x-1,y,num+1)) { path[num-1] = 'N'; k++; return 1; }
	if(s)
	if(solve2(x+1,y,num+1)) { path[num-1] = 'S'; k++; return 1; }
	if(e)
	if(solve2(x,y+1,num+1)) { path[num-1] = 'E'; k++; return 1; }
	if(w)
	if(solve2(x,y-1,num+1)) { path[num-1] = 'W'; k++; return 1; }
	return 0;
}

void print()
{
	for(int a=0;a<m;a++,printf("\n"))
		for(int b=0;b<n;b++) printf("%c",maze[a][b]);
	printf("\n");
}

int main()
{
	scanf("%d %d",&m,&n);
	maze = new char*[m];
	for(int a=0;a<m;a++)
	{
		maze[a] = new char[n];
		for(int b=0;b<n;b++)
		{
			char ch; cin >> ch;
			if(ch == 'S') { sx = a; sy = b; }
			if(ch == 'E') { ex = a; ey = b; }
			maze[a][b] = ch;
		}
	}
	printf("\n");
	if(solve2(sx,sy,1)) { maze[sx][sy] = 'S'; maze[ex][ey] = 'E';
	for(int a=0;a<m;a++)
	{
		for(int b=0;b<n;b++) printf("%c",maze[a][b] < 10 ? maze[a][b]+48 : maze[a][b]);
		printf("\n");
	} }
	for(int a=0;a<k;a++) printf("%c ",path[a]);
	return 0;
}
