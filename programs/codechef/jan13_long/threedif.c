//Program question at: http://www.codechef.com/JAN13/problems/THREEDIF
#include <stdio.h>
#define mod 1000000007LL
typedef long long LL;
inline void swap(LL *a, LL *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		LL A[3],a,b;
		scanf("%lld %lld %lld",&A[0],&A[1],&A[2]);
		if(A[0] > A[1] || A[1] > A[2])
		{
			for(a=0;a<3;a++)
			for(b=0;b<2-a;b++) if(A[b] > A[b+1]) swap(&A[b],&A[b+1]);
		}
		A[1] -= 1; A[2] -= 2;
		for(a=0;a<3;a++) A[a] %= mod;
		printf("%lld\n",(((A[0] * A[1]) % mod) * A[2]) % mod);
	}
	return 0;
}

