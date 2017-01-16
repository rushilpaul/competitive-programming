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

class BigInt
{
    private:
        char *digits;
        int size;            // number of used bytes (digits)
        int capacity;        // size of digits
        int sign;            // -1, 0 or +1

    public:
        /** Creates a BigInt with initial value n and initial capacity cap **/
        BigInt( int n, int cap );

        /** Creates a BigInt with initial value n **/
        BigInt( int n );

        /** Creates a BigInt with initial value floor( d ) **/
        BigInt( long double d );

        /** Creates a BigInt with value 0 **/
        BigInt();

        /** Creates a BigInt by reading the value from a string **/
        BigInt( string s );

        /** Creates a BigInt by reading the value from a C string **/
        BigInt( const char s[] );

        /** Copy constructor **/
        BigInt( const BigInt &n );

        /** Assignment operators **/
        const BigInt &operator=( const BigInt &n );
        const BigInt &operator=( int n );

        /** Cleans up **/
        ~BigInt();

        /** Removes any leading zeros and adjusts the sign **/
        void normalize();

        /** Returns the sign of n: -1, 0 or 1 **/
        static int sig( int n );

        /** Returns the sign of n: -1, 0 or 1 **/
        static int sig( long double n );

        /** Returns the number of decimal digits **/
        inline int length() { return size; }

        /** Arithmetic **/
        BigInt operator++();
        BigInt operator++( int );
        BigInt operator--();
        BigInt operator--( int );
        BigInt operator-();
        BigInt operator+ ( int n    );
        BigInt operator+ ( BigInt n );
        BigInt&operator+=( int n    );
        BigInt&operator+=( BigInt n );
        BigInt operator- ( int n    );
        BigInt operator- ( BigInt n );
        BigInt&operator-=( int n    );
        BigInt&operator-=( BigInt n );
        BigInt operator* ( int n    );
        BigInt operator* ( BigInt n );
        void   operator*=( int n    );
        void   operator*=( BigInt n );
        BigInt operator/ ( int n    );
        BigInt operator/ ( BigInt n );
        void   operator/=( int n    );
        void   operator/=( BigInt n );
        int    operator% ( int n    );
        BigInt operator% ( BigInt n );
        void   operator%=( int n    );
        void   operator%=( BigInt n );
        int divide( int n );              // Divides storing quotient in *this and returning the remainder
        BigInt divide( BigInt n );        // Divides storing quotient in *this and returning the remainder
        BigInt operator* ( long double n ); // Multiplies by a double and truncates (always under-estimates!)
        void   operator*=( long double n ); // Multiplies by a double and truncates (always under-estimates!)

        /** Bitwise arithmetic **/
        BigInt operator<< ( int n    );
        void   operator<<=( int n    );
        BigInt operator>> ( int n    );   // Works differently for negative numbers
        void   operator>>=( int n    );   // Works differently for negative numbers
/*
        BigInt operator&  ( int n    );
        BigInt operator&  ( BigInt n );
        void   operator&= ( int n    );
        void   operator&= ( BigInt n );
        BigInt operator|  ( int n    );
        BigInt operator|  ( BigInt n );
        void   operator|= ( int n    );
        void   operator|= ( BigInt n );
        BigInt operator^  ( int n    );
        BigInt operator^  ( BigInt n );
        void   operator^= ( int n    );
        void   operator^= ( BigInt n );
        BigInt operator~();
*/
        /** Concatenation ;-) **/
        BigInt operator,( int n );
        BigInt operator,( BigInt n );

        /** Casting **/
        bool operator!();
        operator bool();
        //operator int();   //XXX: Don't do this!!! It takes precedence over operator+(int,BigInt)
        operator string();

        /** Comparison **/
        bool operator<( BigInt n );
        bool operator>( BigInt n );
        bool operator==( BigInt n );
        bool operator<=( BigInt n );
        bool operator>=( BigInt n );
        bool operator<( int n );
        bool operator>( int n );
        bool operator==( int n );
        bool operator<=( int n );
        bool operator>=( int n );
        int compare( BigInt n );

        /** Returns the lowest value as an integer (watch out for overflow) **/
        int toInt();

        /** Returns the value as a decimal string **/
        string toString();

        /** Outputs decimal value to stdout **/
        void print();

        /** Outputs the decimal value, with commas **/
        void printWithCommas( ostream &out );

    private:
        /** Expansion **/
        void grow();

    /** I/O Friends **/
    friend istream &operator>>( istream &in, BigInt &n );
    friend ostream &operator<<( ostream &out, BigInt n );
};

BigInt operator+( int m, BigInt &n )
{
    return n + m;
}

BigInt operator-( int m, BigInt &n )
{
    return -n + m;
}

BigInt operator*( int m, BigInt &n )
{
    return n * m;
}

BigInt operator/( int m, BigInt &n )
{
    return BigInt( m ) / n;
}

BigInt operator%( int m, BigInt &n )
{
    return BigInt( m ) % n;
}

/** Misc **/
inline bool isDigit( int c )
{
    return( c >= ( int )'0' && c <= ( int )'9' );
}

/** Input/Output **/
istream &operator>>( istream &in, BigInt &n )           // FIXME: see inside
{
    n.size = 0;
    n.sign = 1;
    int sign = 1;
    int c;
    while( ( c = in.peek() ) >= 0 &&
           ( c == ' ' || c == '\t' || c == '\r' || c == '\n' ) )
        in.get();
    if( c < 0 || ( c != ( int )'-' && !isDigit( c ) ) )
    {
        in >> c;                // XXX: force in.fail()
        return in;
    }
    if( c == ( int )'-' ) { sign = -1; in.get(); }

    // FIXME: Extremely inefficient! Use a string.
    while( ( c = in.peek() ) >= 0 && isDigit( c ) )
    {
        in.get();
        n *= 10;
        n += ( c - ( int )'0' );
    }
    n.sign = sign;      //XXX: assign n.sign directly after fixing the FIXME
    n.normalize();
    return in;
}

ostream &operator<<( ostream &out, BigInt n )       //FIXME: make more efficient
{
    return out << n.toString();
}

BigInt::BigInt( int n, int cap )
{
    cap = max( cap, ( int )sizeof( n ) * 8 );
    capacity = cap;
    sign = sig( n );
    n *= sign;
    digits = new char[cap];
    memset( digits, 0, cap );
    for( size = 0; n; size++ )
    {
        digits[size] = n % 10;
        n /= 10;
    }
}

BigInt::BigInt( int n )
{
    capacity = 1024;
    sign = sig( n );
    n *= sign;
    digits = new char[capacity];
    memset( digits, 0, capacity );
    size = 0;
    while( n )
    {
        digits[size++] = n % 10;
        n /= 10;
    }
}

BigInt::BigInt()
{
    capacity = 128;
    sign = 0;
    digits = new char[capacity];
    memset( digits, 0, capacity );
    size = 0;
}

BigInt::BigInt( string s )
{
    capacity = max( ( int )s.size(), 16 );
    sign = 0;
    digits = new char[capacity];
    memset( digits, 0, capacity );

    istringstream in( s );
    in >> ( *this );
}

BigInt::BigInt( const char s[] )
{
    capacity = max( ( int )strlen( s ), 16 );
    sign = 0;
    digits = new char[capacity];
    memset( digits, 0, capacity );

    istringstream in( s );
    in >> ( *this );
}

BigInt::BigInt( const BigInt &n )
{
    capacity = n.capacity;
    sign = n.sign;
    size = n.size;
    digits = new char[capacity];
    memcpy( digits, n.digits, capacity );
}

const BigInt &BigInt::operator=( const BigInt &n )
{
    if( &n != this )
    {
        if( capacity < n.size )
        {
            capacity = n.capacity;
            delete [] digits;
            digits = new char[capacity];
        }
        sign = n.sign;
        size = n.size;
        memcpy( digits, n.digits, size );
        memset( digits + size, 0, capacity - size );
    }
    return *this;
}

const BigInt &BigInt::operator=( int n )
{
    sign = sig( n );
    n *= sign;
    for( size = 0; n; size++ )
    {
        digits[size] = n % 10;
        n /= 10;
    }
    return *this;
}

BigInt::~BigInt()
{
    delete [] digits;
}

void BigInt::normalize()
{
    while( size && !digits[size-1] ) size--;
    if( !size ) sign = 0;
}

int BigInt::sig( int n )
{
    return( n > 0 ? 1 : ( n == 0 ? 0 : -1 ) );
}

int BigInt::sig( long double n )
{
    return( n > 0 ? 1 : ( n == 0 ? 0 : -1 ) );
}

int BigInt::toInt()
{
    int result = 0;
    for( int i = size - 1; i >= 0; i-- )
    {
        result *= 10;
        result += digits[i];
        if( result < 0 ) return sign * 0x7FFFFFFF;
    }
    return sign * result;
}

string BigInt::toString()
{
    string s = ( sign >= 0 ? "" : "-" );
    for( int i = size - 1; i >= 0; i-- )
        s += ( digits[i] + '0' );
    if( size == 0 ) s += '0';
    return s;
}

void BigInt::print()        //FIXME: make more efficient
{
    cout << toString();
}

void BigInt::printWithCommas( ostream &out )
{
    if( sign < 0 ) out.put( '-' );
    for( int i = size - 1; i >= 0; i-- )
    {
        out.put( digits[i] + '0' );
        if( !( i % 3 ) && i ) out.put( ',' );
    }
    if( size == 0 ) out.put( '0' );
}

void BigInt::grow()
{
    char *olddigits = digits;
    int oldCap = capacity;
    capacity *= 2;
    digits = new char[capacity];
    memcpy( digits, olddigits, oldCap );
    memset( digits + oldCap, 0, oldCap );
    delete [] olddigits;
}

BigInt BigInt::operator++()
{
    operator+=( 1 );
    return *this;
}

BigInt BigInt::operator++( int )
{
    return operator++();
}

BigInt BigInt::operator--()
{
    operator-=( 1 );
    return *this;
}

BigInt BigInt::operator--( int )
{
    return operator--();
}

BigInt BigInt::operator-()
{
    BigInt result( *this );
    result.sign *= -1;
    return result;
}

BigInt BigInt::operator+( int n )
{
    BigInt result( *this );
    result += n;
    return result;
}

BigInt BigInt::operator+( BigInt n )
{
    BigInt result( *this );
    result += n;
    return result;
}

BigInt &BigInt::operator+=( int n )
{
    if( size == capacity ) grow();

    int nsign = sig( n );
    if( !nsign ) return *this;
    if( !sign ) sign = nsign;
    if( sign == nsign )
    {
        n *= nsign;
        int carry = 0;
        int i;
        for( i = 0; n || carry; i++ )
        {
            int dig = n % 10;
            int newdig = digits[i] + dig + carry;
            digits[i] = newdig % 10;
            carry = newdig / 10;
            n /= 10;
        }
        size = max( i, size );
    }
    else operator-=( -n );
    return *this;
}

BigInt &BigInt::operator+=( BigInt n )
{
    int maxS = max( size, n.size ) + 1;
    while( maxS >= capacity ) grow();        //FIXME: this is stupid

    if( !n.sign ) return *this;
    if( !sign ) sign = n.sign;
    if( sign == n.sign )
    {
        int carry = 0;
        int i;
        for( i = 0; i < maxS - 1 || carry; i++ )
        {
            int newdig = carry;
            if( i < size ) newdig += digits[i];
            if( i < n.size ) newdig += n.digits[i];
            digits[i] = newdig % 10;
            carry = newdig / 10;
        }
        size = max( i, size );
    }
    else
    {
        n.sign *= -1;
        operator-=( n );
        n.sign *= -1;
    }
    return *this;
}

BigInt BigInt::operator-( int n )
{
    BigInt result( *this );
    result -= n;
    return result;
}

BigInt BigInt::operator-( BigInt n )
{
    BigInt result( *this );
    result -= n;
    return result;
}

BigInt &BigInt::operator-=( int n )
{
    if( size == capacity ) grow();

    int nsign = sig( n );
    if( !nsign ) return *this;
    if( !sign ) sign = 1;
    if( sign == nsign )
    {
        BigInt bin = n;
        if( sign >= 0 && *this < bin || sign < 0 && *this > bin )
        {
            // Subtracting a bigger number
            operator=( toInt() - n );
            return *this;
        }

        n *= nsign;
        int carry = 0;
        int i;
        for( i = 0; n || carry; i++ )
        {
            int dig = n % 10;
            int newdig = digits[i] - dig + carry;
            if( newdig < 0 ) newdig += 10, carry = -1;
            else carry = 0;
            digits[i] = newdig;
            n /= 10;
        }
        normalize();
    }
    else operator+=( -n );
    return *this;
}

BigInt &BigInt::operator-=( BigInt n )
{
    int maxS = max( size, n.size ) + 1;
    while( maxS >= capacity ) grow();        //FIXME: this is stupid

    if( !n.sign ) return *this;
    if( !sign ) sign = 1;
    if( sign == n.sign )
    {
        if( sign >= 0 && *this < n || sign < 0 && *this > n ) 
        {
            // Subtracting a bigger number
            BigInt tmp = n;
            tmp -= *this;
            *this = tmp;
            sign = -sign;
            return *this;
        }

        int carry = 0;
        int i;
        for( i = 0; i < maxS - 1; i++ )
        {
            int newdig = carry;
            if( i < size ) newdig += digits[i];
            if( i < n.size ) newdig -= n.digits[i];
            if( newdig < 0 ) newdig += 10, carry = -1;
            else carry = 0;
            digits[i] = newdig;
        }
        if( carry )     // Subtracted a bigger number, need to flip sign
        {
            if( i ) digits[0] = 10 - digits[0];
            size = ( i ? 1 : 0 );
            for( int j = 1; j < i; j++ )
            {
                digits[j] = 9 - digits[j];
                if( digits[i] ) size = j + 1;
            }
            sign *= -1;
        }
        normalize();
    }
    else
    {
        n.sign *= -1;
        operator+=( n );
        n.sign *= -1;
    }
    return *this;
}

BigInt BigInt::operator*( int n )
{
    BigInt result( 0, size + ( int )sizeof( n ) * 8 );
    int nsign = sig( n );
    n *= nsign;
    result.sign = sign * nsign;
    if( !result.sign ) return result;

    int i, j;
    for( i = 0; n; i++ )
    {
        int dig = n % 10;
        if( dig )
        {
            int carry = 0;
            for( j = 0; j < size || carry; j++ )
            {
                int newDig = result.digits[i + j] + ( j < size ? dig * digits[j] : 0 ) + carry;
                result.digits[i + j] = newDig % 10;
                carry = newDig / 10;
            }
        }
        n /= 10;
    }
    result.size = i + j - 1;
    return result;
}

BigInt BigInt::operator*( BigInt n )
{
    BigInt result( 0, size + n.size );

    result.sign = sign * n.sign;
    if( !result.sign ) return result;

    int i, j;
    for( i = 0; i < n.size; i++ )
    {
        if( n.digits[i] )
        {
            int carry = 0;
            for( j = 0; j < size || carry; j++ )
            {
                int newDig =
                    result.digits[i + j] +
                    ( j < size ? n.digits[i] * digits[j] : 0 ) +
                    carry;
                result.digits[i + j] = newDig % 10;
                carry = newDig / 10;
            }
        }
    }
    result.size = i + j - 1;

    return result;
}

void BigInt::operator*=( int n )
{
    operator=( operator*( n ) );
}

void BigInt::operator*=( BigInt n )
{
    operator=( operator*( n ) );
}

BigInt BigInt::operator/( int n )
{
    if( !n ) n /= n;        //XXX: force a crash

    BigInt result( *this );
    result /= n;
    return result;
}

BigInt BigInt::operator/( BigInt n )
{
    if( !n ) n.size /= n.size;       //XXX: force a crash

    BigInt result( *this );
    result /= n;
    return result;
}

void BigInt::operator/=( int n )
{
    divide( n );
}

void BigInt::operator/=( BigInt n )
{
    divide( n );
}

int BigInt::operator%( int n )
{
    BigInt tmp( *this );
    return tmp.divide( n );
}

void BigInt::operator%=( int n )
{
    operator=( divide( n ) );
}

BigInt BigInt::operator%( BigInt n )
{
    BigInt tmp( *this );
    return tmp.divide( n );
}

void BigInt::operator%=( BigInt n )
{
    operator=( divide( n ) );
}

int BigInt::divide( int n )
{
    if( !n ) n /= n;        //XXX: force a crash

    int nsign = sig( n );
    n *= nsign;
    if( !sign ) return 0;
    sign *= nsign;

    int tmp = 0;
    for( int i = size - 1; i >= 0; i-- )
    {
        tmp *= 10;
        tmp += digits[i];
        digits[i] = tmp / n;
        tmp -= digits[i] * n;
    }
    normalize();
    return tmp;
}

BigInt BigInt::divide( BigInt n )
{
    if( !n ) n.size /= n.size;         //XXX: force a crash

    if( !sign ) return 0;
    sign *= n.sign;

    int oldSign = n.sign;
    n.sign = 1;

    BigInt tmp( 0, size );
    for( int i = size - 1; i >= 0; i-- )
    {
        tmp *= 10;
        tmp += digits[i];
        digits[i] = 0;
        while( tmp >= n ) { tmp -= n; digits[i]++; }
    }
    normalize();
    n.sign = oldSign;
    return tmp;
}

// This is only exact to the first 15 or so digits, but it is
// never an over-estimate
BigInt BigInt::operator*( long double n )
{
    // the number of digits after the decimal point to use
    int DIGS_AFTER_DOT = 15;

    int nsign = sig( n );
    n *= nsign;
    int ndigs = n >= 1 ? ( int )log10( n ) + 1 : 0;
    BigInt result( 0, size + ndigs );
    result.sign = sign * nsign;
    if( !result.sign ) return result;

    if( n >= 1 ) for( int i = 0; i < ndigs; i++ ) n /= 10;
    result.size = 0;

    char afterDot[DIGS_AFTER_DOT + 1];
    memset( afterDot, 0, sizeof( afterDot ) );

    // Keep going until the DIGS_AFTER_DOT'th digit after the decimal point
    for( int i = ndigs - 1; i >= -DIGS_AFTER_DOT; i-- )
    {
        n *= 10;
        int dig = ( int )floor( n );
        n -= dig;
        if( !dig ) continue;

        int carry = 0;
        for( int j = 0; j < size || carry; j++ )
        {
            int newdig =
                ( i + j < 0 ? afterDot[-( i + j )] : result.digits[i + j] )
                + dig * digits[j]
                + carry;
            ( i + j < 0 ? afterDot[-( i + j )] : result.digits[i + j] ) = newdig % 10;
            if( i + j >= 0 && result.digits[i + j] ) result.size = i + j + 1;
            carry = newdig / 10;
        }
    }
    if( !result.size ) result.sign = 0;
    return result;
}

void BigInt::operator*=( long double n )
{
    operator=( operator*( n ) );
}

BigInt BigInt::operator<<( int n )
{
    BigInt result( *this );
    result <<= n;
    return result;
}

void BigInt::operator<<=( int n )
{
    if( n < 0 ) operator>>=( -n );
    else if( n > 0 )
    {
        BigInt mult( 1, 4 * n );
        for( int i = ( 1 << 30 ); i; i >>= 1 )
        {
            mult *= mult;
            if( n & i ) mult *= 2;
        }
        operator*=( mult );
    }
}

BigInt BigInt::operator>>( int n )
{
    BigInt result( *this );
    result >>= n;
    return result;
}

void BigInt::operator>>=( int n )
{
    if( n < 0 ) operator<<=( -n );
    else if( n > 0 )
    {
        BigInt mult( 1, 4 * n );
        for( int i = ( 1 << 30 ); i; i >>= 1 )
        {
            mult *= mult;
            if( n & i ) mult *= 2;
        }
        operator/=( mult );
    }
}

BigInt BigInt::operator,( int n )
{
    BigInt result( 0, size + ( int )sizeof( n ) * 8 );
    for( result.size = 0; n; result.size++ )
    {
        result.digits[result.size] = n % 10;
        n /= 10;
    }
    memcpy( result.digits + result.size, digits, size * sizeof( digits[0] ) );
    result.size += size;
    result.sign = 1;
    result.normalize();
    return result;
}

BigInt BigInt::operator,( BigInt n )
{
    BigInt result( 0, size + n.size );
    memcpy( result.digits, n.digits, n.size * sizeof( n.digits[0] ) );
    memcpy( result.digits + n.size, digits, size * sizeof( digits[0] ) );
    result.size = size + n.size;
    result.sign = 1;
    result.normalize();
    return result;
}

bool BigInt::operator!()
{
    return !size;
}

BigInt::operator bool()
{
    return size;
}

BigInt::operator string()
{
    return toString();
}

bool BigInt::operator<( BigInt n )
{
    return( compare( n ) < 0 );
}

bool BigInt::operator>( BigInt n )
{
    return( compare( n ) > 0 );
}

bool BigInt::operator==( BigInt n )
{
    return( compare( n ) == 0 );
}

bool BigInt::operator<=( BigInt n )
{
    return( compare( n ) <= 0 );
}

bool BigInt::operator>=( BigInt n )
{
    return( compare( n ) >= 0 );
}

bool BigInt::operator<( int n )
{
    return( compare( BigInt( n ) ) < 0 );
}

bool BigInt::operator>( int n )
{
    return( compare( BigInt( n ) ) > 0 );
}

bool BigInt::operator==( int n )
{
    return( compare( BigInt( n ) ) == 0 );
}

bool BigInt::operator<=( int n )
{
    return( compare( BigInt( n ) ) <= 0 );
}

bool BigInt::operator>=( int n )
{
    return( compare( BigInt( n ) ) >= 0 );
}

int BigInt::compare( BigInt n )
{
    if( sign < n.sign ) return -1;
    if( sign > n.sign ) return 1;
    if( size < n.size ) return -sign;
    if( size > n.size ) return sign;
    for( int i = size - 1; i >= 0; i-- )
    {
        if( digits[i] < n.digits[i] ) return -sign;
        else if( digits[i] > n.digits[i] ) return sign;
    }
    return 0;
}

char s[100001];

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readstr(s);
		rep(a,n) s[a] -= 48;
		BigInt A(s);
		n = readstr(s);
		rep(a,n) s[a] -= 48;
		BigInt B(s);
		cout << A << endl;
		cout << B << endl;
		auto C = A / B;
		cout << C;
	}
	return 0;
}

