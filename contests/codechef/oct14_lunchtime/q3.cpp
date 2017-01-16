#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

void read(int &n) { scanf("%d",&n); }
void read(LL &n) { scanf("%lld",&n); }
void read(double &n) { scanf("%f",&n); }
void read(long double &n) { scanf("%lf",&n); }

int main()
{
	int t; read(t);
	while(t--)
	{
		int n,f; read(n); read(f);
		map<int,int> m;
		int ar[n];
		for(int a=0;a<n;a++) { read(ar[a]); m[ar[a]] = m[ar[a]]+1; }
		sort(ar,ar+n);
		LL ans=0;
		for(int a=n-1;a>=0;a--)
		{
			int num = ar[a];
			int c = m[ar[a]];
			if(ar[a] != ar[a+1] || a==n-1)
				ans += (LL)c*(c-1)/2;
			while(num % f == 0)
			{
				num /= f;
				ans += m[num];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

