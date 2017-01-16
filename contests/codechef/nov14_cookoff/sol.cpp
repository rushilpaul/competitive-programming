#include <bits/stdc++.h>
typedef long long LL;
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

char s[100001];

int f(int i, char c2)
{
	char c1 = i < 5 ? 'A' + i : 'A' + i-5;
	if(i < 5)
	{
		if(c1 == c2) return i+5;
		int prev = c1-'A'-1, next = (c1-'A'+1) % 5;
		if(prev < 0) prev += 5;
		if(c2-'A' == prev) return prev;
		else if(c2-'A' == next) return next;
		else return -1;
	}
	else
	{
		if(c1 == c2) return i-5;
		int prev = (c1-'A'+2) % 5, next = (c1-'A'+3) % 5;
		if(c2-'A' == prev) return prev+5;
		else if(c2-'A' == next) return next+5;
		else return -1;
	}
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		int n = strlen(s);
		int ans[100000],flag=1;
		int start = s[0]-'A';
		for(int a=0;a<n-1;a++)
		{
			ans[a] = start;
			start = f(start,s[a+1]);
			if(start == -1) { flag = 0; break; }
		}
		ans[n-1] = start;
		if(flag == 0)
		{
			flag = 1;
			int start = s[0]-'A'+5;
			for(int a=0;a<n-1;a++)
			{
				ans[a] = start;
				start = f(start,s[a+1]);
				if(start == -1) { flag = 0; break; }	
			}
			ans[n-1] = start;
		}
		if(flag == 0) printf("-1\n");
		else for(int a=0;a<n;a++) printf("%d",ans[a]);
		printf("\n");
	}
	return 0;
}
