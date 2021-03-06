#include <cstdio>
#include <cmath>
using namespace std;

#define lim 100000
#define P 9593
inline void precompute();

int ar[lim];
int primes[P];
int balanced[P];

inline void precompute()
{
	int k=0;
	for(int i=2;i<(int)sqrt(lim);i++)
	{
		if(!ar[i])
		{
			primes[k++] = i;
			for(int j=i*i;j<lim;j+=i)
				ar[j] = 1;
		}
	}
	for(int i=(int)sqrt(lim);i<lim;i++) if(!ar[i]) primes[k++] = i;
	k=0;
	for(int i=1;i<P-1;i++)
	{
		int *m = &primes[i];
		if( (*m)<<1 == *(m-1) + *(m+1) ) balanced[k++] = *m;
	}
}

int main()
{
	precompute();
	for(int a=0;balanced[a];a++) printf("%d,",balanced[a]);
	return 0;
}
