#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 2048
 
char buf[max_buf_size];
int _bytes_read_ = max_buf_size-1;
char *_s = buf + _bytes_read_;
inline char getc1() { if(_s >= buf + _bytes_read_) { _bytes_read_ = fread(buf,1,max_buf_size-1,stdin); buf[_bytes_read_] = 0;  _s = buf; } return *(_s++); }
inline int readint()
{
	char t=getc1(); int n=1,res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{ n=-1; t=getc1(); }
	while(isdigit(t))
	{ res = 10*res + (t&15); t=getc1(); }
	return res*n;
}
inline LL readLL()
{
	char t=getc1(); int n=1; LL res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{ n=-1; t=getc1(); }
	while(isdigit(t))
	{ res = (LL)10*res + (t&15); t=getc1(); }
	return res*n;
}
inline char skipwhitespace() { char ch = getc1(); while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getc1(); return ch; }
inline int readline(char *s)
{
	char ch=skipwhitespace();
	int n=0;
	while( (ch != '\n' && ch != 0) )
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
	while( (ch != '\n' && ch != ' ' && ch != '\t' && ch != 0) )
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
 
struct node
{
	node *left, *right;
	int val;
	node()
	{
		val = INT_MAX;
		left = right = NULL;
	}
};
 
int query(node *root, int i, int j, int p)
{
	if(p < i or p > j) return INT_MAX;
	if(i == j) return root->val;
	int mid = (i+j)/2;
	return min(root->val, min(query(root->left, i, mid, p), query(root->right, mid+1, j, p)));
}
 
void update(node *root, int i, int j, int L, int R, int v)
{
	if(R < i or L > j) return;
	if(L <= i and R >= j)
	{
		root->val = min(root->val,v);
		return;
	}
	int mid = (i+j)/2;
	update(root->left,i,mid,L,R,v);
	update(root->right,mid+1,j,L,R,v);
}
 
void build(node *root, int i, int j)
{
	if(i == j)
		return;
	root->left = new node;
	root->right = new node;
	int mid = (i+j)/2;
	build(root->left,i,mid);
	build(root->right,mid+1,j);
}

void destroy(node *root, int i, int j)
{
	if(i == j) return;
	int mid = (i+j)/2;
	destroy(root->left,i,mid);
	free(root->left);
	destroy(root->right,mid+1,j);
	free(root->right);
}

LL dp[100001][501], ar[100000];
vector< pair<int,int> > sack;
 
/*LL f(int i, int money)
{
	if(i < 0 || money == 0)
		return 0;
	if(i == 0 and money >= sack[0].second)
		return sack[0].first;
	else if(i == 0 and money < sack[0].second)
		return 0;
	LL &ret = dp[i][money];
	if(ret != -1) return ret;
	LL ans = f(i-1,money);
	if(money >= sack[i].second)
		ans = max(ans, sack[i].first + f(i-1, money-sack[i].second));
	return ret = ans;
}*/

LL f(int n, int money)
{
	static clock_t total = 0;
	clock_t dur = clock();
	for(int a=0;a<n;a++)
		dp[a][0] = 0;
	for(int b=0;b<=money;b++)
		dp[0][b] = b >= sack[0].second ? sack[0].first : 0;

	for(int a=1;a<n;a++)
		for(int b=1;b<=money;b++)
		{
			dp[a][b] = dp[a-1][b];
			if(b >= sack[a].second)
			{
				LL tmp = sack[a].first + dp[a-1][b-sack[a].second];
				if(tmp > dp[a][b])
					dp[a][b] = tmp;
			}
		}
	dur = clock() - dur;
	total += dur;
	//fprintf(stderr,"knapsack: %.2f\n",(double)total/CLOCKS_PER_SEC);
	return dp[n-1][money];
}

int main()
{
	clock_t dur = clock(), dur2, total=0;
	int t = readint();
	while(t--)
	{
		int n = readint(), k = readint(), m = readint();
		dur2 = clock();
		node *root = new node;
		build(root,0,n-1);
		LL sum=0;
		for(int a=0;a<n;a++)
		{
			ar[a] = readint();
			sum += ar[a];
		}
		for(int a=0;a<m;a++)
		{
			int L = readint(), R = readint(), C = readint();
			update(root,0,n-1,L-1,R-1,C);
		}
		sack.clear();
		for(int a=0;a<n;a++)
			if(ar[a] < 0)
				sack.push_back( { -ar[a], query(root,0,n-1,a) } );
		dur2 = clock() - dur2;
		total += dur2;
		int size = sack.size();
		printf("%lld\n",sum+f(size,k));
		//destroy(root,0,n-1);
	}
	dur = clock() - dur;
	//fprintf(stderr,"segtree: %.2f\n",(double)total/CLOCKS_PER_SEC);
	//fprintf(stderr,"total: %.2f\n",(double)dur/CLOCKS_PER_SEC);
	return 0;
}

