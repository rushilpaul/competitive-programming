#include <cstdio>
#include <cstring>
typedef long long LL;
using namespace std;
int mod = 1000000007;

int gcd(LL a, LL b) { return !a || !b ? a+b : gcd(b,a%b); }

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n], done[n];
		LL lcm=1;
		memset(done,0,sizeof(int)*n);
		for(int a=0;a<n;a++) { scanf("%d",ar+a); ar[a]--; }
		for(int a=0;a<n;a++)
		{
			if(done[a]) continue;
			int len=0,orig=a;
			do
			{
				len++;
				done[orig] = 1;
				orig = ar[orig];
			}while(orig!=a);
			int g = gcd(lcm,len);
			lcm = (lcm*len) / g;
			lcm %= mod;
			//printf("length: %d\n",len);
		}
		printf("%d\n",lcm);
	}
	return 0;
}
