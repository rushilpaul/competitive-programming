#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

const int max_primes = 1000001;		// 1e6+1
int isprime[max_primes], largestpdiv[max_primes];

void sieve()
{
	for(int a=0;a<max_primes;a++) isprime[a] = 1, largestpdiv[a] = 0;
	for(int a=2;a<max_primes;a++)
	{
		if(!isprime[a]) continue;
		largestpdiv[a] = a;
		for(int b=a+a;b<max_primes;b+=a)
		{
			isprime[b] = 0;
			largestpdiv[b] = a;
		}
	}
}

map<int,int> getprimefactors(int n)
{
	map<int,int> ans;
	int L;
	while( (L=largestpdiv[n]) > 0)
	{
		ans[L] = ans[L] + 1;
		n /= L;
	}
	return ans;
}

