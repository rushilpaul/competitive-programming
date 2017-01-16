#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	int t; cin >> t;
	int ar[] = { 192,442,692,942 };
	while(t--)
	{
		LL k; cin >> k;
		k--;
		cout << k/4*1000 + ar[k%4] << endl;
	}
	return 0;
}
