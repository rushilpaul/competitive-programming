//Program question at: http://www.codechef.com/SEP12/problems/CROWD
#include <stdio.h>
typedef long long LL;
LL ans, mod = 1000000007LL;
LL base[3][3] = { {1,1,1}, {1,0,0}, {0,1,0} }, M[3][3], result[3][3];
LL f1(LL n)
{
	LL tmp;
	if(n==0) return 1;
	if(n&1)
	{
		tmp = f1((n-1)/2);
		tmp = ((tmp*tmp)<<1);
	}
	else
	{
		tmp = f1(n/2);
		tmp = tmp*tmp;
	}
	return tmp%mod;

}
inline void sq()
{
	int i,j,k;
	for(i=0;i<3;i++) for(j=0;j<3;j++)
	{
		result[i][j] = 0;
		for(k=0;k<3;k++)
		{
			result[i][j] += (M[i][k]*M[k][j])%mod;
			result[i][j] %= mod;
		}
	}
	for(i=0;i<3;i++) for(j=0;j<3;j++) M[i][j] = result[i][j];
}

inline void mul()
{
	int i,j,k;
	for(i=0;i<3;i++) for(j=0;j<3;j++)
	{
		result[i][j] = 0;
		for(k=0;k<3;k++)
		{
			result[i][j] += (M[i][k]*base[k][j])%mod;
			result[i][j] %= mod;
		}
	}
	for(i=0;i<3;i++) for(j=0;j<3;j++) M[i][j] = result[i][j];
}

void f2(LL n)
{
	if(n==1) return;
	if(n%2)
	{
		f2((n-1)/2);
		sq(); mul();
	}
	else
	{
		f2(n/2);
		sq();
	}
}

int main()
{
	int i,j,t; scanf("%d\n",&t);
	while(t--)
	{
		LL n; scanf("%lld",&n);
		if(n<3) { printf("0\n"); continue; }
		for(i=0;i<3;i++) for(j=0;j<3;j++) M[i][j] = base[i][j];
		ans = f1(n);
		f2(n-2);
		n = ( (M[0][0]*4)%mod + (M[0][1]*2)%mod + M[0][2] ) % mod;
		if(n > ans) ans = mod+ans-n;
		else ans = (ans-n) % mod;
		printf("%lld\n",ans);
	}
	return 0;
}
