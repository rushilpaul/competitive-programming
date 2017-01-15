#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;

#define EPS (std::numeric_limits<double>::epsilon())
#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define sq(a) ((a)*(a))
#define PI 3.141592653589793238462643383279502884197

char _buf[max_buf_size];
int _bytes_read_ = max_buf_size-1;
char *_s = _buf + _bytes_read_;
inline char getc1() { if(_s >= _buf + _bytes_read_) { _bytes_read_ = fread(_buf,1,max_buf_size-1,stdin); _buf[_bytes_read_] = 0;  _s = _buf; } return *(_s++); }
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

inline string readstring(int n)
{
	char buf[n+1];
	readstr(buf);
	string s(buf);
	return s;
}

inline double readdouble()
{
	char buf[40];
	readstr(buf);
	double d;
	sscanf(buf,"%lf",&d);
	return d;
}

inline LD readLD()
{
	char buf[80];
	readstr(buf);
	LD d;
	sscanf(buf,"%Lf",&d);
	return d;
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



struct RangeMinimumQuery
{
    typedef int Key;
    typedef pair<int,int> Value;
    struct Node {
        Key key;
        Value value, sum;
        int pr;
        Node *ch[2];
        Node(Key key, Value value) :
            key(key), value(value), pr(rand()) {
            ch[0] = ch[1] = 0;
        }
    } *root;
    RangeMinimumQuery() : root(0) { }

    Value SUM(Node *n) {
        return n ? n->sum : Value(INT_MAX,INT_MIN);
    }
    Value PLUS(Value x, Value y) {
        return Value(min(x.first, y.first), max(x.second, y.second));
    }
    Node *update(Node *n) {
        if (n) n->sum = PLUS(n->value, PLUS(SUM(n->ch[0]), SUM(n->ch[1])));
        return n;
    }
    Node *rotate(Node *n, int b) {
        Node *m = n->ch[b];
        n->ch[b] = m->ch[!b];
        m->ch[!b] = update(n);
        return update(m);
    }
    Node *insert(Node *n, Key key, Value value) {
        if (!n) return update(new Node(key, value));
        int b = (n->key < key);
        n->ch[b] = insert(n->ch[b], key, value);
        return n->ch[b]->pr < n->pr ? rotate(n, b) : update(n);
    }
    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }
    Value rangeSum(Node *n, Key key) { // sum over n.key >= key
        if (!n) return SUM(n);
        if (n->key < key) return rangeSum(n->ch[1], key);
        return PLUS(rangeSum(n->ch[0], key), PLUS(n->value, SUM(n->ch[1])));
    }
};

int a[100010], s[100010], n, k;

bool possible(int m)
{
    pair<int,int> p;
    RangeMinimumQuery RMQ;
    RMQ.insert(0, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        p = RMQ.rangeSum(RMQ.root, s[i] - m);
        p.first += 1;
        p.second += 1;
        RMQ.insert(s[i], p);
    }
    return p.first <= k && k <= p.second;
}

int solve()
{
    int l = 0, r = INT_MAX;
    while (l+1 < r)
	{
        int m = (r + l) / 2;
        if (possible(m)) r = m;
        else l = m;
    }
    return r;
}

int main()
{
	int t; scanf("%d",&t);

    while (t--)
	{
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        s[0] = a[0];
        for (int i = 1; i < n; i++)
            s[i] = s[i-1] + a[i];
        printf("%d\n", solve());
    }
	return 0;
}

