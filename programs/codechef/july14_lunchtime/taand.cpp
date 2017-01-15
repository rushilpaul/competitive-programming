#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n; scanf("%d",&n);
	vector<int> ar(n);
	for(int a=0;a<n;a++) scanf("%d",&ar[a]);
	sort(ar.begin(),ar.end());
	int m=0;
	for(int a=n-1;a>=1;a--)
		m = max(m,ar[a] & ar[a-1]);
	printf("%d\n",m);
	return 0;
}