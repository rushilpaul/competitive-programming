#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

template<class T>
T read(T &n) { cin >> n; return n; }
template<class T1,class T2>
void read(T1 &n1, T2 &n2) { cin >> n1 >> n2; }
template<class T1,class T2,class T3>
void read(T1 &n1, T2 &n2, T3 &n3) { cin >> n1 >> n2 >> n3; }
template<class T1,class T2,class T3,class T4>
void read(T1 &n1, T2 &n2, T3 &n3, T4 &n4) { cin >> n1 >> n2 >> n3 >> n4; }
template<class T>
void read(T *ar, int n)
{
	for(int a=0;a<n;a++) cin >> ar[a];
}

#define max_buf_size 2048
char _out_buf_[max_buf_size];

struct _init_
{
	_init_() { setvbuf(stdout,_out_buf_,_IOFBF,max_buf_size); ios_base::sync_with_stdio(0); cin.tie(0); }
} _init_ob_unused;

int main()
{
	int n,e,m; read(n,e,m);
	printf("%d\n",pow(n,e));
	return 0;
}
