// inorder, preorder and postorder traversals using stack
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
	node *L, *R;
	int data;
	node() { L = R = NULL; }
	node(int d) { L = R = NULL; data = d; }
};

node* f(int l, int r, vector<int> &ar)
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

void inorder(node *root)
{
	stack<node*> s;
	while(root or !s.empty())
	{
		if(root)
		{
			s.push(root);
			root = root->L;
		}
		else
		{
			root = s.top();
			printf("%d ",root->data);
			s.pop();
			root = root->R;
		}
	}
}

void preorder(node *root)
{
	stack<node*> s;
	while(root or not s.empty())
	{
		if(root)
		{
			printf("%d ",root->data);
			s.push(root);
			root = root->L;
		}
		else
		{
			root = s.top();
			s.pop();
			root = root->R;
		}
	}
}

void postorder(node *root)
{
	stack< pair<node*,int> > s;
	s.push({root,0});
	while(!s.empty())
	{
		if(s.top().first)
		{
			auto t = s.top();
			s.pop();
			if(t.second == 0)
			{
				t.second = 1;
				s.push(t);
				s.push({t.first->L,0});
			}
			else if(t.second == 1)
			{
				t.second = 2;
				s.push(t);
				s.push({t.first->R,0});
			}
			else
				printf("%d ",t.first->data);
		}
		else
			s.pop();
	}
}

void post_rec(node *root)
{
	if(!root) return;
	post_rec(root->L);
	post_rec(root->R);
	printf("%d ",root->data);
}

void pre_rec(node *root)
{
	if(!root) return;
	printf("%d ",root->data);
	pre_rec(root->L);
	pre_rec(root->R);
}

int main()
{
	node *root = new node(5);
	root->L = new node(4);
	root->L->L = new node(10);
	root->R = new node(6);
	root->R->L = new node(2);
	root->R->R = new node(7);
	postorder(root);
	printf("\n");
	post_rec(root);
}

