//Program question at: http://www.codechef.com/AUG12/MACGUN
#include <stdio.h>
char **ar;
int m,n,free;

inline int check(int x, int y)
{
	if(x >= m || y >= n || x < 0 || y < 0) return 0;
	if(ar[x][y] == 'F') return 1;
	return 0;
}

inline int count(int x, int y)
{
	int guns=0;
	if(check(x+2,y+2)) guns++;
	if(check(x-2,y+2)) guns++;
	if(check(x+2,y-2)) guns++;
	if(check(x-2,y-2)) guns++;
	return guns;
}

inline del(int x, int y)
{
	if(check(x+2,y+2)) ar[x+2][y+2] -= 1;
	if(check(x-2,y+2)) ar[x-2][y+2] -= 1;
	if(check(x+2,y-2)) ar[x+2][y-2] -= 1;
	if(check(x-2,y-2)) ar[x-2][y-2] -= 1;
}

int main()
{
	int a,b; char ch;
	while(1)
	{
		scanf("%d %d\n",&m,&n);
		if(m == 0) return 0;
		ar = (char**)malloc(sizeof(char**)*m);
		for(a=0;a<m;a++)
		{
			ar[a] = (char*)malloc(sizeof(char*)*n);
			for(b=0;b<n;b++)
			{
				scanf("%c",&ch);
				while(ch < 65 || ch > 90) scanf("%c",&ch);
				ar[a][b] = ch;
				if(ch == 'F') free++;
			}
		} // end of input
		for(a=0;a<m;a++)
		for(b=0;b<n;b++)
		{
			if(!check(a,b)) continue;
			int guns = count(a,b);
			if(check(a+2,b+2))
			{
				if(check(a+4,b+4)) 
			}
		}
	}
}






