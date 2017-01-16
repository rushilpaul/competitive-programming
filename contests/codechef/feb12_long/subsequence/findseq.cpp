//Program question at: http://www.codechef.com/FEB12/problems/FINDSEQ
#include <cstdio>
#include <iostream>
using namespace std;
 
 int maxio=1000000;
 char buf[1000000], *s = buf + maxio;
 inline char getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
 inline long input() { char t = getc(); long n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res = res*10 + (t&15); t=getc(); } return res*n; }

char order[5];
int ans[5], ans_k=0, n;
long *ar;

inline bool check(int i)
{
	int o = order[ans_k-1], r = ar[i];
	for(int a=ans_k-2;a>=0;a--)
		if( !((r-ar[ans[a]] > 0 && o-order[a] > 0) || (r-ar[ans[a]] < 0 && o-order[a] < 0)) ) return 0;
	return 1;
}

bool solve(int st)
{
	if(ans_k > 4) return 1;
	for(int a=st;a<n;a++)
	{
		ans[ans_k++] = a;
		if(!check(a)) ans_k--;
		else
		{
			if( solve(a+1) ) return 1;
			ans_k--;
		}
	}
	return 0;
}

int main()
{
	int t = (int)input();
	while(t--)
	{
		n = (int)input();
		char ch = getc();
		while(!isdigit(ch)) ch=getc();
		order[0] = ch-48;
		for(int a=1;a<5;a++) order[a] = getc()-48;
		ar = new long[n];
		int k=0;
		for(int a=0;a<n;a++) ar[a] = input();
		ans_k = 0;
		if(solve(0))
			for(int a=0;a<5;a++) printf("%d%c",ans[a], a==4 ? '\n':' ');
		else printf("%d\n",-1);
		}
	return 0;
}
