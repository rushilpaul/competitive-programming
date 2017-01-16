#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;

#define EPS (std::numeric_limits<double>::epsilon())
#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define sq(a) ((a)*(a))
#define PI 3.141592653589793238462643383279502884197

inline LL gcd(LL a, LL b)
{
	while(b)
	{
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		LL a,b; scanf("%lld %lld",&a,&b);
		LL g = gcd(a,b);
		a /= g;
		b /= g;
		printf("%lld %lld\n",b,a);
	}
	return 0;
}
