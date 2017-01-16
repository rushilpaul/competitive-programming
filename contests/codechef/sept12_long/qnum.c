//Program question at: http://www.codechef.com/SEP12/problems/QNUMBER
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
typedef long long LL;
char P[1000001];
int N = 1000000; LL n;
int isprime;

inline void init()
{
	memset(P,1,N+1);
	int i,j;
	for(i=2;i<=1000;i++)
	{
		if(P[i] == 0) continue;
		if(n % i == 0 && i!=n) isprime = 0;
		for(j=i*i;j<=N;j+=i)
		{
			P[j] = 0;
			if(n % j == 0 && n!=j) isprime = 0;
		}
	}
}

LL gcd(LL a, LL b)
{ return !a || !b ? a+b : gcd(b,a%b); }

int sqrt_(LL n)
{
	LL two[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144LL,524288LL,1048576LL,2097152LL,4194304LL,8388608LL,16777216LL,33554432LL,67108864LL,134217728LL,268435456LL,536870912LL,1073741824LL,2147483648LL,4294967296LL,8589934592LL,17179869184LL,34359738368LL,68719476736LL,137438953472LL,274877906944LL,549755813888LL,1099511627776LL,2199023255552LL,4398046511104LL,8796093022208LL,17592186044416LL,35184372088832LL,70368744177664LL,140737488355328LL,281474976710656LL,562949953421312LL,1125899906842624LL,2251799813685248LL,4503599627370496LL,9007199254740992LL,18014398509481984LL,36028797018963968LL,72057594037927936LL,144115188075855872LL,288230376151711744LL,576460752303423488LL,1152921504606846976LL};
	int nbits=0,i=0;
	while(n>=two[i++]); nbits = i-1;
	LL x = 1 << (int)(ceil(nbits/2.0)), y;
	while(1)
	{
		y = (x + n/x)/2;
		if(y >= x) return x;
		x = y;
	}
}

int main()
{
	LL ans,q,k; int t,i;
	scanf("%lld %lld\n",&n,&q);
	LL srn = sqrt_(n);
	isprime=1;
	init();
	while(q--)
	{
		scanf("%d %lld",&t,&k);
		if(t==1)
		{
			if(n==1 || k==1) { printf("1\n"); continue; }
			if(isprime)
			{
				if(n == k) printf("2\n");
				else printf("1\n");
				continue;
			}
			ans = 1;
			LL hcf = gcd(n,k);
			if(hcf == 2) { printf("2\n"); continue; }
			LL sr = sqrt_(hcf);
			for(i=2;i<=sr;i++)
				if(hcf % i == 0) ans++;
			ans <<= 1;
			if(sr * sr == hcf) ans--;
			printf("%lld\n",ans);
		}
		else
		{
			ans = 1;
			if(n%k) ans = 0;
			int total = 1;
			for(i=2;i<=srn;i++)
				if(n%i == 0)
				{
					total++;
					if(i % k == 0) ans++;
					if((n/i) % k == 0) ans++;
				}
			total <<= 1;
			if(srn * srn == n) total--;
			if(k * k == n) ans--;
			if(k > n) ans = 0;
			if(t == 2)
			{
				if(n==1 && k>1) printf("0\n");
				else if(n>1 && k==1) printf("%d\n",total);
				else if(isprime) printf("0\n");
				else printf("%lld\n",ans);
			}
			else
			{
				//if(n==k && isprime) printf("0\n");	// wrong
				printf("%d\n",total-ans);
			}
		}
	}
	return 0;
}
