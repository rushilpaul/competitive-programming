//program Q. 7
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

map<int,int> cache;
bool *cache2;

inline int perfect(int num)
{
	double sq = sqrt(num);
	if(int(sq) == sq) return (int)sq;
	return 0;
}

int find(int n)
{
	if(cache2[n-1]) return cache[n];
	int total=0;
	for(int a=1;a<=n/2;a++)
	{
		int tmp = (a<<1)-1,p;
		if( p=perfect(tmp*tmp + (n<<3)) )
		{
			total++;
			int tn = (1 - 2*a + p)/2;
			for(int b=a;b<a+tn;b++)
				total += find(b);
		}
	}
	cache2[n-1] = 1; cache[n] = total;
	return total;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n],max=0,total=0;
		for(int a=0;a<n;a++) { scanf("%d",&ar[a]); max = ar[a] > max ? ar[a] : max; }
		cache2 = new bool[max];
		for(int a=0;a<n;a++)
			total += find(ar[a]);
		if(total % 2 == 1) printf("HARRY\n");
		else printf("RON\n");
	}
	return 0;
}

