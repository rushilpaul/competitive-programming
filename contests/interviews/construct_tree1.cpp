// construct a BST from its preorder traversal
#include <cstdio>
#include <stack>
using namespace std;

struct node
{
	node *L, *R;
	int data;
	node() { L = R = NULL; }
	node(int d) { L = R = NULL; data = d; }
};

void inorder(node* root)
{
	if(root == NULL) return;
	inorder(root->L);
	printf("%d ",root->data);
	inorder(root->R);
}

node* construct(int &i, int n, int *ar, int m)
{
	if(i >= n) return NULL;
	node *root = new node(ar[i]);
	if(i+1 < n and ar[i+1] > m)
		return root;
	root->L = construct(++i,n,ar,ar[i]);
	if(root->L and root->L->data > root->data)
	{
		root->R = root->L;
		root->L = NULL;
	}
	else
		root->R = construct(++i,n,ar,m);
	return root;
}

void f(stack<node*> &s)
{
	node *tmp = s.top();
	s.pop();
	node *parent = s.top();
	s.pop();
	if(tmp->data <= parent->data)
		parent->L = tmp;
	else
		parent->R = tmp;
	s.push(parent);
}

node* cons_stack(int *ar, int n)
{
	stack<node*> s, min_val;
	s.push(new node(ar[0]));
	min_val.push(new node(1<<30));
	min_val.push(s.top());
	int left=1;
	int i = 1;
	while(i < n)
	{
		if(ar[i] > min_val.top()->data)
		{
			if(left)
			{
				min_val.pop();
				left = 0;
			}
			else	// right
			{
				node* last;
				while(ar[i] > min_val.top()->data)
				{
					f(s);
					last = min_val.top();
					min_val.pop();
				}
				while(s.top() != last)
					f(s);
				left = 1;
			}
			continue;
		}
		s.push(new node(ar[i]));
		left = 1;
		min_val.push(s.top());
		i++;
	}
	while(s.size() > 1)
		f(s);
	return s.top();
}

node* cons_stack2(int *ar, int n)
{
	node *root = new node(ar[n-1]);
	stack<node*> s;
	s.push(root);
	for(int a=n-2;a>=0;a--)
	{
		if(ar[a] > s.top()->data)
		{
			node *tmp = s.top();
			s.pop();
			tmp->R = new node(ar[a]);
			s.push(tmp);
			s.push(tmp->R);
		}
		else
		{
			node *tmp = NULL;
			while(s.size() > 0 and s.top()->data >= ar[a])
			{
				tmp = s.top();
				s.pop();
			}
			node *t = tmp;
			while(t->L) t = t->L;
			t->L = new node(ar[a]);
			s.push(tmp);
			s.push(t->L);
		}
	}
	return root;
}

int main()
{
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++) scanf("%d",&ar[a]);
	int i=0;
	node *root = cons_stack2(ar,n);
	inorder(root);
}

