// in a binary tree, convert the last level to a Linked List
#include <cstdio>

struct node
{
	int n;
	node *L, *R;
	node() { L = R = NULL; }
	node(int n) : n(n) { L = R = NULL; }
};

void f(node *root)
{
	if(!root) return;
	static node *prev = NULL;
	if(!root->L and !root->R)
	{
		if(!prev)
		{
			prev = root;
			return;
		}
		prev->R = root;
		root->L = prev;
		prev = root;
		return;
	}
	f(root->L);
	f(root->R);
}

int main()
{
	node *root = new node(5);
	root->L = new node(3);
	root->R = new node(6);
	root->R->L = new node(2);
	root->L->L = new node(10);
	root->L->R = new node(20);
	f(root);
	node *cur = root->L->L;
	while(cur)
	{
		printf("%d ",cur->n);
		cur = cur->R;
	}
}

