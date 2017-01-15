#include <stdio.h>

int f(int n)
{
	if (n==0) return 0;
	if(n==1) return 2;
	int s = n+1;
	if (n%2 == 0)
	{
		s += f(n/2);
		s += f(n/2-1);
	}
	else
		s += 2*f(n/2);
	return s;
}

int main()
{
int t; scanf("%d\n",&t);
while(t--)
{
	int n,m; scanf("%d %d",&n,&m);
	int R = ((n+1)*(n+2))/2 - 1;
	int L = f(n);
	if (m < L)
		printf("-1\n");
	else if( m >= L && m <= R)
		printf("0\n");
	else
		printf("%d\n",m-R);
}
}


