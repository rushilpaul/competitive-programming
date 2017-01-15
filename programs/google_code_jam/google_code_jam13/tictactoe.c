#include <stdio.h>
char ar[4][4];

int forward(int x, int y)
{
	if(y > 0) return 0;
	int a=0; char ch = ar[x][y];
	while(ch == 'T' && y < 4) ch = ar[x][++y];
	if(ch == 'T' || ch == '.') return 0;
	for(;a<4;a++)
		if(ar[x][a] != ch && ar[x][a] != 'T') return 0;
	return 1;
}

int down(int x, int y)
{
	if(x > 0) return 0;
	int a=0; char ch = ar[x][y];
	while(ch == 'T' && x < 4) ch = ar[++x][y];
	if(ch == 'T' || ch == '.') return 0;
	for(;a<4;a++) if(ar[a][y] != ch && ar[a][y] != 'T') return 0;
	return 2;
}

int diag1(int x, int y)
{
	if(x > 0 || y > 0) return 0;
	int a=0; char ch = ar[x][y];
	while(ch == 'T' && x < 4) ch = ar[++x][++y];
	if(ch == 'T' || ch == '.') return 0;
	for(;a<4 && x+a < 4 && y+a < 4;a++) if(ar[x+a][y+a] != ch && ar[x+a][y+a] != 'T') return 0;
	return 4;
}

int diag2(int x, int y)
{
	if(x > 0 || y < 3) return 0;
	int a=0; char ch = ar[x][y];
	while(ch == 'T' && x < 4 && y >= 0) ch = ar[++x][--y];
	if(ch == 'T' || ch == '.') return 0;
	for(a=0;a<4 && x+a < 4 && y-a >= 0;a++)
		if(ar[x+a][y-a] != ch && ar[x+a][y-a] != 'T') return 0;
	return 8;
}

char find(int r, int x, int y)
{
	int a;
	for(a=0;a<4;a++)
	{
		if(r & 1 && y+a < 4 && ar[x][y+a] != 'T') return ar[x][y+a];
		if(r & 2 && x+a < 4 && ar[x+a][y] != 'T') return ar[x+a][y];
		if(r & 4 && x+a < 4 && y+a < 4 && ar[x+a][y+a] != 'T') return ar[x+a][y+a];
		if(r & 8 && x+a < 4 && y-a >= 0 && ar[x+a][y-a] != 'T') return ar[x+a][y-a];
	}
	return 'z';
}

int main()
{
	int tc,t,a,b,comp;
	char ch;
	scanf("%d\n",&tc);
	for(t=1;t<=tc;t++)
	{
		comp = 1;
		for(a=0;a<4;a++) gets(ar[a]);
		for(a=0;a<4;a++)
		for(b=0;b<4;b++)
		{
			if(ar[a][b] == '.') { comp = 0; continue; }
			int r = forward(a,b) | down(a,b) | diag1(a,b) | diag2(a,b);
			if(r > 0 && (ch = find(r,a,b)) != 'z')
			{
				printf("Case #%d: %c won\n",t,ch);
				goto end;
			}
		}
		if(comp) printf("Case #%d: Draw\n",t);
		else printf("Case #%d: Game has not completed\n",t);
		end:;
		gets(ar[0]);	// a blank line
	}
}
