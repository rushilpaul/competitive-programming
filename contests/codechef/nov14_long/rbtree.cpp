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

inline int countbits(int n)
{
	int ans = 0;
	while(n)
	{
		n >>= 1;
		ans++;
	}
	return ans;
}

int main()
{
	int t; scanf("%d",&t);
	char s[4];
	char root = 'B';
	while(t--)
	{
		int x,y;
		scanf("%s",s);
		if(s[1] == 'i')
		{
			root = root=='B' ? 'R' : 'B';
			continue;
		}
		scanf("%d %d",&x,&y);
		if(x > y) swap(x,y);
		int bitx = countbits(x), bity = countbits(y);
		int x_len=0, y_len=0;
		while(bity != bitx)
		{
			y >>= 1;
			bity--;
			y_len++;
		}
		while(x != y)
		{
			x >>= 1;
			y >>= 1;
			x_len++;
			y_len++;
		}
		bitx--;
		bool isred = false;
		if(root == 'B' && bitx % 2) isred = true;
		else if(root == 'B' && bitx % 2 == 0) isred = false;
		else if(root == 'R' && bitx % 2 == 0) isred = true;
		int ans = x_len + y_len + 1;
		if(ans&1)
		{
			ans >>= 1;
			if((s[1] == 'b' && !isred) || (s[1] == 'r' && isred)) ans++;
		}
		else ans >>= 1;
		printf("%d\n",ans);
	}
	return 0;
}
