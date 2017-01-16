#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int A[n], B[n];
		for(int a=0;a<n;a++) cin >> A[a];
		for(int b=0;b<n;b++) cin >> B[b];
		sort(A,A+n,greater<int>());
		sort(B,B+n,greater<int>());
		int ans=0;
		for(int a=0;a<n;a++)
			ans += A[a] * B[a];
		printf("%d\n",ans);
	}
	return 0;
}
