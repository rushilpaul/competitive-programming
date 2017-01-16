#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 1024
char s[100001];
int n;

struct node
{
	int sum;
	int rem[3];
	node *left, *right;
	node() { sum = rem[0] = rem[1] = rem[2] = 0; left = right = NULL; }
};

node merge(node L, node R)
{
	node ans;
	ans.sum = (L.sum + R.sum) % 3;
	for(int a=0;a<3;a++)
	{
		ans.rem[a] += L.rem[a];
		ans.rem[(a + L.sum) % 3] += R.rem[a];
	}
	return ans;
}

node query(node *root, int i, int j, int L, int R)
{
	if(L <= i and R >= j) return *root;
	if(j < L || i > R) return node();
	if(i == j)
	{
		return *root;
	}
	int mid = (i+j)/2;
	node left =  query(root->left, i, mid, L, R);
	node right = query(root->right, mid+1, j, L, R);
	return merge(left,right);
}

void update(node *root, int i, int j, int pos, int num)
{
	if(i == j)
	{
		root->sum = num % 3;
		for(int a=0;a<3;a++) root->rem[a] = 0;
		root->rem[root->sum] = 1;
		return;
	}
	int mid = (i+j)/2;
	if(pos <= mid) update(root->left,i,mid,pos,num);
	else update(root->right,mid+1,j,pos,num);
	node res = merge(*(root->left),*(root->right));
	root->sum = res.sum;
	for(int a=0;a<3;a++) root->rem[a] = res.rem[a];
}

void build(node *root, int i, int j)
{
	if(i == j)
	{
		root->sum = s[i] % 3;
		root->rem[root->sum] = 1;
		return;
	}
	root->left = new node;
	root->right = new node;
	int mid = (i+j)/2;
	build(root->left,i,mid);
	build(root->right,mid+1,j);
	node m = merge(*(root->left),*(root->right));
	root->sum = m.sum;
	for(int a=0;a<3;a++) root->rem[a] = m.rem[a];
	//printf("i,j: %d,%d; sum = %d; %d %d %d\n",i,j,root->sum,root->rem[0],root->rem[1],root->rem[2]);
}

inline LL f(LL n) { return n*(n-1)/2; }

inline LL count(node &root)
{
	return f(root.rem[0]+1) + f(root.rem[1]) + f(root.rem[2]);
}

int main()
{
	setvbuf(stdout,NULL,_IOFBF,max_buf_size);
	int m; scanf("%d %d\n",&n,&m);
	gets(s);
	for(int a=0;a<n;a++) s[a] -= 48;
	
	node *root = new node;
	build(root,0,n-1);
	
	while(m--)
	{
		int op,x,y; scanf("%d %d %d",&op,&x,&y); x--;
		if(op == 1)
			update(root,0,n-1,x,y);
		else
		{
			y--;
			node ans = query(root,0,n-1,x,y);
			printf("%lld\n",count(ans));
		}
	}
}
