//Program question at: http://www.codechef.com/FEB12/problems/SMVSEVIL
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

inline char getdir(int s, int e);

int sx,sy,ex,ey,m,n,path_k,minlen;
char **maze;
char path[10001];
void print();

inline int check(int x, int y)
{
	if(x<0 || x>=m || y<0 || y>=n) return 0;
	char &ch = maze[x][y];
	if(ch == '#' || ch == 48) return 0;
	if(x == ex && y == ey) return 2;
	return 1;	// '.' case
}

void solve()
{
	int r = m+n, c = min(m,n)*2, a=0;
	int ar[r][c];
	memset(ar,-1,r*c*sizeof(int));
	maze[sx][sy] = 48;
	int nr = check(sx-1,sy), s = check(sx+1,sy), e = check(sx,sy+1), w = check(sx,sy-1);
	if(nr==2 || s==2 || e==2 || w==2) goto out;
	if(nr) { ar[0][a++] = (sx-1)*n + sy; maze[sx-1][sy]=48; }
	if(s) { ar[0][a++] = (sx+1)*n + sy; maze[sx+1][sy]=48; }
	if(e) { ar[0][a++] = sx*n + sy+1; maze[sx][sy+1]=48; }
	if(w) { ar[0][a++] = sx*n + sy-1; maze[sx][sy-1]=48; }
	for(a=1;a<r;a++)
		for(int b=0,k=0;b<c && ar[a-1][b] != -1; b++)
		{
			int x = ar[a-1][b]/n, y = ar[a-1][b]%n;
			nr = check(x-1,y); s = check(x+1,y); e = check(x,y+1); w = check(x,y-1);
			if(nr==2 || s==2 || e==2 || w==2) goto out;

			if(nr) { ar[a][k++] = (x-1)*n + y; maze[x-1][y]=48; }
			if(s) { ar[a][k++] = (x+1)*n + y; maze[x+1][y]=48; }
			if(e) { ar[a][k++] = x*n + y + 1; maze[x][y+1]=48; }
			if(w) { ar[a][k++] = x*n + y - 1; maze[x][y-1]=48; }
		}
	out:
	int cell = -1; minlen += a+1;
	for(int i=0;i<c;i++)
	{
		char d = getdir(ar[a-1][i], ex*n+ey);
		if(d != 1) { path[minlen-path_k++] = d; cell = ar[a-1][i]; break; }
	}
	for(a-=2;a>=0;a--)
		for(int b=0;b<c;b++)
		{
			char d = getdir(ar[a][b], cell);
			if(d != 1) { path[minlen-path_k++] = d; cell = ar[a][b]; break; }
		}
	path[minlen-path_k++] = getdir(sx*n+sy, cell);
	//printf("length: %d\n%s\n",minlen,path);
}

inline char getdir(int s, int e)
{
	int x1 = s/n, x2 = e/n, y1 = s%n, y2 = e%n;
	if(x1 == x2) { if(y1-y2 == 1) return 'W'; else if(y1-y2 == -1) return 'E'; }
	if(y1 == y2) { if(x1-x2 == 1) return 'N'; else if(x1-x2 == -1) return 'S'; }
	return 1;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int nmaze; scanf("%d",&nmaze);
		minlen = -1;
		for(int i=0;i<nmaze;i++)
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
					else if(ch == 'E') { ex = a; ey = b; }
					maze[a][b] = ch;
				}
			} // input done
			path_k=0;
			if(!i) solve();
			else
			{
				for(int a=0;a<=minlen;a++)
				{
					char &p = path[a]; int r;
					if(p == 'N')
					{
						r = check(sx-1,sy);
						if(r) sx--;
					}
					else if(p == 'S')
					{
						r = check(sx+1,sy);
						if(r) sx++;
					}
					else if(p == 'E')
					{
						r = check(sx,sy+1);
						if(r) sy++;
					}
					else if(p == 'W')
					{
						r = check(sx,sy-1);
						if(r) sy--;
					}
				}
				if(i) solve();
			}
		}	// all mazes done
		path[minlen+1] = '\0';
		printf("%s\n",path);
	}
	return 0;
}
