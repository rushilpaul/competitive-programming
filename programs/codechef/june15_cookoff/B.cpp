#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define EPS std::numeric_limits<LL>::epsilon()
#define max_buf_size 2048

char buf[max_buf_size], *_s = buf + max_buf_size;
inline char getc1(void)
{
    if(_s >= buf + max_buf_size)
    {
        fread(buf,1,max_buf_size,stdin);
        _s = buf;
    }
    return *(_s++);
}
inline int readint()
{
    char t = getc1();
    int n=1,res=0;
    while(t!='-' && !isdigit(t)) t=getc1();
    if(t=='-')
    {
        n=-1;
        t=getc1();
    }
    while(isdigit(t))
    {
        res = 10*res + (t&15);
        t=getc1();
    }
    return res*n;
}
inline LL readLL()
{
    char t = getc1();
    int n=1;
    LL res=0;
    while(t!='-' && !isdigit(t)) t=getc1();
    if(t=='-')
    {
        n=-1;
        t=getc1();
    }
    while(isdigit(t))
    {
        res = 10*res + (t&15);
        t=getc1();
    }
    return res*n;
}
inline char skipwhitespace()
{
    char ch = getc1();
    while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getc1();
    return ch;
}
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

inline char readchar()
{
    return skipwhitespace();
}

char outbuf[max_buf_size];
int outbuf_p;

inline void putc1(char ch)
{
    if(outbuf_p >= max_buf_size)
    {
        fwrite(outbuf,1,max_buf_size,stdout);
        outbuf_p = 0;
    }
    outbuf[outbuf_p++] = ch;
}

inline void flush()
{
    fwrite(outbuf,1,outbuf_p,stdout);
    outbuf_p = 0;
}

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

inline void writedouble(double d, int p)
{
    char buf[40];
    sprintf(buf,"%.*f",p,d);
    writestr(buf);
}

// END OF IO

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

int egcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
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

vector<int> getfactors(int n)
{
    vector<int> f;
    for(int a=2; a*a<=n; a++)
    {
        int p = 1;
        while(n % a == 0)
        {
            n /= a;
            p *= a;
        }
        if(p > 1) f.push_back(p);
    }
    return f;
}

inline int getbit(LL n, int i)
{
    return n & (1<<i);
}

char s[100010];

int main()
{
    int t = readint();
    while(t--)
    {
        int n = readstr(s);
        int k = readint();
        int c1=0,c2=0;
        vector<int> pos1, pos2;
        for(int a=0; a<n; a++)
        {
            if(s[a] == '(')
                pos1.push_back(a);
            else
                pos2.push_back(a);
        }
        if(pos1.size() != pos2.size())
        {
            if(k > 1) printf("-1\n");
            else printf("%s\n",s);
            continue;
        }
        stack<char> st;
        int flag = 0;
        for(int a=0; a<n; a++)
        {
            if(s[a] == '(')
                st.push(s[a]);
            else
            {
                if(st.size() == 0)
                {
                    flag = 1;
                    break;
                }
                st.pop();
            }
        }
        if(st.size() > 0)
            flag = 1;
        if(flag)
        {
            if(k > 1) printf("-1\n");
            else printf("%s\n",s);
            continue;
        }

        vector< pair<int,int> > R;
        int p = 0;
        s[n] = '#';
        for(int a=1; a<n+1; a++)
        {
            if(s[a] != s[p])
            {
                R.push_back( make_pair(p,a-1) );
                p = a;
            }
        }
        if(k > R.size())
        {
            printf("-1\n");
            continue;
        }

        //for(auto it : R) printf("%d %d\n",it.first,it.second);

        if(k <= R.size()/2)  	// 2
        {
            int sz = R.size();
            int i = 2*(k-1) + 1;
            assert(i >= 0 and i < sz);
            for(int a=0; a<sz; a++)
            {
                if(a == i)
                    R[a].second--;
                for(int b=R[a].first; b <= R[a].second; b++)
                    printf("%c",a % 2 ? ')' : '(');
            }
        }
        else  	// 1
        {
            int sz = R.size();
            k -= sz/2;
            int i = sz-1 - 2*(k-1) - 1;
            assert(i >= 0 and i < sz);
            //printf("k = %d, i = %d\n",k,i);
            for(int a=0; a<sz; a++)
            {
                if(a == i)
                    R[a].second--;
                for(int b=R[a].first; b <= R[a].second; b++)
                    printf("%c",a % 2 ? ')' : '(');
            }
        }
        printf("\n");
    }

    return 0;
}

