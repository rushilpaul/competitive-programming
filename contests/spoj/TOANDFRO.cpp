#include <cstdio>
#include <iostream>
typedef long long LL;
#define max_buf_size 1024
#define putchar putc1

char buf[max_buf_size], *_s = buf + max_buf_size;
inline char getc1(void) { if(_s >= buf + max_buf_size) { fread(buf,1,max_buf_size,stdin); _s = buf; } return *(_s++); }
inline int readint() { char t = getc1(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline LL readLL() { char t = getc1(); int n=1; LL res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline char skipwhitespace() { char ch = getc1(); while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getc1(); return ch; }
inline int readline(char *s)
{
	char ch=skipwhitespace();
	int n=0;
	while( (ch != '\n') )
	{
		s[n++] = ch;
		ch = getc1();
	}
	s[n] = 0;
	return n;
}

inline int readstr(char *s)
{
	char ch=skipwhitespace();
	int n=0;
	while( (ch != '\n' && ch != ' ' && ch != '\t') )
	{
		s[n++] = ch;
		ch = getc1();
	}
	s[n] = 0;
	return n;
}

inline char readchar() { return skipwhitespace(); }

char outbuf[max_buf_size];
int outbuf_p;

inline void putc1(char ch) { if(outbuf_p >= max_buf_size) { fwrite(outbuf,1,max_buf_size,stdout); outbuf_p = 0; } outbuf[outbuf_p++] = ch; }

inline void flush() { fwrite(outbuf,1,outbuf_p,stdout); outbuf_p = 0; }

inline void writeint(int n)
{
	int sign = n >= 0 ? 1 : -1;
	n = n>0 ? n : -n;
	char buf[10];
	int i = 9;
	if(!n) buf[i--] = 48;
	while(n)
	{
		buf[i--] = n % 10 + 48;
		n /= 10;
	}
	if(sign < 0) putc1('-');
	while(++i < 10) putc1(buf[i]);
}

inline void writeLL(LL n)
{
	int sign = n >= 0 ? 1 : -1;
	n = n>0 ? n : -n;
	char buf[25];
	int i = 24;
	if(!n) buf[i--] = 48;
	while(n)
	{
		buf[i--] = n % 10 + 48;
		n /= 10;
	}
	if(sign < 0) putc1('-');
	while(++i < 25) putc1(buf[i]);
}

inline void writestr(char *s)
{
	char *p = s;
	while(*p)
	{
		putc1(*p);
		p++;
	}
}

inline void writedouble(double d, int p) { char buf[40]; sprintf(buf,"%.*f",p,d); writestr(buf); }

#include <bits/stdc++.h>
using namespace std;

int main()
{
	while(1)
	{
		int n = readint();
		if(n == 0) break;
		char s[201];
		int len = readstr(s);
		string str(s);
		int i=1;
		for(int a=0;a<len;a+=n)
		{
			i++;
			if(i % 2)
				reverse(str.begin()+a,str.begin()+a+n);
		}
		string ans="";
		i=0;
		int start=0;
		while(ans.length() != len)
		{
			ans += str[i];
			i+=n;
			if(i >= len)
				i = ++start;
		}
		printf("%s\n",ans.c_str());
	}

	return 0;
}
