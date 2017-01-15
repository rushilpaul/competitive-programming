#include <cstdio>
#include <cstring>
using namespace std;

inline int sub(char *s, int len, int i)
{
	int n=0;
	for(int a=i;a<len;a++)
	{
		for(int b=0;;b++)
			if(s[a] == s[b]) n++;
			else return n;
	}
	return n;
}

int main()
{
	int len,n; scanf("%d %d", &len, &n);
	char s[len], D[n][len];
	int ar[len], sizes[n];
	memset(sizes, 0, n*sizeof(int));
	for(int a=0;a<n;a++)
	{
		gets(s);
		D[a][0] = s[0];
		ar[0] = len;
		int a=0;
		for(;a<sizes[0];a++) if(s[0] == D[a][0]) break;
		if(a == sizes[0]) D[a][sizes[0]++] = s[0];
		for(a=1;a<len;a++)
		{
			int r = sub(s,len,a);
			if(r > ar[a]) { ar[a] = r; D[a][0] = s[a]; sizes[a] = 0; }
			else if(r == ar[a])
			{
				int b=0;
				for(;b<sizes[a];b++) if(D[a][b] == s[a]) break;
				if(b == sizes[a]) D[a][sizes[a]++] = s[a];
			}
		}
		long ans = 1;
		for(int a=0;a<n;a++)
		{
			ans *= sizes[a];
			if(ans >= 10000007) ans %= 10000007;
		}
		printf("%ld\n",ans);
	}
	return 0;
}
