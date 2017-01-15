//Program question at: http://www.codechef.com/APRIL12/problems/PLAYFIT
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int maxio=3000000;
char buf[3000000], *s = buf + maxio;
inline char getc(void) { if(s >= buf + maxio) { fread_unlocked(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc(); } return res*n; }


int main()
{
	int t = input();
	while(t--)
	{
		int s = input(), max = 0;
		int ar[s+1][2]; memset(ar,-1,(s+1)*2*sizeof(int));
		for(int a=0;a<s;a++)
		{
			int n = input();
			for(int b=0;b<s;b++)
			{
				if(ar[b][0] == -1) { ar[b][0] = n; break; }
				if(ar[b][1] == -1 && ar[b][0] < n) { ar[b][1] = n;
													 if(ar[b][1] - ar[b][0] > max) max = ar[b][1] - ar[b][0];
													 break; }
				if(ar[b][1] < n) {  ar[b][1] = n;
									if(ar[b][1] - ar[b][0] > max) max = ar[b][1] - ar[b][0];
									if(ar[b+1][0] == -1) break; }
			}
		}
		if(max) printf("%d\n",max);
		else printf("UNFIT\n");
	}
	return 0;
}
