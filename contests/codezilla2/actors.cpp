#include <cstdio>
using namespace std;

void sort(int arr[], int left, int right)
{
	int i = left, j = right, tmp;
	int pivot = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i] > pivot) i++;

		while (arr[j] < pivot) j--;

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
if (left < j)
	sort(arr, left, j);

if (i < right)
	sort(arr, i, right);
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int C,N; scanf("%d %d", &C, &N);
		int ar[C][7];
		for(int a=0;a<C;a++) for(int b=0;b<7;b++) scanf("%d",&ar[a][b]);
		int actor[N], max=0;
		for(int a=0;a<N;a++) scanf("%d",&actor[a]);
		sort(actor,0,N-1);
		for(int a=0;a<C;a++)
		for(int ac=0;ac<N;ac++)
			for(int b=0;b<7;b++)
			{
				if(ar[a][b] >= actor[ac]) { max += actor[ac]; ar[a][b] -= actor[ac]; }
			}

		printf("%d\n",max);
	}
	return 0;
}
