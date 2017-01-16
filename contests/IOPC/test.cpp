#include <iostream>
#include <cstdio>
using namespace std;

#define abs(x) x<0 ? (-x):x
#define max(x,y) x>y ? x : y

const int _maxio=1000000;
char _buf[_maxio], *_s=_buf+_maxio;
inline char _getc(void)
{
    if(_s>=_buf+_maxio)
	{
        fread(_buf,sizeof(char),_maxio,stdin);
        _s=_buf;
    }
    return *(_s++);
}
inline int input(void)
{
    char _t=_getc();
    int _n=1,_res=0;
    while(_t!='-' && !isdigit(_t)) _t=_getc();
    if(_t=='-') {
        _n=-1;
        _t=_getc();
    }
    while(isdigit(_t))
	{
        _res = 10*_res + (_t&15);
        _t=_getc();
    }
    return _res*_n;
}

int main()
{
    int t = input();
    cout << t << endl;
    return 0;
}
