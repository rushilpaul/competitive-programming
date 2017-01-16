// Reverse a linked list
#include <cstdio>

class node
{
	public:
		int item;
		node *next;
};

class List
{
	node *head;
	public:
		List()
		{
			head = NULL;
		}
		void push(int item)
		{
			if(head == NULL)
			{
				head = new node;
				head->item = item;
				head->next = NULL;
				return;
			}
			node *cur = head;
			while(cur->next)
				cur = cur->next;
			cur->next = new node;
			cur->next->item = item;
			cur->next->next = NULL;
		}
		int pop()
		{
			if(head == NULL) return -999999;
			node *cur = head, *prev = head;
			while(cur->next)
			{
				prev = cur;
				cur = cur->next;
			}
			int item = cur->item;
			delete cur;
			cur = NULL;
			prev->next = NULL;
			return item;
		}
		void reverse()
		{
			if(head == NULL or head->next == NULL) return;
			node *cur, *next, *prev;
			prev = head;
			cur = prev->next;
			int a = 0;
			do
			{
				a++;
				next = cur->next;
				cur->next = prev;
				if(a == 1)
					prev->next = NULL;
				prev = cur;
				cur = next;
			} while(next);
			head = prev;
		}
		void print()
		{
			node *cur = head;
			while(cur)
			{
				printf("%d ",cur->item);
				cur = cur->next;
			}
			printf("\n");
		}
};

int main()
{
	List L;
	for(int a=1;a<=10;a++)
		L.push(a);
	L.print();
	L.reverse();
	printf("After reverse\n");
	L.print();
	return 0;
}

