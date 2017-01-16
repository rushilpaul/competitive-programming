#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t; scanf("%d",&t);
	while(t-- > 0)
	{
		ll n,m,Z,L,R,B; scanf("%lld %lld %lld %lld %lld %lld",&n,&m,&Z,&L,&R,&B);
		ll total = n*m;
		if(m == 1)
		{
			printf("%lld\n",min(n,L+R+Z+B));
			continue;
		}
		if(L + R + Z >= n*m or (B >= n and L + R + Z >= n*(m-1)))
		{
			printf("%lld\n",total);
			continue;
		}
		if(B <= n)
		{
			total -= B;
			total -= min(total, L + R + Z);
			printf("%lld\n",n*m - total);
			continue;
		}
		ll x = L + R;
		ll b = (x+m-2)/(m-1);
		total -= x + b;
		B -= b;
		ll remain = n-b;
		b = min(B, ((x + b) % m == 0 ? 0 : (m - (x+b) % m)) / 2 + (m+1)/2 * remain );
		//printf("b = %lld\n",b);
		B -= b;
		total -= b;
		if(B == 0)
		{
			total -= min(total,Z);
			printf("%lld\n",n*m - total);
			continue;
		}
		if(m % 2)
		{
			total -= min(total,Z);
			printf("%lld\n",n*m - total);
			continue;
		}
		ll y = remain;
		b = (x+m-2)/(m-1);
		if((x+b) % m > 0 and (m - (x+b) % m) % 2 == 1)
			y++;
		y = min(y, L+R);
		//printf("y = %lld\n",y);
		ll lines = x / (m-1);
		ll pairs = (m-1)/2 * lines + ((x+b) % m - 1) / 2;

		total -= min(B,min(y/2, pairs));
		total -= min(total,Z);
		printf("%lld\n",n*m - total);
	}
	return 0;
}

