// Mirror an n-ary tree
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
	node* *ar;
	int n, data;
	node()
	{
		n=0;
		ar = NULL;
	}
	node(int n, int data) : n(n), data(data)
	{
		ar = new node*[n];
		for(int a=0;a<n;a++)
			ar[a] = new node;
	}
	~node()
	{
		for(int a=0;a<n;a++)
			delete ar[a];
		delete ar;
	}
};

void mirror(node *root)
{
	if(root == NULL || root->n == 0) return;
	for(int a=0;a<root->n;a++)
		mirror(root->ar[a]);
	int n = root->n;
	for(int a=0;a<(root->n)/2;a++)
		swap(root->ar[a], root->ar[n-a-1]);
}

void print(node *root)
{
	queue< pair<int,node*> > q;
	q.push({0,root});
	int prev = -1;
	while(q.size())
	{
		auto f = q.front();
		q.pop();
		if(prev != f.first)
			printf("\n");
		prev = f.first;
		printf("%d ",f.second->data);
		for(int a=0;a<f.second->n;a++)
			q.push({f.first+1,f.second->ar[a]});
	}
}

int main()
{
	node *root = new node(5,1);
	for(int a=0;a<5;a++)
		root->ar[a]->data = a+2;
	root->ar[0] = new node(1,2);
	root->ar[0]->ar[0]->data = 7;

	root->ar[2] = new node(2,4);
	root->ar[2]->ar[0]->data = 8;
	root->ar[2]->ar[1]->data = 9;
	print(root);
	mirror(root);
	print(root);
}

