#include <cstdio>
#include <stack>
using namespace std;

#define NUL 1

struct node
{
	node *L, *R;
	int data;
	node() { L = R = (node*)NUL; }
	node(int d) : data(d)
	{ L = R = (node*)NUL; }
};

node* f(int *ar, int n)
{
	node *root = new node(ar[0]);
	stack<node*> s;
	s.push(root);
	for(int a=1;a<n;a++)
	{
		node *tmp = s.top();
		if(ar[a] != -1)
		{
			node *cur = new node(ar[a]);
			if(tmp->L == (node*)NUL)
				tmp->L = cur;
			else
				tmp->R = cur;
			if(tmp->R != (node*)NUL)
				s.pop();
			s.push(cur);
		}
		else
		{
			if(tmp->L == (node*)NUL)
				tmp->L = NULL;
			else
				tmp->R = NULL;
			if(tmp->R == NULL)
				s.pop();
		}
	}
	return root;
}

void inorder(node* root)
{
	if(root == NULL) return;
	inorder(root->L);
	printf("%d ",root->data);
	inorder(root->R);
}

int main()
{
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++) scanf("%d",&ar[a]);
	node *root = f(ar,n);
	inorder(root);
}

