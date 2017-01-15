#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 2048

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

struct node
{
	LL F[4][4];
	int chef[4];
	node *left, *right;
	node()
	{
		left = right = NULL;
		F[0][1] = F[0][2] = F[0][3] = F[1][2] = F[1][3] = F[2][3] = F[1][0] = F[2][0] = F[3][0] = F[2][1] = F[3][1] = F[3][2] = 0;
		chef[0] = chef[1] = chef[2] = chef[3] = 0;
	}
};

vector<node> st;
char s[1000001];
int n,L,R;

inline int get(char ch)
{
	if(ch == 'c') return 0;
	else if(ch == 'h') return 1;
	else if(ch == 'e') return 2;
	else return 3;
}

inline node merge(node L, node R)
{
	node ans;
	ans.F[0][1] = L.F[0][1] + R.F[0][1] + (LL)L.chef[0] * R.chef[1];
	ans.F[0][2] = L.F[0][2] + R.F[0][2] + (LL)L.chef[0] * R.chef[2];
	ans.F[0][3] = L.F[0][3] + R.F[0][3] + (LL)L.chef[0] * R.chef[3];
	
	ans.F[1][2] = L.F[1][2] + R.F[1][2] + (LL)L.chef[1] * R.chef[2];
	ans.F[1][3] = L.F[1][3] + R.F[1][3] + (LL)L.chef[1] * R.chef[3];
	
	ans.F[2][3] = L.F[2][3] + R.F[2][3] + (LL)L.chef[2] * R.chef[3];
	
	ans.F[1][0] = L.F[1][0] + R.F[1][0] + (LL)L.chef[1] * R.chef[0];
	ans.F[2][0] = L.F[2][0] + R.F[2][0] + (LL)L.chef[2] * R.chef[0];
	ans.F[3][0] = L.F[3][0] + R.F[3][0] + (LL)L.chef[3] * R.chef[0];
	
	ans.F[2][1] = L.F[2][1] + R.F[2][1] + (LL)L.chef[2] * R.chef[1];
	ans.F[3][1] = L.F[3][1] + R.F[3][1] + (LL)L.chef[3] * R.chef[1];
	
	ans.F[3][2] = L.F[3][2] + R.F[3][2] + (LL)L.chef[3] * R.chef[2];
	
	ans.chef[0] = L.chef[0] + R.chef[0];
	ans.chef[1] = L.chef[1] + R.chef[1];
	ans.chef[2] = L.chef[2] + R.chef[2];
	ans.chef[3] = L.chef[3] + R.chef[3];	
	return ans;
}

node query(int i, int j, int index)
{
    if (L <= i && R >= j)
        return st[index];
 
    if (j < L || i > R)
        return node();
	
    int mid = (i+j)/2;
	return merge( query(i,mid,2*index+1), query(mid+1,j,2*index+2) );
}

node build(int i, int j, int index)
{
    if (i == j)
    {
		st[index].chef[get(s[i])]++;
		return st[index];
    }
    int mid = (i+j)/2;
	st[index] = merge( build(i,mid,2*index+1), build(mid+1,j,2*index+2) );
    return st[index];
}

void init()
{
    int x = (int)(ceil(log2(n))); // height
    int max_size = (1<<(x+1)) - 1;
	st.resize(max_size);
    build(0,n-1,0);
}

clock_t _time, total;

int main()
{
	_time = clock();
	n = readstr(s);
	init();
	
	int q = readint();
	while(q--)
	{
		char a = readchar(), b = readchar();
		int x = readint(), y = readint();
		x--; y--;
		node ans;
		L = x; R = y;
		ans = query(0,n-1,0);
		writeLL(ans.F[get(a)][get(b)]);
		putc1('\n');
	}
	flush();
	_time = clock() - _time;
	writedouble((double)_time/CLOCKS_PER_SEC,2);
	flush();
	return 0;
}
