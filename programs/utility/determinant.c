#include <stdio.h>
#include <stdlib.h>

int solve(int **M, int n)
{
	if(n == 2) return M[0][0]*M[1][1] - M[0][1]*M[1][0];
	else if(n == 1) return M[0][0];
	int a,b,c,D=0,k;
	int **ar = (int**)malloc(sizeof(int*)*(n-1));
	for(k=0;k<n-1;k++) ar[k] = (int*)malloc(sizeof(int)*(n-1));
	for(a=0;a<n;a++)
	{
		k=0;
		for(b=0;b<n;b++)
		{
			if(b == a) b++;
			for(c=1;c<n;c++) ar[c-1][k] = M[c][b];
			k++;
		}
		D += (solve(ar,n-1) * (a&1 ? -1:1) * M[0][a]);		
	}
	return D;
}

int main()
{
	int a,b,n; scanf("%d",&n);
	int **ar = (int**)malloc(sizeof(int*)*n);
	for(a=0;a<n;a++)
	{
		ar[a] = (int*)malloc(sizeof(int)*n);
		for(b=0;b<n;b++) scanf("%d",&ar[a][b]);
	}
	printf("%d\n",solve(ar,n));
}
