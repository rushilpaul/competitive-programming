//Program question at: http://www.codechef.com/AUG12/MACGUN
#include <stdio.h>
char **ar;
int m,n,f;

inline int check(int x, int y)
{
	if(x >= m || y >= n || x < 0 || y < 0) return 0;
	char ch = ar[x][y];
	if(ch == 'F' || ( ch > 0 && ch <= 4)) return 1;
	return 0;
}

inline int valid(int x, int y)
{
	if(x >= m || y >= n || x < 0 || y < 0) return 0;
	char ch = ar[x][y];
	if(ch == 'F' || ch <= 4) return 1;
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

inline void del(int x, int y)
{
	if(check(x+2,y+2) && ar[x+2][y+2]) ar[x+2][y+2] -= 1;
	if(check(x-2,y+2) && ar[x-2][y+2]) ar[x-2][y+2] -= 1;
	if(check(x+2,y-2) && ar[x+2][y-2]) ar[x+2][y-2] -= 1;
	if(check(x-2,y-2) && ar[x-2][y-2]) ar[x-2][y-2] -= 1;
}

int main()
{
	int a,b; char ch;
	while(1)
	{
		scanf("%d %d\n",&m,&n);
		if(m == 0) return 0;
		ar = (char**)malloc(sizeof(char**)*m);
		f=0;
		for(a=0;a<m;a++)
		{
			ar[a] = (char*)malloc(sizeof(char*)*n);
			for(b=0;b<n;b++)
			{
				scanf("%c",&ch);
				while(ch < 65 || ch > 90) scanf("%c",&ch);
				ar[a][b] = ch;
				if(ch == 'F') f++;
			}
		} // end of input
		for(a=0;a<m;a++)
		for(b=0;b<n;b++)
			if(ar[a][b] == 'G')
			{
				if(valid(a+2,b+2)) { ar[a+2][b+2] = 'x'; f--; }
				if(valid(a+2,b-2)) { ar[a+2][b-2] = 'x'; f--; }
				if(valid(a-2,b+2)) { ar[a-2][b+2] = 'x'; f--; }
				if(valid(a-2,b-2)) { ar[a-2][b-2] = 'x'; f--; }
			}
			else if(check(a,b)) ar[a][b] = count(a,b);
		
		/*for(a=0;a<m;a++) { printf("\n");
		for(b=0;b<n;b++)
		printf("%d ",ar[a][b]); }
		return 0;
		*/
			
		for(a=0;a<m;a++)
		for(b=0;b<n;b++)
		{
			if(check(a,b))
			{
				if(check(a+2,b+2) && ar[a+1][b+1] != 'P')
				{
					if(ar[a+2][b+2] >= ar[a][b])
					{
						ar[a+2][b+2] = 'x';
						f--;
						del(a+2,b+2);
					}
					else
					{
						ar[a][b] = 'x';
						f--;
						del(a,b);
						continue;
					}
				}
				if(check(a+2,b-2) && ar[a+1][b-1] != 'P')
				{
					if(ar[a+2][b-2] >= ar[a][b])
					{
						ar[a+2][b-2] = 'x';
						f--;
						del(a+2,b-2);
					}
					else
					{
						ar[a][b] = 'x';
						f--;
						del(a,b);
						continue;
					}
				}
				if(check(a-2,b+2) && ar[a-1][b+1] != 'P')
				{
					if(ar[a-2][b+2] >= ar[a][b])
					{
						ar[a-2][b+2] = 'x';
						f--;
						del(a-2,b+2);
					}
					else
					{
						ar[a][b] = 'x';
						f--;
						del(a,b);
						continue;
					}
				}
				if(check(a-2,b-2) && ar[a-1][b-1] != 'P')
				{
					if(ar[a-2][b-2] >= ar[a][b])
					{
						ar[a-2][b-2] = 'x';
						f--;
						del(a-2,b-2);
					}
					else
					{
						ar[a][b] = 'x';
						f--;
						del(a,b);
						continue;
					}
				}
			}
		}
		printf("%d\n",f);
	}
	return 0;
}






