// Print the left view of a binary tree
#include <cstdio>

struct node
{
	node *L, *R;
	int n;
	node() { L = R = NULL; }
	node(int i) : n(i) { L = R = NULL; }
};

void f(node *root, int cur, int &max)
{
	if(root == NULL) return;
	if(cur > max)
		printf("%d ",root->n);
	if(cur > max) max = cur;
	f(root->L, cur+1, max);
	f(root->R, cur+1, max);
}

node* get(int data) { return new node(data); }

int main()
{
	node *root = new node(12);
	root->L = new node(10);
	root->R = new node(30);
	root->R->L = new node(25);
	root->R->R = new node(40);
	int max = 0;
	f(root,1,max);
}
