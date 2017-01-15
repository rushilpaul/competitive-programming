// Given a binary tree, find all nodes at a distance of k
#include <cstdio>

struct node
{
	node *L, *R;
	int data;
	node() { L = R = NULL; }
	node(int d) : data(d) { L = R = NULL; }
};

node *path[100]; int d;

void print_dist_k(node *root, int cur, int max)
{
	if(root == NULL) return;
	if(cur > max) return;
	if(cur == max)
		printf("%d ",root->data);
	else
	{
		print_dist_k(root->L,cur+1,max);
		print_dist_k(root->R,cur+1,max);
	}	
}

int findpath(node *root, int data)
{
	if(root == NULL) return 0;
	path[d++] = root;
	if(root->data == data) return 1;
	if(findpath(root->L,data) || findpath(root->R,data)) return 1;
	d--;
	return 0;
}

void func(int k)
{
	for(int a=0;a<d-1;a++)
	{
		int len = d - a - 1;
		len = k - len;
		if(len == 0)
			printf("%d ",path[0]->data);
		if(len <= 0) continue;
		if(path[a]->L == path[a+1])
			print_dist_k(path[a]->R,0,len-1);
		else
			print_dist_k(path[a]->L,0,len-1);
	}
	print_dist_k(path[d-1],0,k);
}

node* make(int l, int r, int *ar)
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
	root->L = make(l,mid-1,ar);
	root->R = make(mid+1,r,ar);
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
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++)
		scanf("%d",ar+a);
	node *root = make(0,n-1,ar);
	int search,k; scanf("%d %d",&search,&k);
	findpath(root,search);
	func(k);
}

