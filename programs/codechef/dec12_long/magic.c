//Program question at: http://www.codechef.com/DEC12/problems/MGCRNK
#include <stdio.h>
#define max(a,b) (a>b?a:b)
#define FOR(i,n) for(i=0;i<n;i++)
#define MAX 100
#define MIN -300000
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
int ar[MAX][MAX],cache[MAX][MAX],n;

int solve(int i, int j)
{
	if(i >= n || j >= n) return MIN;
	int p,q; p=q=3000;
	if(i+1 < n) p = cache[i+1][j];
	if(j+1 < n) q = cache[i][j+1];
	if(p == 3000) p = solve(i+1,j);
	if(q == 3000) q = solve(i,j+1);
	if(p == MIN && q == MIN) p=0;
	return cache[i][j] = max(p,q) + ar[i][j];
}

int main()
{
	int i,j,t=in();
	while(t--)
	{
		n = in();
		FOR(i,n) FOR(j,n) { ar[i][j] = in(); cache[i][j] = 3000; }
		i = solve(0,0);
		if(i<0) printf("Bad Judges\n");
		else printf("%f\n",i/(2*n-3.0));
	}
	return 0;
}
