//Program question at: http://www.codechef.com/problems/NSIT15
#include <stdio.h>
#include <math.h>
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,d,a=0,s=0,ar[9]; scanf("%d %d",&n,&d);
		for(;a<9;a++) ar[a] = a<d ? a:a+1; a=0;
		while(n)
		{
			int t = n%9; if(!d) t = t?t:9;
			s += (d ? ar[t] : t)*pow(10,a++);
			n = d ? n/9 : (n-t)/9;
		}
		printf("%d\n",s);
	}
	return 0;
}
