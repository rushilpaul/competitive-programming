#include <bits/stdc++.h>
using namespace std;

int ar[100];

double calc(int n)
{
	double ans=0;
	for(int a=0;a<n;a++)
		if(ar[a] == -1) ans++;
	for(int a=0;a<n;a++)
		if(ar[a] != -1)
			ans *= (1.0/a);
	return ans / (1<<(n-1));
}

double ans = 0;

void f(int i, int n)
{
	if(i == n)
	{
		ans += calc(n);
		return;
	}
	ar[i] = -1;
	f(i+1,n);
	for(int a=0;a<i;a++)
	{
		ar[i] = a;
		f(i+1,n);
	}
}

int main()
{
	int n; scanf("%d",&n);
	f(0,n);
	printf("%f\n",ans);
}

