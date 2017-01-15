#include <stdio.h>
#define mod 1000000007
long long M[2][2] = {{0,1}, {1,1}}, ar[2][2], tmp[2][2];

void mul()
{
	tmp[0][0] = (ar[0][0]*M[0][0])%mod + (ar[0][1]*M[1][0])%mod;
	tmp[0][1] = (ar[0][0]*M[0][1])%mod + (ar[0][1]*M[1][1])%mod;
	tmp[1][0] = (ar[1][0]*M[0][0])%mod + (ar[1][1]*M[1][0])%mod;
	tmp[1][1] = (ar[1][0]*M[0][1])%mod + (ar[1][1]*M[1][1])%mod;
	ar[0][0] = tmp[0][0]%mod, ar[0][1] = tmp[0][1]%mod, ar[1][0] = tmp[1][0]%mod, ar[1][1] = tmp[1][1]%mod;
}

void sq()
{
	tmp[0][0] = (ar[0][0]*ar[0][0])%mod + (ar[0][1]*ar[1][0])%mod;
	tmp[0][1] = (ar[0][0]*ar[0][1])%mod + (ar[0][1]*ar[1][1])%mod;
	tmp[1][0] = (ar[1][0]*ar[0][0])%mod + (ar[1][1]*ar[1][0])%mod;
	tmp[1][1] = (ar[1][0]*ar[0][1])%mod + (ar[1][1]*ar[1][1])%mod;
	ar[0][0] = tmp[0][0]%mod, ar[0][1] = tmp[0][1]%mod, ar[1][0] = tmp[1][0]%mod, ar[1][1] = tmp[1][1]%mod;
}

void powM(int p)
{
	if(p == 1) return;
	if(p & 1)
	{
		powM(p/2);
		sq();
		mul();
	}
	else
	{
		powM(p/2);
		sq();
	}
}

void init()
{
	ar[0][0] = 0, ar[0][1] = 1, ar[1][0] = 1, ar[1][1] = 1;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		init();
		int n,g; scanf("%d %d",&n,&g);
		powM(n);
		n = ar[1][1];
		do
			g -= n&1;
		while(n>>=1);
		if(g) printf("INCORRECT\n");
		else printf("CORRECT\n");
	}
	return 0;
}
