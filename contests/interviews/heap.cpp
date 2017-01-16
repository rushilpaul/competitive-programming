#include <cstdio>
#include <algorithm>
#include <cassert>

struct heap
{
	int *ar, n;
	heap()
	{
		ar = NULL;
		n = 0;
	}
	heap(int *A, int n) : n(n)
	{
		ar = new int[n+10];
		for(int a=1;a<=n;a++)
			ar[a] = A[a-1];
	}

	void siftup(int i)
	{
		int parent = i/2;
		while(parent >= 1)
		{
			if(ar[parent] < ar[i])
				std::swap(ar[i],ar[parent]);
			i = parent;
			parent = i/2;
		}
	}

	void siftdown(int i)
	{
		int left = i*2, right = i*2+1;
		int max = i;
		if(left <= n and ar[left] > ar[max])
			max = left;
		if(right <= n and ar[right] > ar[max])
			max = right;
		std::swap(ar[max],ar[i]);
		if(max != i)
			siftdown(max);
	}
	
	void heapify()
	{
		for(int a=n/2;a>=1;a--)
			siftdown(a);
	}

	int isheap(int i=1)
	{
		int left = i*2, right = i*2+1;
		if( (left <= n and ar[i] < ar[left]) or (right <= n and ar[i] < ar[right]) ) return 0;
		if(left <= n and isheap(left) == 0) return 0;
		if(right <= n and isheap(right) == 0) return 0;
		return 1;
	}
	
	int deletemin()
	{
		std::swap(ar[1],ar[n]);
		n--;
		siftdown(1);
		assert(isheap());
	}

	void insert(int item)
	{
		ar[++n] = item;
		siftup(n);
		assert(isheap());
	}

	void print() { for(int a=1;a<=n;a++) printf("%d ",ar[a]); printf("\n"); }
};

int main()
{
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++) scanf("%d",&ar[a]);
	heap h(ar,n);
	h.heapify();
	h.deletemin();
	h.insert(6);
	h.print();
}

