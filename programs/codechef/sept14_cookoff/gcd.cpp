#include <cstdio>

int findgcd(int a, int b) { return !a || !b ? a+b : findgcd(b,a%b); }

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n];
		for(int a=0;a<n;a++) scanf("%d",ar+a);
		if(n == 1) { printf("-1\n"); continue; }
		int gcd[n];
		gcd[0] = findgcd(ar[0],ar[1]);
		for(int a=2;a<n;a++) gcd[a-1] = findgcd(ar[a],gcd[a-2]);
		if(gcd[n-2] == 1) { printf("%d\n",n); continue; }
		int count=0,m=0;
		for(int a=0;a<n-1;a++)
		{
			if(gcd[a] == 1) count++;
			else count = 0;
			if(count > m) m = count;
		}
		if(count > m) m = count;
		if(m == 0) m = -1;
		else m++;
		printf("%d\n",m);
	}
	return 0;
}
