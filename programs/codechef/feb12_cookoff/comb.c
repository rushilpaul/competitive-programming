//Program question at: http://www.codechef.com/COOK19/problems/DAILY
#include <stdio.h>

int fact(int n) { return n<=1 ? 1 : n*fact(n-1); }

inline int nCr(int n, int r)
{
	if(n < r) return 0;
	return fact(n) / (fact(r) * fact(n-r));
}

int main()
{
	int x,n,ans=0; scanf("%d %d", &x, &n);
	while(n--)
	{
		char aval[55];
		aval[54] = '\0';
		scanf("%s",aval);
		int i=0,j=53;
		for(; i<33; i+=4,j-=2)
		{
			int t=0,b=i;
			for(;b<i+4;b++) if(aval[b] == '0') t++;
			if(aval[j] == '0') t++; if(aval[j-1] == '0') t++;
			ans += nCr(t,x);
		}
	}
	printf("%d\n",ans);
	return 0;
}
