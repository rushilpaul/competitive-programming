// Given a sorted array, find frequency of a number in O(log n) time
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++) scanf("%d",&ar[a]);
	int k; scanf("%d",&k);
	printf("Frequency of %d = %d\n",k,(lower_bound(ar,ar+n,k+1) - ar) - (lower_bound(ar,ar+n,k) - ar));
}
