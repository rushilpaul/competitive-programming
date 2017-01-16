#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int tmp,n; cin >> n; tmp = n;
		int x = ceil((sqrt(1.0+8*n) - 1)/2.0);
		n = max(n - x*(x+1)/2, n - x*(x-1)/2);
		int ans = x % 2 ? x-n+1 : n;
		printf("TERM %d IS %d/%d\n",tmp,ans,x+1-ans);
	}
	return 0;
}
