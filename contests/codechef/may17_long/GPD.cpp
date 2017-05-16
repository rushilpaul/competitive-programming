#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
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
inline LL readint()
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

// END OF IO

double my_sqrt(double x, double delta = .00001)
{
    double g = x / 2, ng;
    while(fabs(g - (ng = (x / g + g) / 2)) > delta)
        g = ng;
    return g;
}

template<class T>
void print(vector<T> v)
{
	for(T i : v)
		cout << i << " ";
}

template<class T>
void fill(vector<T> v, T val = 0)
{
	fill(v.begin(),v.end(),val);
}

vector<string> split(string S, string D)
{
	vector<string> ar;
	int pos = 0, last = 0;
	while( (pos = S.find(D,last)) != string::npos)
	{
		string sub = S.substr(last,pos-last);
		if(sub.length() > 0)
			ar.push_back(sub);
		last = pos + D.length();
	}
	string sub = S.substr(last);
	if(sub.length() > 0)
		ar.push_back(sub);
	return ar;
}

inline LL pow(LL b, LL e)
{
	LL ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow(LL b, LL e, LL mod)
{
	LL ans=1;
	while(e)
	{
		if(e & 1)
			ans = ans * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return ans;
}

template<class T>
T egcd(T a, T b, T &x, T &y)
{
	if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    T x1, y1;
    T d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}
 
LL inv(LL a, LL m)
{
	LL inv,y;
	assert(egcd(a,m,inv,y) == 1);
	if(inv < 0) inv += m;
	return inv;
}

inline LL gcd(LL a, LL b)
{
	while(b)
	{
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}

struct trie
{
	trie *left, *right;

	trie()
	{
		left = right = NULL;
	}
};

struct node
{
	trie *trie_root;
	int id, val, depth;
	node()
	{
		depth = id = val = -1;
		trie_root = NULL;
	}
};

// print all elements of the trie
void print_trie(trie* root, int n, int level)
{
	if(!root) return;
	if(level == 31)
	{
		printf("Number: %d\n", n);
		return;
	}
	//printf("......number so far = %d, at level %d\n", n, level);
	print_trie(root->left, n * 2, level+1);
	print_trie(root->right, n * 2 + 1, level+1);
}

node *root;

// mapping of node ID to tree node
map<int, node*> treeMap;

// pos = 0 will return the least significant bit
int getBit(int n, int pos) { return (n & (1<<pos)) > 0; }

trie* updateTrie(int val, trie *from)
{
	//printf("inserting val = %d\n", val);
	trie *root = new trie();
	trie *cur_target = root, *cur_source = from;
	for(int pos = 30; pos >= 0; pos--)
	{
		int bit = getBit(val, pos);
		if(bit)
		{
			if(cur_target->right == NULL)
				cur_target->right = new trie();

			cur_target->left = cur_source ? cur_source->left : NULL;
			cur_target = cur_target->right;
			if(cur_source)
				cur_source = cur_source->right;
		}
		else
		{
			if(cur_target->left == NULL)
				cur_target->left = new trie();

			cur_target->right = cur_source ? cur_source->right : NULL;
			cur_target = cur_target->left;
			if(cur_source)
				cur_source = cur_source->left;
		}
	}
	return root;
}

// update the tree node v with a new child node
void update(int v, node* newnode)
{
	node *node_v = treeMap[v];
	// insert the new node as a child node of v
	// increase the depth of the new ndoe
	newnode->depth = node_v->depth + 1;
	// create a new trie and assign its root to the new node
	newnode->trie_root = updateTrie(newnode->val, node_v->trie_root);
}

// get max xor
int query(int val, trie* root, int findmax)
{
	trie *cur = root;
	int num = 0;
	int pos = 30;
	while(cur && pos >= 0)
	{
		if(getBit(val, pos))
		{
			if(findmax)
			{
				if(cur->left)
				{
					cur = cur->left;
					if(cur)
						num = num * 2;
				}
				else
				{
					cur = cur->right;
					if(cur)
						num = num * 2 + 1;
				}
			}
			else
			{
				if(cur->right)
				{
					cur = cur->right;
					if(cur)
						num = num * 2 + 1;
				}
				else
				{
					cur = cur->left;
					if(cur)
						num = num * 2;
				}
			}
		}
		else
		{
			if(findmax)
			{
				if(cur->right)
				{
					cur = cur->right;
					if(cur)
						num = num * 2 + 1;
				}
				else
				{
					cur = cur->left;
					if(cur)
						num = num * 2;
				}
			}
			else
			{
				if(cur->left)
				{
					cur = cur->left;
					if(cur)
						num = num * 2;
				}
				else
				{
					cur = cur->right;
					if(cur)
						num = num * 2 + 1;
				}

			}
		}
		pos--;
	}
	assert(pos == -1);
	return num;
}

int main()
{
	int n, q, rootID, rootVal; scanf("%d %d %d %d", &n, &q, &rootID, &rootVal);
	root = new node();
	root->depth = 0;
	root->id = rootID;
	root->val = rootVal;
	treeMap[rootID] = root;
	root->trie_root = updateTrie(root->val, NULL);

	rep(a,n-1)
	{
		int u,v,k; scanf("%d %d %d", &u, &v, &k);
		node *newnode = new node();
		newnode->id = u;
		newnode->val = k;
		treeMap[u] = newnode;
		update(v, newnode);
		//print_trie(newnode->trie_root, 0, 0);
		//printf("\n");
	}

	int last_ans = 0;
	while(q--)
	{
		int type, v; scanf("%d %d", &type, &v);
		type ^= last_ans;
		v ^= last_ans;

		if(type == 0)	// update
		{
			int u,k; scanf("%d %d", &u, &k);
			u ^= last_ans; k ^= last_ans;

			node *newnode = new node();
			newnode->id = u;
			newnode->val = k;
			treeMap[u] = newnode;
			update(v, newnode);
			//print_trie(newnode->trie_root, 0, 0);
			//printf("\n");
		}
		else
		{
			int k; scanf("%d", &k);
			k ^= last_ans;

			node *node_v = treeMap[v];
			int min_ans = k ^ query(k, node_v->trie_root, 0);
			int max_ans = k ^ query(k, node_v->trie_root, 1);
			printf("%d %d\n", min_ans, max_ans);
			last_ans = min_ans ^ max_ans;
		}
	}

	return 0;
}

