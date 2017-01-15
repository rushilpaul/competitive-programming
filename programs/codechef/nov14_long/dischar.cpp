#include <bits/stdc++.h>
using namespace std;
char s[100001];

int main()
{
	int t; scanf("%d\n",&t);	
	while(t--)
	{
		gets(s);
		int n = strlen(s);
		int f[26], ans=0;
		fill(f,f+26,0);
		for(int a=0;a<n;a++)
			f[s[a]-97]=1;
		for(int a=0;a<26;a++) if(f[a]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}