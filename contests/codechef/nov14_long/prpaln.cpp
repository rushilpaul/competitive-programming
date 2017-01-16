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
		setvbuf(stdout,NULL,_IOFBF,max_buf_size);
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
inline void read(char *s) { cin >> s; }

int palin(char *s, int n)
{
	for(int a=0;a<n/2;a++) if(s[a] != s[n-a-1]) return 0;
	return 1;
}

int main()
{
	int t; read(t);
	char s[1001];
	while(t--)
	{
		int n = readline(s,1002), flag = 0;
		for(int a=0;a<n/2;a++)
			if(s[a] != s[n-1-a])
			{
				if(!palin(s+a,n-2*a-1) && !palin(s+a+1,n-2*a-1))
					printf("NO\n");
				else
					printf("YES\n");
				flag = 1;
				break;
			}
		if(!flag)
			printf("YES\n");
	}
	return 0;
}
