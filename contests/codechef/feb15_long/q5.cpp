#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 1024

char buf[max_buf_size], *_s = buf + max_buf_size;
inline char getc1(void) { if(_s >= buf + max_buf_size) { fread_unlocked(buf,1,max_buf_size,stdin); _s = buf; } return *(_s++); }
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

inline void putc1(char ch) { if(outbuf_p >= max_buf_size) { fwrite_unlocked(outbuf,1,max_buf_size,stdout); outbuf_p = 0; } outbuf[outbuf_p++] = ch; }

inline void flush() { fwrite_unlocked(outbuf,1,outbuf_p,stdout); }

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

// END of IO

inline int get(char ch)
{
	if(ch == 'c') return 0;
	else if(ch == 'h') return 1;
	else if(ch == 'e') return 2;
	else return 3;
}

#define maxi 1000000
#define putchar putc1

int chef[4][maxi], n;
LL cache[4][4][maxi];
char *s;

void init()
{
	const char str[5] = "chef";
	for(int a=0;a<4;a++) chef[a][n-1] = s[n-1] == str[a];

	for(int a=0;a<4;a++)
	for(int i=n-2;i>=0;i--)
		chef[a][i] = chef[a][i+1] + (s[i] == str[a]);

	for(int a=0;a<4;a++)
		for(int b=a+1;b<4;b++)
		{
			cache[a][b][0] = s[0] == str[a] ? chef[b][0] : 0;
			cache[b][a][0] = s[0] == str[b] ? chef[a][0] : 0;
			for(int i=1;i<n;i++)
			{
				cache[a][b][i] = cache[a][b][i-1] + (s[i] == str[a] ? chef[b][i] : 0);
				cache[b][a][i] = cache[b][a][i-1] + (s[i] == str[b] ? chef[a][i] : 0);
			}
		}
}

clock_t _time, total;

int main()
{
	_time = clock();
	s = new char[1000001];
	n = readstr(s);
	init();
	
	int q = readint();
	while(q--)
	{
		char a = get(readchar()), b = get(readchar());
		int x = readint(), y = readint();
		x--; y--;
		LL ans = x == 0 ? cache[a][b][y] : cache[a][b][y] - cache[a][b][x-1];
		LL ext;
		ext = y == n-1 ? chef[a][x] : chef[a][x] - chef[a][y+1];
		ext *= (y == n-1 ? 0 : chef[b][y+1]);
		ans -= ext;
		writeLL(ans);
		putchar('\n');
	}
	//_time = clock() - _time;
	flush();
	return 0;
}

