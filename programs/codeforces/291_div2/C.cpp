#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

struct trie
{
	trie *a,*b,*c;
	char end;
	trie()
	{
		a = b = c = 0;
		end = 0;
	}
};

char s[1000001];

int f(trie *root, int i, int n, int flag)
{
	if(flag >= 2) return flag;
	if(i == n) return flag;
	if(!root and i != n) return 2;
	set<int> val;
	val.insert(2);
	for(int a=i;a<n and root;a++)
	{
		if(s[a] == 'a')
		{
			if(root->b)
				val.insert(f(root->b,a+1,n,flag+1));
			if(root->c)
				val.insert(f(root->c,a+1,n,flag+1));
			root = root->a;
		}
		else if(s[a] == 'b')
		{
			if(root->a)
				val.insert(f(root->a,a+1,n,flag+1));
			if(root->c)
				val.insert(f(root->c,a+1,n,flag+1));
			root = root->b;
		}
		else
		{
			if(root->a)
				val.insert(f(root->a,a+1,n,flag+1));
			if(root->b)
				val.insert(f(root->b,a+1,n,flag+1));
			root = root->c;
		}
	}
	int ans;
	if(root and root->end) ans = flag;
	else ans = *val.begin();
	return ans;
}

int main()
{
	int n,m;
	scanf("%d %d\n",&n,&m);
	trie *root = new trie;
	while(n--)
	{
		cin.getline(s,100000);
		int len = strlen(s);
		trie *start = root;
		for(int a=0;a<len;a++)
		{
			if(s[a] == 'a')
			{
				if(start->a == 0)
					start->a = new trie;
				start = start->a;
			}
			else if(s[a] == 'b')
			{
				if(start->b == 0)
					start->b = new trie;
				start = start->b;
			}
			else
			{
				if(start->c == 0)
					start->c = new trie;
				start = start->c;
			}
		}
		start->end = 1;
	}
	while(m--)
	{
		cin.getline(s,100000);
		int len = strlen(s);
		int r = f(root,0,len,0);
		//printf("r = %d\n",r);
		if(r == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

