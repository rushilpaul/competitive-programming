#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

typedef long long LL;

int A[100001];

struct node
{
	int f2, f3, f5;
	node *left, *right;
	node()
	{
		left = right = NULL;
		f2 = f3 = f5 = 0;
	}
};

void prop(node *src, node *target)
{
	target->f2 += src->f2;
	target->f3 += src->f3;
	target->f5 += src->f5;
}

void clearNode(node *root) { root->f2 = root->f3 = root->f5 = 0; }

void query1(node *root, int x, int y, int l, int r, int p)		// Query range: [l,r], Segment range: [x,y]
{
	if(l <= x and r >= y)
	{
		if(p == 2)
			root->f2++;
		else if(p == 3)
			root->f3++;
		else if(p == 5)
			root->f5++;
		return;
	}
	else if(r < x or l > y)
		return;
	// overlap
	int mid = (x + y) / 2;
	query1(root->left, x, mid, l, r, p);
	query1(root->right, mid+1, y, l, r, p);
}

int values[100001][3];

void query2(node *root, int x, int y, int l, int r, int clear)		// Query range: [l,r], Segment range: [x,y]
{
	if(r < x or l > y)
		return;
	else if(x == y)
	{
		if(clear)
			root->f2 = root->f3 = root->f5 = 0;
		else
		{
			values[x][0] = root->f2;
			values[x][1] = root->f3;
			values[x][2] = root->f5;
		}
		return;
	}

	if(root->left)
		prop(root, root->left);
	if(root->right)
		prop(root, root->right);
	clearNode(root);
	
	int mid = (x + y) / 2;
	query2(root->left, x, mid, l, r, clear);
	query2(root->right, mid+1, y, l, r, clear);
}

node* init(int l, int r)
{
	node* root = new node();
	if(l == r)
		return root;
	int m = (l + r) / 2;
	root->left = init(l, m);
	root->right = init(m+1, r);
	return root;
}

int main()
{
	int n; scanf("%d",&n);
	for(int a=0;a<n;a++)
		scanf("%d", &A[a]);

	node *root = init(0, n-1);

	int m; scanf("%d", &m);
	while(m--)
	{
		int q; scanf("%d", &q);
		if(q == 1)
		{
			int l,r,p; scanf("%d %d %d", &l, &r, &p);
			query1(root, 0, n-1, l-1, r-1, p);
		}
		else
		{
			int l, d; scanf("%d %d", &l, &d);
			query2(root, 0, n-1, l-1, l-1, 1);
			A[l-1] = d;
		}
	}
	query2(root, 0, n-1, 0, n-1, 0);

	for(int a=0;a<n;a++)
	{
		while(values[a][0]-- and A[a] % 2 == 0)
			A[a] /= 2;
		while(values[a][1]-- and A[a] % 3 == 0)
			A[a] /= 3;
		while(values[a][2]-- and A[a] % 5 == 0)
			A[a] /= 5;
		printf("%d ", A[a]);
	}
	return 0;
}
