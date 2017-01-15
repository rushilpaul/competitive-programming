//Program question at: http://code.google.com/codejam/contest/1460488/dashboard#s=p2
#include <cstdio>
#include <cstring>
using namespace std;

inline void inc(int* num, int& len )
{
	int i=6;
	while(num[i] == 9) num[i--]=0;
	if(i == 6-len) len++;
	num[i]++;
}

inline int form(int* D, int n, int c)
{
	int num=0,a;
	for(a=c+n;a<7;a++) num = num*10 + D[a];
	for(a=c;a<c+n;a++) num = num*10 + D[a];
	return num;
}

inline bool dup(int* ar, int len)
{
	if( !(len==4 || len==6) ) return 0;
	if(len == 6)
	{
		if( (ar[1] == ar[3] && ar[3] == ar[5]) && (ar[2] == ar[4] && ar[4] == ar[6]) ) return 1;
		if( ar[1] == ar[4] && ar[2] == ar[5] && ar[3] == ar[6] ) return 1;
	}
	else if(len == 4)
		if(ar[3] == ar[5] && ar[4] == ar[6]) return 1;
	return 0;
}

int main()
{
	int t; scanf("%d\n",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int A,B; scanf("%d %d",&A,&B);
		if(A < 12) A=12;
		if(A >= B) { printf("Case #%d: 0\n",cas); continue; }
		int D[7], len=0, ans=0, tmp = A, i=6;
		for(int a=0;a<7;a++) { D[a] = 0; if(tmp) len++; tmp/=10; }
		tmp = A;
		while(tmp) { D[i--] = tmp%10; tmp/=10; }	// initializing digits array

		for(;A<B;inc(D,len),A++)
		{
			bool d = dup(D,len); int crc=0; i=0;
			int perm[5]; bool *done = new bool[5]; memset(done,0,5);
			for(int n=1;n<len;n++)
			{
				if( !D[7-len+n] ) continue;
				int m = form(D,n,7-len);
				if( m > A && m <= B) { ans++; perm[i++] = m; }
			}
			if(!d) continue;
			for(int a=0;a<i-1;a++)
			{
				if(done[a]) continue;
				for(int b=a+1;b<i;b++) if(perm[a] == perm[b]) { done[b]=1; crc++; }
			}
			ans -= crc;
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
