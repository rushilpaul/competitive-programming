#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int f(vector<int> v)
{
	int n = v.size();
	if(n == 0) return 0;
	int w = 1;
	for(int a=0;a<n;a++)
	{
		vector<int> v2;
		for(int b=0;b<n;b++)
			if(v[a] % v[b])
				v2.push_back(v[b]);
		w &= f(v2);
	}
	return !w;
}

int main()
{
	int n; cin >> n;
	vector<int> ar(n);
	for(int a=0;a<n;a++) ar[a] = a+1;
	printf("%d\n",f(ar));
}
