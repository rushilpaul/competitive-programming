#include <stdio.h>
int maxio=524288;
char buf[524288], *s = buf + 524288;
inline char getc1(void) { if(s >= buf + maxio) { fread_unlocked(buf,1,maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc1(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }

int main()
{
	int n = input(),k = input(),ans=0;
	while(n--)
		if(input() % k == 0) ans++;
	printf("%d\n",ans);
	return 0;
}
