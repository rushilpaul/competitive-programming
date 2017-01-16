#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;
#define max_buf_size 1024

struct _init_
{
	_init_()
	{
		ios_base::sync_with_stdio(0); cin.tie(0);
		setvbuf(stdout,NULL,_IONBF,max_buf_size);
		setvbuf(stdin,NULL,_IOFBF,max_buf_size);
	}
} _init_ob_unused;

template<class T>
inline T read(T &n) { cin >> n; return n; }
template<class T1,class T2>
inline void read(T1 &n1, T2 &n2) { cin >> n1 >> n2; }
template<class T1,class T2,class T3>
inline void read(T1 &n1, T2 &n2, T3 &n3) { cin >> n1 >> n2 >> n3; }
template<class T1,class T2,class T3,class T4>
inline void read(T1 &n1, T2 &n2, T3 &n3, T4 &n4) { cin >> n1 >> n2 >> n3 >> n4; }
inline int readline(char *n, int len) { while(1) { cin.getline(n,len); int i = strlen(n); if(i) return i; } }
template<class T>
inline void read(T *ar, int n)
{
	for(int a=0;a<n;a++) cin >> ar[a];
}
inline int read(char *s) { cin >> s; return strlen(s); }
template<class T>
inline void print(char sep, T a) { assert(sep==' ' or sep=='\n'); cout << a << sep; }
template<class T1, class T2>
inline void print(char sep, T1 a, T2 b) { assert(sep==' ' or sep=='\n'); cout << a << sep << b << sep; }
template<class T1, class T2, class T3>
inline void print(char sep, T1 a, T2 b, T3 c) { assert(sep==' ' or sep=='\n'); cout << a << sep << b << sep << c << sep; }
template<class T>
inline void print(vector<T> v)
{
	int s = v.size();
	for(int a=0;a<s;a++) cout << v[a] << " ";
}


LL pow1(LL b, LL e, LL mod)
{
	if(e == 0) return 1;
	LL ans = pow1(b,e/2,mod);
	ans = (ans * ans) % mod;
	if(e&1) return (ans*b)%mod;
	else return ans;
}

inline LL pow(LL b, LL e, LL mod)	// mod should be prime
{
	if(e < 0)
		return pow1(pow1(b,-e,mod),mod-2,mod);
	else return pow1(b,e,mod);
}


LL egcd(LL a, LL b, LL& x, LL& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL d = egcd(b%a, a, x1, y1);
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

char s[100001];

int main()
{
	

	int t; read(t);
	int path[5][2] = { {0,5}, {1,6}, {2,7}, {3,8}, {4,9} };
	while(t--)
	{
		int n = read(s);
		pair<char,int> ar[n];
		int a = 0,k=0;
		for(int a=0;a<n;)
		{
			int count=1;
			char ch = s[a];
			while(a < n and s[a] == s[a+1]) { count++; a++; }
			ar[k++] = make_pair(ch,count);
			a++;
		}
		int start;
		if(k == 1) start = path[ar[0].first-65][0];
		else
		{
			int c1 = ar[0].first, c2 = ar[1].first;
			if(c1 == 'A') start = (c2 == 'B' || c2 == 'E' ? 0 : 5);
			else if(c1 == 'B') start = (c2 == 'A' or c2 == 'C' ? 1 : 6);
			else if(c1 == 'C') start = (c2 == 'B' or c2 == 'D' ? 2 : 7);
			else if(c1 == 'D') start = (c2 == 'C' or c2 == 'E' ? 3 : 8);
			else if(c1 == 'E') start = (c2 == 'A' or c2 == 'D' ? 4 : 9);
		}
		if(ar[0].second % 2 == 0) start = (start <= 4 ? start + 5 : start - 5);
		int ans[100001], ans_i = 0;
		for(int a=0;a<ar[0].second;a++)
		{
			ans[ans_i++] = path[ar[0].first-65][start >= 5];
			if(a != ar[0].second-1)
				start = ( start <= 4 ? start + 5 : start - 5 );
		}
		int flag = 1;
		for(int a=1;a<k-1;a++)
		{
			char c1 = ar[a].first, c2 = ar[a+1].first;
			//printf("c1 = %c, c2 = %c, start = %d\n",c1,c2,start);
			for(int b=0;b<ar[a].second;b++)
			{
				ans[ans_i++] = path[c1-65][start >= 5];
				if(b != ar[a].second-1)
					start = ( start <= 4 ? start + 5 : start - 5 );
			}
		    if( start<5 && c1 == 'A' && !(c2 == 'E' || c2 == 'B') ) { flag = 0; break; }
			if( (start>=5 && c1 == 'A' && (c2 == 'E' || c2 == 'B')) ) { flag = 0; break; }
			if( (start<5 && c1 == 'B' && !(c2 == 'A' || c2 == 'C')) ) { flag = 0;  break; }
			if( (start>=5 && c1 == 'B' && (c2 == 'A' || c2 == 'C')) ) { flag = 0;  break; }
			if( (start<5 && c1 == 'C' && !(c2 == 'B' || c2 == 'D')) ) { flag = 0;  break; }
			if( (start>=5 && c1 == 'C' && (c2 == 'B' || c2 == 'D')) ) { flag = 0;  break; }
			if( (start<5 && c1 == 'D' && !(c2 == 'C' || c2 == 'E')) ) { flag = 0;  break; }
			if( (start>=5 && c1 == 'D' && (c2 == 'C' || c2 == 'E')) ) { flag = 0; break; }
			if( (start<5 && c1 == 'E' && !(c2 == 'A' || c2 == 'D')) ) { flag = 0; break; }
			if( (start>=5 && c1 == 'E' && (c2 == 'A' || c2 == 'D')) ) { flag = 0; break; }
		}
		//printf("flag = %d\n",flag);
		if(k > 1)
		{
		/*
		start = ( start <= 4 ? start + 5 : start - 5 );
		char c1 = ar[k-2].first, c2 = ar[k-1].first;
			if( start<5 && c1 == 'A' && !(c2 == 'E' || c2 == 'B') ) { flag = 0; }
			if( (start>=5 && c1 == 'A' && (c2 == 'E' || c2 == 'B')) ) { flag = 0; }
			if( (start<5 && c1 == 'B' && !(c2 == 'A' || c2 == 'C')) ) { flag = 0;  }
			if( (start>=5 && c1 == 'B' && (c2 == 'A' || c2 == 'C')) ) { flag = 0;  }
			if( (start<5 && c1 == 'C' && !(c2 == 'B' || c2 == 'D')) ) { flag = 0;  }
			if( (start>=5 && c1 == 'C' && (c2 == 'B' || c2 == 'D')) ) { flag = 0;  }
			if( (start<5 && c1 == 'D' && !(c2 == 'C' || c2 == 'E')) ) { flag = 0;  }
			if( (start>=5 && c1 == 'D' && (c2 == 'C' || c2 == 'E')) ) { flag = 0; }
			if( (start<5 && c1 == 'E' && !(c2 == 'A' || c2 == 'D')) ) { flag = 0; }
			if( (start>=5 && c1 == 'E' && (c2 == 'A' || c2 == 'D')) ) { flag = 0; }
		*/
		for(int a=0;a<ar[k-1].second;a++)
		{
			ans[ans_i++] = path[ar[k-1].first-65][start >= 5];
			start = ( start <= 4 ? start + 5 : start - 5 );
		}
		}
		if(flag == 0) printf("-1");
		else
		for(int a=0;a<ans_i;a++) printf("%d",ans[a]);
		printf("\n");
	}
		
	return 0;
}

