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

int ar[300000];

struct node
{
	map<int,int> m;
	int max_val;
	node *left, *right;
	node()
	{
		left = right = NULL;
		m.clear();
		max_val = 0;
	}
};

inline node merge(node &L, node &R)
{
	node ans;
	for(auto a : L.m)
	{
		ans.m[a.first] = a.second;
		ans.max_val = max(ans.max_val, a.second);
	}
	for(auto a : R.m)
	{
		if(ans.m.find(a.first) != ans.m.end())
		{
			int v = ans.m[a.first];
			ans.m[a.first] = v + a.second;
			ans.max_val = max(ans.max_val, v + a.second);
		}
		else
		{
			ans.m[a.first] = a.second;
			ans.max_val = max(ans.max_val, a.second);
		}
	}
	return ans;
}

node query(node *root, int i, int j, int L, int R)
{
	if(L <= i and R >= j) return *root;
	if(j < L || i > R) return node();
	int mid = (i+j)/2;
	node left =  query(root->left, i, mid, L, R);
	node right = query(root->right, mid+1, j, L, R);
	return merge(left,right);
}

void build(node *root, int i, int j)
{
	if(i == j)
	{
		root->m[ar[i]] = 1;
		return;
	}
	root->left = new node;
	root->right = new node;
	int mid = (i+j)/2;
	build(root->left,i,mid);
	build(root->right,mid+1,j);
	node m = merge(*(root->left),*(root->right));
	
	root->max_val = m.max_val;
	for(auto e : m.m)
		root->m[e.first] = e.second;
}

int main()
{
	int t = readint();
	char yes[] = "yes", no[] = "no";
	while(t--)
	{
		int n = readint();
		for(int a=0;a<n;a++) ar[a] = readint();

		node *root = new node;
		build(root,0,n-1);
		int m = readint();
		while(m--)
		{
			int x = readint(), y = readint(), d = readint();
			x--; y--;
			node ans = query(root,0,n-1,x,y);
			writestr(ans.max_val > d ? yes : no);
			putchar('\n');
		}
	}
	flush();
	return 0;
}
