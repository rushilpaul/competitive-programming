#include <stdio.h>
#define max(a,b) a>b?a:b

int **cache,**ar,m,n;
int f(int a, int b)
{
	int i,j,num=ar[a][b],s=1;
	for(i=a;i<m;i++)
	for(j=i==a ? b+1:b;j<n;j++)
		if(ar[i][j] <= num)
			s = cache[i][j] ? max(s,cache[i][j]+1) : max(s,f(i,j)+1);
	cache[a][b] = s;
	return s;
}

int main()
{
	int a,b,s=0;
	scanf("%d %d",&m,&n);
	ar = (int**)malloc(sizeof(int*)*m);
	cache = (int**)malloc(sizeof(int*)*m);
	for(a=0;a<m;a++)
	{
		ar[a] = (int*)malloc(sizeof(int)*n);
		cache[a] = (int*)malloc(sizeof(int)*n);
		for(b=0;b<n;b++)
		{
			scanf("%d",&ar[a][b]);
			cache[a][b] = 0;
		}
	}
	for(a=0;a<m;a++)
	for(b=0;b<n;b++)
		s = max(s,f(a,b));
	printf("%d\n",s);
	return 0;
}
