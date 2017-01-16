//Program question at: http://www.codechef.com/JULY12/problems/SAD
#include <stdio.h>
int main()
{
	int a,b,r,c; scanf("%d %d\n",&r,&c);
	int ar[r][c];
	int min_r[r];
	for(a=0;a<r;a++) min_r[a] = 100000000;
	for(a=0;a<r;a++)
		for(b=0;b<c;b++) { scanf("%d",&ar[a][b]); if(ar[a][b] < min_r[a]) min_r[a] = ar[a][b]; }
	
	for(a=0;a<r;a++)
	{
		for(b=0;b<c;b++) if(ar[a][b] == min_r[a])
		{
			int row=0;
			for(;row<r;row++) if(ar[row][b] > ar[a][b]) break;
			if(row == r) { printf("%d\n",ar[a][b]); return 0; }
		}
	}
	printf("GUESS\n");
	return 0;
}
