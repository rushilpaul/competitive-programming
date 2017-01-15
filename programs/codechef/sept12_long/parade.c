//Program question at: http://www.codechef.com/SEP12/problems/CHEFTOWN
#include <stdio.h>
#include <string.h>
int maxio=4096;
char buf[4096], *s = buf + 4096;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc_(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }

int n,nb1,nb2;
inline void addp(char *P, int *nb, int i)
{
	P[i] = 1;
	int l=0,r=0;
	if(i-1>=0) // left
	{
		if(P[i-1])
		{
			l=1;
			if(nb[i-1] == 1) nb1--;
			nb[i]++;
			nb[i-1]++;
			if(nb[i-1] == 1) nb1++;
			else if(nb[i-1] == 2) nb2++;
		}
	}
	if(i+1<n) // right
	{
		if(P[i+1])
		{
			r=1;
			if(nb[i+1] == 1) nb1--;
			nb[i]++;
			nb[i+1]++;
			if(nb[i+1] == 1) nb1++;
			else if(nb[i+1] == 2) nb2++;
		}
	}
	if(l && r) nb2++;
	if( (l && !r) || (!l && r) ) nb1++;
}
inline void delp(char *P, int *nb, int i)
{
	P[i] = 0;
	if(i-1>=0) // left
	{
		if(P[i-1])
		{
			if(nb[i-1] == 1) nb1--;
			else if(nb[i-1] == 2) nb2--;
			nb[i-1]--;
			if(nb[i-1] == 1) nb1++;
		}
	}
	if(i+1<n) // right
	{
		if(P[i+1])
		{
			if(nb[i+1] == 1) nb1--;
			else if(nb[i+1] == 2) nb2--;
			nb[i+1]--;
			if(nb[i+1] == 1) nb1++;
		}
	}
	if(nb[i] == 2) nb2--;
	else if(nb[i] == 1) nb1--;
}

int main()
{
	int ans=0,a,w,cur; n = input(); w = input();
	char P[n]; int ar[n]; int nb[n];
	memset(nb,0,sizeof(int)*n);
	memset(P,0,n);
	nb1 = nb2 = 0;
	if(w==1) { printf("%d\n",n); return 0; }
	for(a=0;a<n;a++)
	{
		cur = input();
		ar[a] = cur;
		addp(P, nb, cur-1);
		if(a+1>w) // 1st w elements added
			delp(P, nb, ar[a-w]-1);
		if(nb1 == 2 && nb2 == w-2) ans++;
	}	
	printf("%d\n",ans);
	return 0;
}
