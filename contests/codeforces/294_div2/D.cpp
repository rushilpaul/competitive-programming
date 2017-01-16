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

inline void flush() { fwrite(outbuf,1,outbuf_p,stdout); }

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

struct node
{
	node *left, *right;
	node()
	{
		left = right = NULL;
	}
};

inline node merge(node &L, node &R)
{
	node ans;	
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
		return;
	}
	root->left = new node;
	root->right = new node;
	int mid = (i+j)/2;
	build(root->left,i,mid);
	build(root->right,mid+1,j);
	node m = merge(*(root->left),*(root->right));
	// copy m to *root
}

char s[100001];
int ar[26];
LL C[100001];
vector<int> pos[26];

int main()
{
	for(int a=0;a<26;a++) scanf("%d",ar+a);
	scanf("%s",s);
	int n = strlen(s);
	for(int a=0;a<n;a++)
		C[a] = ar[s[a]-97];
	for(int a=1;a<=n;a++)
		C[a] += C[a-1];
	
	for(int a=0;a<n;a++)
	{
		pos[s[a]-97].push_back(a);
	}
	LL ans=0;
	for(int a=0;a<26;a++)
	{
		int size = pos[a].size();
		if(size == 0) continue;
		LL tmp[size-1];
		for(int i=0;i<size-1;i++)
		{
			tmp[i] = C[pos[a][i+1]-1] - C[pos[a][i]];
		}
		for(int i=1;i<size-1;i++)
			tmp[i] += tmp[i-1];

		for(int i=0;i<size-1;i++)
			printf("%lld ",tmp[i]);
		printf("\n");

		map<LL,int> m;
		for(int i=0;i<size-1;i++)
			m[tmp[i]] = m[tmp[i]] + 1;
		for(auto q : m)
		{
			//printf("%lld %d\n",q.first,q.second);
			int num = q.second;
			if(q.first == 0)
				ans += (LL)num * (num + 1)/2;
			else
				ans += (LL)num * (num - 1)/2;
		}
	}
	cout << ans;
	return 0;
}

/*
x a b c a b

a  a  a
1  1  1
1  2  3

 0   0


*/


