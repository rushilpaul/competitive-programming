#include <bits/stdc++.h>
using namespace std;
#define max_buf_size 1024

struct _init_
{
	_init_()
	{
		ios_base::sync_with_stdio(0); cin.tie(0);
		setvbuf(stdout,NULL,_IOFBF,max_buf_size);
		setvbuf(stdin,NULL,_IOFBF,max_buf_size);
	}
} _init_ob_unused;

int gcd(int a, int b) { return !a || !b ? a+b : gcd(b,a%b); }

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d %d",&n,&q);
		int ar[n];
		for(int &a : ar) scanf("%d",&a);
		int F[n], B[n];
		F[0] = ar[0];
		B[n-1] = ar[n-1];
		for(int a=1;a<n;a++)
		{
			F[a] = gcd(F[a-1],ar[a]);
			B[n-1-a] = gcd(B[n-a],ar[n-1-a]);
		}
		while(q--)
		{
			int l,r; scanf("%d %d",&l,&r);
			l--; r--;
			int a = l==0 ? 0 : F[l-1], b = r==n-1 ? 0 : B[r+1];
			printf("%d\n",gcd(a,b));
		}
	}
	return 0;
}
