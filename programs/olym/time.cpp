#include <cstdio>
#include <cstring>
using namespace std;

int **time,n;
bool *done;

int solve(int end);

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		time = new int*[n];
		done = new bool[n];
		memset(done,0,n*sizeof(bool));
		for(int a=0;a<n;a++) { time[a] = new int[2]; scanf("%d %d",&time[a][0],&time[a][1]); }
		int max=0;
		for(int a=0;a<n;a++)
		{
			done[a] = 1;
			int r = solve(time[a][1])+1;
			done[a] = 0;
			if(r > max) max = r;
		}
		printf("%d\n",max);
	}
	return 0;
}

int solve(int end)
{
	int max=0;
	for(int a=0;a<n;a++)
	{
		if(done[a]) continue;
		if(time[a][0] >= end)
		{
			done[a] = 1;
			int r = solve(time[a][1])+1;
			done[a] = 0;
			if(r > max) max = r;
		}
	}
	return max;
}
