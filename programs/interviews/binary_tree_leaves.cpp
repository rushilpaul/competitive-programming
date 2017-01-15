// Given a binary tree, check if all leaves are at the same level or not
#include <cstdio>

struct node
{
	int n;
	node *L, *R;
	node() { L = R = NULL; }
};

void f(node *root)
{
	root->L = new node;
	root->R = new node;
}

int check(node *root)
{
	if(root == NULL)
		return 0;
	if(root->L == NULL and root->R == NULL)
		return 1;
	int left = check(root->L) + 1, right = check(root->R) + 1;
	return left != right ? -1 : left;
}

int main()
{
	node *root = new node;
	f(root);
	printf("%d\n",check(root));
	return 0;
}
