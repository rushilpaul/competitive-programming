//Program question at: http://www.codechef.com/FEB12/problems/WCOUNT
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define mod 1000000007
int maxio=1000000;
char buf[1000000], *s = buf + maxio;
inline char getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res = res*10 + (t&15); t=getc(); } return res*n; }

int fact[] = { 2,6,24,120,720,5040,40320,362880,3628800 };

int hcf(int a,int b)
{ return !a || !b ? a+b : hcf(b,a%b); }

int main()
{
	int t = input();
	while(t--)
	{
		char ch; int s=0;
		char U[26], L[26];
		for(int a=0;a<26;U[a]=0,L[a++]=0);
		while(1)
		{
			ch = getc();
			if(ch == ' ' || ch == '\n') break;
			if(ch <= 90) U[ch-65]++;
			else L[ch-97]++;
			s++;
		}
		int ar[s];
		for(int a=0;a<s;ar[a++]=a+1);
		for(int a=0;a<26;a++)
		{
			if(U[a] > 1)
			{
				int div = fact[U[a]-2];
				for(int a=0;a<s && div>1;a++)
				{
					int h = hcf(ar[a],div);
					ar[a] /= h;
					div /= h;
				}
			}
			if(L[a] > 1)
			{
				int div = fact[L[a]-2];
				for(int a=0;a<s && div>1;a++)
				{
					int h = hcf(ar[a],div);
					ar[a] /= h;
					div /= h;
				}
			}
		}
		unsigned long long int p=1;
		for(int a=0;a<s;a++)
		{
			p *= ar[a];
			if(p > mod) p %= mod;
		}
		printf("%llu\n",p);
	}
	return 0;
}
