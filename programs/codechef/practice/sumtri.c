//Program question at: http://www.codechef.com/problems/SUMTRIAN
#include <stdio.h>
int ar[100][100],n;
inline int max(int a, int b) { return a>b?a:b; }
int solve(int i, int j)
{
	if(i >= n || j >= n) return 0;
	if(ar[i][j] == -1) return 0;
	return max(ar[i][j], max(solve(i+1,j),solve(i+1,j+1)) );
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a,b; scanf("%d",&n);
		memset(ar,-1,40000);
		for(a=0;a<n;a++,printf("\n"))
			for(b=0;b<n;b++) printf("%d ",ar[a][b]);

		for(a=0;a<n;a++)
			for(b=0;b<n;b++) scanf("%d",&ar[a][b]);

		printf("%d\n",solve(0,0));
	}
}
