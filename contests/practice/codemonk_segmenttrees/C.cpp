#include <bits/stdc++.h>
using namespace std;

int ar[100001];
#define mod 1000000007
#define debug(x) printf(#x " = %d\n",x)

struct node
{
	node *left, *right;
	int max_size, count;
	node()
	{
		left = right = NULL;
		max_size = count = 0;
	}
};

inline node merge(node &L, node &R)
{
	node ans;
	ans.max_size = max(L.max_size, R.max_size);
	if(L.max_size != R.max_size)
		ans.count = L.max_size > R.max_size ? L.count : R.count;
	else
		ans.count = L.count + R.count;
	if(ans.count >= mod)
		ans.count %= mod;
	return ans;
}

node query(node *root, int i, int j, int L, int R)
{
	if(j < L || i > R) return node();
	if(L <= i and R >= j) return *root;
	int mid = (i+j)/2;
	node left =  query(root->left, i, mid, L,R);
	node right = query(root->right, mid+1, j, L,R);
	return merge(left,right);
}

void update(node *root, int i, int j, int pos, node &val)
{
	if(i == j)
	{
		if(val.max_size + 1 > root->max_size)
		{
			root->max_size = val.max_size + 1;
			root->count = val.count;
		}
		else if(val.max_size + 1 == root->max_size)
		{
			root->count += val.count;
			if(root->count >= mod) root->count %= mod;
		}
		return;
	}
	int mid = (i+j)/2;
	if(pos <= mid) update(root->left,i,mid,pos,val);
	else update(root->right,mid+1,j,pos,val);
	node res = merge(*(root->left),*(root->right));
	// copy res to *root
	root->max_size = res.max_size;
	root->count = res.count;
}

void build(node *root, int i, int j)
{
	if(i == j)
		return;
	root->left = new node;
	root->right = new node;
	int mid = (i+j)/2;
	build(root->left,i,mid);
	build(root->right,mid+1,j);
}

int main()
{
	int n; cin >> n;
	for(int a=0;a<n;a++) cin >> ar[a];
	node *root1 = new node(), *root2 = new node();
	int M = 100010;
	build(root1,0,M);
	build(root2,0,M);

	for(int a=0;a<n;a++)
	{
		node res;
		if(ar[a] > 0)
		{
			res = query(root2,0,M,0,ar[a]-1);
			if(res.max_size == 0)
				res.count = 1;
			update(root1,0,M,ar[a],res);
		}
		else
		{
			ar[a] *= -1;
			res = query(root1,0,M,0,ar[a]-1);
			if(res.max_size == 0)
				res.count = 1;
			update(root2,0,M,ar[a],res);
		}
	}
	/*
	debug(root1->max_size);
	debug(root1->count);
	debug(root2->max_size);
	debug(root2->count);
	*/

	node ans = merge(*root1, *root2);
	printf("%d %d\n",ans.max_size,ans.count);

	return 0;
}

