#include <stdio.h>
#include <string.h>
typedef long long int LL;
int R,C, **done, **usafe, block;
LL **grid, **memo;
LL solve(int r, int c)
{
	if(r == R-1 && c == C-1) return 0;
	int isR=0, isD=0;
	if(usafe[r][c]) { block=1; return 0; }
	if(done[r][c]) return memo[r][c];
	LL res = grid[r][c],a=0,b=0;
	if (r+1 < R) a = solve(r+1,c);
	else isD = 1;
		if(block) { isD=1; block=0; }
	if (c+1 < C) b = solve(r,c+1);
	else isR = 1;
		if(block) { isR=1; block=0; }
	if(isD && isR) { usafe[r][c] = 1; block=1; return 0; }
	if(isD) res += b;
	else if(isR) res += a;
	else res += (a>b?a:b);
	done[r][c] = 1;
	return memo[r][c] = res;
}

int main()
{
	scanf("%d,%d\n",&R,&C);
	if(!R || !C) { printf("0\n"); return 0; }
	LL add[R][C];
	memset(add,0,R*C*sizeof(LL));
	int r,c,dr,dc; block = 0;
	grid = (LL**)malloc(R*sizeof(LL*));
	memo = (LL**)malloc(R*sizeof(LL*));
	done = (int**)malloc(R*sizeof(int*));
	usafe = (int**)malloc(R*sizeof(int*));
    for (r=0;r<R;r++)
	{
		grid[r] = (LL*)malloc(C*sizeof(LL));
		memo[r] = (LL*)malloc(C*sizeof(LL));
		done[r] = (int*)malloc(C*sizeof(int));
		usafe[r] = (int*)malloc(C*sizeof(int));
        for(c=0;c<C;c++)
		{
			if(c == C-1)
				scanf("%lld",&grid[r][c]);
			else
				scanf("%lld,",&grid[r][c]);
            if (grid[r][c] < 0)
			{
				usafe[r][c] = 1;
                for (dr = -1;dr<=1;dr++)
				for (dc = -1;dc<=1;dc++)
					if ((dr || dc) && r+dr >= 0 && r+dr < R && c+dc >= 0 && c+dc < C && !(r+dr==0 && c+dc==0) && !(r+dr==R-1 && c+dc==C-1)) add[r+dr][c+dc] += grid[r][c];
            }
			else usafe[r][c] = 0;
			done[r][c] = memo[r][c] = 0;
		}
	}
	for(r=0;r<R;r++)
	for (c=0;c<C;c++)
		grid[r][c] += add[r][c];
    printf("%lld\n",solve(0,0));
	return 0;
}
