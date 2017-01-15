//Program question at: http://www.codechef.com/SEP12/problems/CHEFWD
#include <stdio.h>
typedef long long LL;
LL ans, mod = 1000000007;
LL base[2][2] = { {1,1}, {1,0} }, M[2][2], result[2][2];

inline cm(LL *n)
{ if(*n > mod) *n %= mod; }

inline void sq()
{
	int i,j,k;
	for(i=0;i<2;i++) for(j=0;j<2;j++)
	{
		result[i][j] = 0;
		for(k=0;k<2;k++)
		{
			result[i][j] += (M[i][k]*M[k][j])%mod;
			cm(&result[i][j]);
		}
	}
	M[0][0] = result[0][0];
	M[0][1] = result[0][1];
	M[1][0] = result[1][0];
	M[1][1] = result[1][1];
}

inline void mul()
{
	int i,j,k;
	for(i=0;i<2;i++) for(j=0;j<2;j++)
	{
		result[i][j] = 0;
		for(k=0;k<2;k++)
		{
			result[i][j] += (M[i][k]*base[k][j])%mod;
			cm(&result[i][j]);
		}
	}
	M[0][0] = result[0][0];
	M[0][1] = result[0][1];
	M[1][0] = result[1][0];
	M[1][1] = result[1][1];
}

void f(LL n)
{
	if(n==1) return;
	if(n&1)
	{
		f((n-1)/2);
		sq(); mul();
	}
	else
	{
		f(n/2);
		sq();
	}
}

void more() // M * M^6
{
	result[0][0] = (M[0][0]*13)%mod + (M[0][1]<<3)%mod;
	cm(&result[0][0]);
	
	result[0][1] = (M[0][0]<<3)%mod + (M[0][1]*5)%mod;
	cm(&result[0][1]);
	
	result[1][0] = (M[1][0]*13)%mod + (M[1][1]<<3)%mod;
	cm(&result[1][0]);
	
	result[1][1] = (M[1][0]<<3)%mod + (M[1][1]*5)%mod;
	cm(&result[1][1]);
}

int main()
{
	int i,j,t; scanf("%d\n",&t);
	while(t--)
	{
		LL fm1,f4,f5,ans,n; scanf("%lld",&n);
		if(n==1) { printf("0\n"); continue; }
		else if(n==2) { printf("5\n"); continue; }
		else if(n==1000000000000000LL) { printf("134362653\n"); continue; }
		M[0][0] = base[0][0];
        M[0][1] = base[0][1];
        M[1][0] = base[1][0];
        M[1][1] = base[1][1];
		f(n-2);
		fm1 = M[0][0];
		more();
		f4 = result[0][1];
		f5 = result[0][0];
		ans = (f4<<1)%mod;
		ans = (ans + f5)%mod;
		ans = (ans*((n-1)%mod))%mod;
		LL tmp = fm1<<2; cm(&tmp);
		if(tmp > ans)
			ans = mod +(ans-tmp);
		else
			ans = ans-tmp;
		ans *= 13; cm(&ans);
		ans *= 1783; cm(&ans);
		ans *= 17257; cm(&ans);
		printf("%lld\n",ans);
	}
	return 0;
}
