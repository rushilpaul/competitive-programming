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

inline int readstr(char *s, int len)	// buffer needs to be at least len+1 in size
{
	if(!adjust_buf_ptr()) return 0;
	int a, str_len=0; char ch;
	while( (ch=in_buf[buf_ptr]) == ' ' || ch == '\n' || ch == '\r' || ch == '\t')
	{
		buf_ptr++;
		if(!adjust_buf_ptr()) return 0;
	}
	for(a=0;a<len;a++) { s[a] = readchar(); if(s[a] == '\n' || s[a] == '\r' || s[a] == ' ' || s[a] == '\t') break; str_len++; }
	s[a] = 0;
	return str_len;
}

inline int readline(char *s, int len)	// buffer needs to be at least len+1 in size
{
	if(!adjust_buf_ptr()) return 0;
	int a, str_len=0; char ch;
	while( (ch=in_buf[buf_ptr]) == '\n' || ch == '\r')
	{
		buf_ptr++;
		if(!adjust_buf_ptr()) return 0;
	}
	for(a=0;a<len;a++) { s[a] = readchar(); if(s[a] == '\n' || s[a] == '\r') break; str_len++; }
	s[a] = 0;
	return str_len;
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

#include <cmath>
using namespace std;

int main()
{
	int t = readint();
	while(t--)
	{
		int x = abs(readint()), y = abs(readint());
		if(x == y) printf("%d\n",x*2);
		else if(x > y)
		{
			if(x&1)
				printf("%d\n",y&1 ? x*2 : x*2+1);
			else
				printf("%d\n",y&1 ? x*2+1 : x*2);
		}
		else
		{
			if(y&1)
				printf("%d\n",x&1 ? y*2 : y*2-1);
			else
				printf("%d\n",x&1 ? y*2-1 : y*2);
		}
	}
	return 0;
}
