//Program question at: http://www.codechef.com/BTCD2012/problems/T03
#include<stdio.h>
int maxio=50000;
char buf[50000], *s = buf + 50000;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc_(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }

int main()
{
	int t=input();
	while(t--)
	{
		int a,b,n=input(),ans=0;
		int ar[n][2];
		for(a=0;a<n;a++) { ar[a][0] = input(); ar[a][1] = input(); }
		for(a=0;a<n;a++)
			for(b=a+1;b<n;b++)
			if((ar[a][0] > ar[b][0] && ar[a][1] < ar[b][1]) || (ar[a][0] < ar[b][0] && ar[a][1] > ar[b][1])) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
