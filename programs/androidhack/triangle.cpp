#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int solve(int** ar, int row, int col)
{
	if(row >= n || col > row) return -1;
	int s=ar[row][col];
	int d = max(solve(ar,row+1,col), solve(ar,row+1,col+1) );
	if(d != -1) s += d;
	return s;
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		scanf("%d\n",&n);
		int **ar = new int*[n];
		for(int a=0;a<n;a++)
		{
			ar[a] = new int[n];
			for(int b=0;b<=a;b++) scanf("%d",&ar[a][b]);
			for(int b=a+1;b<n;b++) ar[a][b]=-1;
		}
		printf("%d\n",solve(ar,0,0));
	}
	return 0;
}
