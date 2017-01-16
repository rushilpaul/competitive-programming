#include <cstdio>
#include <iostream>
#define max_buf_size 512
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
char in_buf[max_buf_size], out_buf[max_buf_size];
int buf_ptr=max_buf_size, cur_buf_size=max_buf_size;

namespace std
{
struct _init_
{
	_init_() { setvbuf(stdout,out_buf,_IOFBF,max_buf_size); }
} _init_ob_unused;

inline int adjust_buf_ptr()
{
	if(buf_ptr >= cur_buf_size)
	{
		buf_ptr = 0;
		cur_buf_size = fread(in_buf,sizeof(char),max_buf_size,stdin);
	}
	return cur_buf_size;
}

inline char readchar()
{
	if(!adjust_buf_ptr()) return 0;
	return in_buf[buf_ptr++];
}

inline void readstr(char *s, int len)
{
	int a; char ch;
	while( (ch=in_buf[buf_ptr]) == ' ' || ch == '\n' || ch == '\r' || ch == '\t')
	{
		buf_ptr++;
		if(!adjust_buf_ptr()) return;
	}
	for(a=0;a<len-1;a++) { s[a] = readchar(); if(s[a] == '\n' || s[a] == '\r' || s[a] == ' ' || s[a] == '\t') break; }
	s[a] = 0;
}

inline void readline(char *s, int len)
{
	int a;
	for(a=0;a<len-1;a++) { s[a] = readchar(); if(s[a] == '\n' || s[a] == '\r') break; }
	s[a] = 0;
}

inline uint readuint()
{
	unsigned int n = 0;
	char ch;
	do
		if(!adjust_buf_ptr()) return 0;
	while( !isdigit(ch=in_buf[buf_ptr++]) );
	buf_ptr--;
	while( isdigit(ch=in_buf[buf_ptr]) )
	{
		buf_ptr++;
		n = n*10 + ch-48;
		if(!adjust_buf_ptr()) return n;
	}
	return n;
}

inline int readint()
{
	int n=0,sign=1;
	char ch;
	do
		if(!adjust_buf_ptr()) return 0;
	while( !isdigit(ch=in_buf[buf_ptr++]) && ch != '-');
	buf_ptr--;
	if(ch == '-')
	{
		sign=-1;
		buf_ptr++;
		if(!adjust_buf_ptr()) return 0;
	}
	while( isdigit(ch=in_buf[buf_ptr]) )
	{
		buf_ptr++;
		n = n*10 + ch-48;
		if(!adjust_buf_ptr()) break;
	}
	return n*sign;
}

inline ULL readULL()
{
	ULL n = 0;
	char ch;
	do
		if(!adjust_buf_ptr()) return 0;
	while( !isdigit(ch=in_buf[buf_ptr++]) );
	buf_ptr--;
	while( isdigit(ch=in_buf[buf_ptr]) )
	{
		buf_ptr++;
		n = n*10 + ch-48;
		if(!adjust_buf_ptr()) return n;
	}
	return n;
}

inline LL readLL()
{
	LL n=0; int sign=1;
	char ch;
	do
		if(!adjust_buf_ptr()) return 0;
	while( !isdigit(ch=in_buf[buf_ptr++]) && ch != '-');
	buf_ptr--;
	if(ch == '-')
	{
		sign=-1;
		buf_ptr++;
		if(!adjust_buf_ptr()) return 0;
	}
	while( isdigit(ch=in_buf[buf_ptr]) )
	{
		buf_ptr++;
		n = n*10 + ch-48;
		if(!adjust_buf_ptr()) break;
	}
	return n*sign;
}
inline double readdouble()
{
	double n=readint();
	int sign = n<0?-1:1;
	char ch = in_buf[buf_ptr];
	if(ch != '.') return n;
	buf_ptr++;
	if(!adjust_buf_ptr()) return n;
	int exp=10;
	while( isdigit(ch=in_buf[buf_ptr]) )
	{
		buf_ptr++;
		if(sign == 1)
			n += (ch-48)/(double)exp;
		else
			n -= (ch-48)/(double)exp;
		exp *= 10;
		if(!adjust_buf_ptr()) break;
	}
	return n;
}
}

using namespace std;

inline int abs(int x) { return x>0?x:-x; }

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint(), k = readint();
		int ar[n],ans=0,min=2000000000,tmp;
		for(int a=0;a<n;a++) ar[a] = readint();
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
		{
			tmp = abs(ar[a] + ar[b] - k);
			if(tmp < min) min = tmp;
		}
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
			if(abs(ar[a]+ar[b]-k) == min) ans++;
		printf("%d %d\n",min,ans);
	}
}
