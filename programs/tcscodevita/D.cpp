#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

LL getmin(LL c, LL d, LL a, LL b)
{
	if(c >= d) return c;
	LL x = c % a, y = c % b;
	
}

int f(int v[], int x[], int y[], int n, int t)
{
	LL prev = v[0];
	for(int a=1;a<n;a++)
	{
		LL vol = v[a];
		if(v[a] > prev)
		{
			
		}
	}
}

int main()
{
	int n; scanf("%d",&n);
	int v[n], x[n], y[n];
	for(int a=0;a<n;a++)
		scanf("%d %d %d",v+a,x+a,y+a);
	int flag = 1;
	for(int a=0;a<n-1;a++)
		if(v[a] >= v[a+1]) { flag = 0; break; }
	if(flag)
	{
		printf("0");
		return 0;
	}
	LL L = 1, R = LLONG_MAX-2;
	while(L <= R)
	{
		LL mid = (L+R)/2;
		if(f(v,x,y,n,mid))
			R = mid-1;
		else
			L = mid+1;
	}
	printf("%lld",L);
	return 0;
}

