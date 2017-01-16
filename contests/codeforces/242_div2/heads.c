#include <stdio.h>
int main()
{
	int s=0,x,y,a,b; scanf("%d %d %d %d",&x,&y,&a,&b);
	register int i,j;
	for(i=b;i<x;i++)
		if(i < x)
			s += (x-i);
		else if(i > y)
		{
			s += (x-i)*y;
			break;
		}	
	printf("%d\n",s);

	for(i=b;i<=y;i++)
	{
		loop:
		if(i >= a)
		{
			if(a < x) { a++; goto loop; }
			else return 0;
		}
		for(j=a;j<=x;j++) printf("%d %d\n",j,i);
	}
	return 0;
}
/*
3 3
2 3
*/

