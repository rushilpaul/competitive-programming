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

struct cyclist
{
	LL dist, time, speed;
	cyclist() { dist = time = speed = 0; }
};

map< pair<LL,LL>, LD > v;
map< LD, pair<LL,LL> > leftp;

pair<LL,LL> getline(cyclist ar[], int i)
{
	return { ar[i].speed, ar[i].dist - ar[i].time * ar[i].speed };
}

LD point(pair<LL,LL> a, pair<LL,LL> b)
{
	return (a.second - b.second) / (LD)(b.first - a.first);
}

void printv()
{
	for(auto e : v) printf("%lld, %lld: left: %Lf\n",e.first.first,e.first.second,e.second);
	printf("\n");
}

void printleft()
{
	for(auto e : leftp) printf("Left: %Lf; %lld, %lld\n",e.first,e.second.first,e.second.second);
	printf("\n");
}

int main()
{
	int n = readint(), t = readint();
	cyclist ar[n];

	while(t--)
	{
		int q = readint();
		//printv();
		//printleft();
		//printf("\n");
		int debug = 0;

		if(q == 1)
		{
			LL time = readint(), i = readint() - 1, speed = readint();
			LL dist = ar[i].dist + (time - ar[i].time) * ar[i].speed;
			if(speed == ar[i].speed) continue;
			int newline = ar[i].time == 0 and ar[i].speed == 0;
			ar[i].time = time;
			ar[i].speed = speed;
			ar[i].dist = dist;

			pair<LL,LL> cur;
			if(v.size() == 0)
			{
				cur = {speed, -time * speed};
				v[cur] = time;
				leftp[time] = cur;
				continue;
			}

			if(newline)
			{
				cur = {speed, -time * speed};
				if(speed > v.rbegin()->first.first)
				{
					while(v.size() >= 2)	// L1, L2, cur
					{
						auto L2 = v.end(); L2--;
						auto L1 = L2; L1--;
						if(point(L1->first,cur) > point(L1->first,L2->first)) break;
						leftp.erase(L2->second);
						v.erase(L2);
					}
					auto last = v.rbegin();
					LD x = point(last->first, cur);
					leftp[x] = cur;
					v[cur] = x;
				}
				continue;
			}

			cur = getline(ar,i);

			if(v.find(cur) != v.end()) continue;	// duplicate
			v[cur] = 0;
			auto last = v.end(); last--;
			auto middle = v.find(cur);

			if(middle == last)
			{
				while(v.size() >= 3)	// tlast, slast, last
				{
					auto slast = last; slast--;
					auto tlast = slast; tlast--;
					if(point(tlast->first, last->first) > point(tlast->first, slast->first)) break;
					
					if(debug)
					{
						printf("xxxxxxxxxx %Lf\n",point(tlast->first, slast->first));
						printf("speed slast: %lld\n",slast->first.first);
					}

					leftp.erase(point(tlast->first, slast->first));
					v.erase(slast);
				}
				auto slast = last; slast--;
				LD x = point(last->first, slast->first);
				leftp[x] = cur;
				v[cur] = x;
				continue;
			}
			else	// check for same slope
			{
				auto after = middle; after++;
				if(after->first.first == middle->first.first)
				{
					v.erase(middle); continue;
				}
			}

			auto prev = middle, next = middle;
			prev--; next++;		// L1, cur, L2
			if(point(prev->first,next->first) <= point(prev->first,middle->first))
			{
				v.erase(middle);
				continue;
			}
			leftp[point(middle->first, next->first)] = next->first;

			leftp.erase(next->second);
			LD x = point(middle->first, next->first);
			leftp[x] = next->first;
			v[next->first] = x;

			// middle, L1, L2
			while(1)
			{
				auto L1 = middle; L1++;
				if(L1 == v.end()) break;
				auto L2 = L1; L2++;
				if(L2 == v.end()) break;
				if(point(middle->first, L2->first) > point(middle->first, L1->first)) break;
				leftp.erase(L1->second);
				leftp.erase(point(L1->first,L2->first));
				v.erase(L1);
			}
			next = middle; next++;
			assert(next != v.end());
			x = point(middle->first, next->first);
			leftp[x] = next->first;
			v[next->first] = x;
			

			// L1, L2, middle
			while(middle != v.begin())
			{
				auto L2 = middle; L2--;
				if(L2 == v.begin()) break;
				auto L1 = L2; L1--;
				if(point(L1->first, middle->first) > point(L1->first, L2->first)) break;
				leftp.erase(L2->second);
				v.erase(L2);
			}

			prev = middle; prev--;
			x = point(middle->first, prev->first);
			leftp[x] = cur;
			v[cur] = x;
		}
		else
		{
			LL time = readint();
				
			if(v.size() == 0) { printf("0\n"); continue; }
			if(v.size() == 1)
			{
				printf("%lld\n",v.begin()->first.first * time + v.begin()->first.second);
				continue;
			}
			auto it = leftp.lower_bound(time);
			if(it->first != time) it--;
			printf("%lld\n",it->second.first * time + it->second.second);
		}
	}
	return 0;
}

