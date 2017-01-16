#include <cstdio>

struct node
{
	node *down, *next;
	int data;
	node() { down = next = NULL; }
	node(int d) : data(d) { down = next = NULL; }
};

void add(node* &head, int data)
{
	node *nn = new node(data);
	if(head == NULL)
	{
		head = nn;
		return;
	}
	node *cur = head;
	while(cur->next)
		cur = cur->next;
	cur->next = nn;
}

node* getnode(int data) { return new node(data); }

node* flatten(node *head)
{
	node *cur = head, *prev = NULL;
	while(cur)
	{
		prev = cur;
		node *next = cur->next;
		if(cur->down)
		{
			cur->next = cur->down;
			(flatten(cur->down))->next = next;
			cur->down = NULL;
		}
		cur = next;
	}
	return prev;
}

void print(node *head)
{
	node *cur = head;
	while(cur)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
}

int main()
{
	node *head = NULL;
	for(int a=1;a<=4;a++)
		add(head,a);
	head->down = getnode(7);
	head->down->next = getnode(8);
	head->next->next->down = getnode(10);
	head->next->next->down->next = getnode(11);
	node *cur = head->down;
	cur->down = getnode(14);
	cur = cur->down;
	for(int a=15;a<=16;a++)
		add(cur,a);
	cur->next->down = getnode(20);
	cur->next->down->next = getnode(21);

	flatten(head);
	print(head);
}

