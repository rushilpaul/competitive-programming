#include <cstdio>
typedef long long LL;

char s[100001];

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d", &n);
		scanf("%s", s);
		LL count = 0;
		for(int a=0;a<n;a++)
			if(s[a] == '1')
				count++;
		printf("%lld\n", count * (count + 1) / 2);
	}
	return 0;
}
