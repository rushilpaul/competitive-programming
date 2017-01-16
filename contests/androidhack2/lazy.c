//Program question at: http://www.codechef.com/ADR2012/problems/A104
#include <stdio.h>

void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
	int n,a,b; scanf("%d\n",&n);
	int ar[n],pos[n];
	for(a=0;a<n;a++) { scanf("%d\n",&ar[a]); pos[a]=a+1; }
	for(a=0;a<n;a++)
	for(b=0;b<n-1;b++)
		if(ar[b] < ar[b+1])
		{
			swap(&ar[b],&ar[b+1]); swap(&pos[b],&pos[b+1]);
		}
	for(a=0;a<n;a++) printf("%d\n",pos[a]);
	return 0;
}
