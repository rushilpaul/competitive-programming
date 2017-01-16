#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int f(int n)
{
	int s5=0, s2=0, tmp = n;
	while(n % 5 == 0)
	{
		n /= 5;
		s5++;
	}
	while(tmp % 2 == 0)
	{
		tmp /= 2;
		s2++;
	}
	return max(0,s5 - s2);
}

ULL L[] = { 1, 4, 4, 744, 7744, 7744, 7744, 47744, 447744, 4447744, 44447744, 44447744, 74444447744LL };

int main()
{
	int n; scanf("%d",&n);
	while(n--)
	{
		int x; scanf("%d",&x);
		printf("%llu\n",(1ULL << (f(x)+1)/2*2) * x);
	}
	return 0;
}

