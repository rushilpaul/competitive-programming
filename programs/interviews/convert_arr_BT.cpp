// convert sorted array to binary search tree
#include <cstdio>

struct node
{
	node *L,*R;
	int data;
	node() { L = R = NULL; }
};

node* f(int l, int r, int *ar)
{
	if(l > r) return NULL;
	node* root = new node;
	if(l == r)
	{
		root->data = ar[l];
		return root;
	}
	int mid = (l+r)/2;
	root->data = ar[mid];
	root->L = f(l,mid-1,ar);
	root->R = f(mid+1,r,ar);
	return root;
}

void print(node *root)
{
	if(root == NULL) return;
	print(root->L);
	printf("%d ",root->data);
	print(root->R);
}

int main()
{
	int ar[] = {1,2};
	int n = sizeof(ar)/sizeof(int);
	node *root = f(0,n-1,ar);
	print(root);
}
