#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/*
a*b <= n
*/

int main()
{
	int n; cin >> n;
	int ans=0;
	for(int a=1;a<=n;a++)
		for(int b=a;b<=n;b++)
		{
			if(a*b > n) break;
			ans++;
		}
	cout << ans << endl;
	return 0;
}
