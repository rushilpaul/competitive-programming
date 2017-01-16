// convert sorted linked list to binary search tree
#include <cstdio>
#include <list>
using namespace std;

struct node
{
	node *L,*R;
	int data;
	node() { L = R = NULL; }
};

struct Lnode
{
	Lnode *next;
	int data;
	Lnode() { next = NULL; }
	Lnode(int data) : data(data) { next = NULL; }
};

void push(Lnode* &head, int data)
{
	Lnode *newnode = new Lnode(data);
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	Lnode* tmp = head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = newnode;
};

#include <cassert>

node* f(int l, int r, Lnode* &head)
{
	if(l > r) return NULL;
	int mid = (l+r)/2;
	node *left = f(l,mid-1,head);
	node *root = new node;
	root->data = head->data;
	fflush(stdout);
	root->L = left;
	head = head->next;
	root->R = f(mid+1,r,head);
	return root;
}

void printBST(node *root)
{
	if(root == NULL) return;
	printBST(root->L);
	printf("%d ",root->data);
	printBST(root->R);
}

void printLL(Lnode *head)
{
	Lnode* tmp = head;
	while(tmp)
	{
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
}

int main()
{
	Lnode *head = NULL;
	int n = 5;
	for(int a=1;a<=n;a++)
	{
		int b; scanf("%d",&b);
		push(head,b);
	}
	node *root = f(0,n-1,head);
	printBST(root);
}

