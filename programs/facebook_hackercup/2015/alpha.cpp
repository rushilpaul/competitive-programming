#include <cstdio>
#include <cstring>
using namespace std;

char s[1001];

int main()
{
	int t; scanf("%d\n",&t);
	for(int tt=1;tt<=t;tt++)
	{
		gets(s);
		int A[26],len = strlen(s);
		memset(A,0,26*sizeof(int));
		for(int a=0;a<len;a++) { if(s[a] != ' ') A[s[a]-65]++; }
		int ans=10000;
		char *h = "HACKERUP";
		for(int a=0;a<8;a++)
			if(h[a]=='C') { if(ans >= A[h[a]-65]/2) ans = A[h[a]-65]/2; }
			else { if(ans >= A[h[a]-65]) ans = A[h[a]-65]; }
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
