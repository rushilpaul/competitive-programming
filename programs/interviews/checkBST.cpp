#include <cstdio>

struct node
{
	node *L,*R;
	int data;
	node() { L = R = NULL; }
	node(int data) : data(data) { L = R = NULL; }
};

int f(node *root)
{
	if(root == NULL) return 1;
	static node *prev = NULL;
	if(!f(root->L)) return 0;
	if(prev and prev->data > root->data) return 0;
	prev = root;
	if(!f(root->R)) return 0;
	return 1;
}

int main()
{
	node *root = new node(5);
	root->L = new node(5);
	root->L->L = new node(1);
	root->L->R = new node(4);
	root->R = new node(8);
	root->R->L = new node(6);
	root->R->R = new node(9);
	printf("%d\n",f(root));
}
