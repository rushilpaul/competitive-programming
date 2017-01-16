// given an array, rotate a subarray by k towards right
#include <cstdio>

void f(int *ar, int n, int k)
{
	int tmp[k];
	for(int a=0;a<k;a++)
		tmp[a] = ar[a];
	for(int a=k;a<n;a++)
		ar[a-k] = ar[a];
	for(int a=0;a<k;a++)
		ar[a+n-k] = tmp[a];
}

int main()
{
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++) scanf("%d",ar+a);
	int start,end,k; scanf("%d %d %d",&start,&end,&k);
	start--; end--;
	f(ar+start,end-start+1,k);
	for(int a=0;a<n;a++)
		printf("%d ",ar[a]);
}
