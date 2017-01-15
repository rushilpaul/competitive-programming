#include <cstdio>
#include <iostream>
using namespace std;

int maxio=1000000;
char buf[1000000], *s = buf + maxio;
inline char getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc(); } return res*n; }

int abs_(int x)

 int main()
 {
	int t = input();
	while(t--)
	{
		int x = input(), y=input();
		char D; //scanf("%c",&D);
		D = getc();

		int n = input();
		int A[n][2]; char dir[n];
		for(int i=0;i<n;i++)
		{
			//scanf("%d %d %c", &A[i][0], &A[i][1], &dir[i]);
			A[i][0] = input(); A[i][1] = input();
			dir[i] = getc();
		}
		double min = 1000000; bool flag = true;

		for(int i=0;i<n;i++)
		{
			char d = dir[i];
			if(D == d) continue;
			int x1 = A[i][0], y1 = A[i][1];
			bool safe = true;
			if(D == 'U')
			{
				if(d == 'D')
				{
					if( !(x1 == x && y1 > y)) continue; safe = false;
				}
				else if(d == 'L')
				{
					if( !(x1 > x && y1 > y)) continue; safe = false;
				}
				else if(d == 'R')
				{
					if( !(x1 < x && y1 > y)) continue; safe = false;
				}
			}
			else if(D == 'D')
			{
				if(d == 'U')
				{
					if( !(x1 == x && y1 < y)) continue; safe = false;
				}
				else if(d == 'L')
				{
					if( !(x1 > x && y1 < y)) continue; safe = false;
				}
				else if(d == 'R')
				{
					if( !(x1 < x && y1 < y)) continue; safe = false;
				}
			}
			else if(D == 'L')
			{
				if(d == 'U')
				{
					if( !(x1 < x && y1 < y)) continue; safe = false;
				}
				else if(d == 'D')
				{
					if( !(x1 < x && y1 > y)) continue; safe = false;
				}
				else if(d == 'R')
				{
					if( !(x1 < x && y1 == y)) continue; safe = false;
				}
			}
			else if(D == 'R')
			{
				if(d == 'U')
				{
					if( !(x1 > x && y1 < y)) continue; safe = false;
				}
				else if(d == 'D')
				{
					if( !(x1 > x && y1 > y)) continue; safe = false;
				}
				else if(d == 'L')
				{
					if( !(x1 > x && y1 == y)) continue; safe = false;
				}
			}
			if( abs_(x1-x) != abs_(y1-y) && !(x==x1 || y == y1)) continue;
			if(!safe)
			{
				flag = false;
				double time = (abs_(x1-x) + abs_(y1-y) ) / 2.0;
				if(time < min) min = time;
			}
		}	// end enumeration
		if(flag) printf("%s\n","SAFE");
		else printf("%.1f\n",min);
	}	// end while
	return 0;
 }

int abs_(int x)
{
return x<0 ? -x : x;
}
