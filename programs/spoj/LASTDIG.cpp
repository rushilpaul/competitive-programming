#include <bits/stdc++.h>
using namespace std;

int pow(int b, int e)
{
	if(e == 0) return 1;
	int ans = pow(b,e/2) % 10;
	ans = ans * ans % 10;
	if(e&1)
		ans *= b;
	return ans % 10;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int a,b; cin >> a >> b;
		printf("%d\n",pow(a,b));
	}
	return 0;
}
