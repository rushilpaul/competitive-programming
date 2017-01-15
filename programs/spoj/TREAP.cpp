#include <bits/stdc++.h>
using namespace std;

struct node
{
	int prior,size;
	int key;
	int diff,max,min; //segtree specific info
	struct node *l,*r;
};

typedef node* pnode;
int sz(pnode t) { return t ? t->size : 0; }

void upd_sz(pnode t)
{
	if(t) t->size = sz(t->l) + 1 + sz(t->r);
}

void combine(pnode& t, pnode l, pnode r) //combining two ranges of segtree
{
	if(!l || !r) return void(t = l ? l:r);
	if(l->diff >= 0)
		t->diff = l->diff;
	if(r->diff >= 0)
		t->diff = r->diff;
	t->diff = min(t->diff, abs(l->max - r->min));
	t->min = l->min;
	t->max = r->max;
}

void operation(pnode t) //operation of segtree
{
	if(!t) return;
	combine(t,t->l,t);
	combine(t,t,t->r);
}

void split(pnode t, pnode &l, pnode &r, int k)
{
	l = r = NULL;
	if(!t) return;
	if(t->key < k) //element at pos goes to left subtree(l)
		split(t->r,t->r,r,k), l = t;
	else
		split(t->l,l,t->l,k), r = t;
	upd_sz(t);
	operation(t);
}

void merge(pnode &t, pnode l, pnode r)
{
	if(!l || !r)
		t = l ? l:r;
	else if(l->prior > r->prior)
		merge(l->r,l->r,r), t = l;
	else
		merge(r->l,l,r->l), t = r;
	upd_sz(t);
	operation(t);
}

pnode init(int key)
{
	pnode ret = new node;
	ret->prior = rand();
	ret->size = 1;
	ret->key = key;
	ret->diff = -1;
	ret->max = ret->min = key;
	return ret;
}

pnode range_query(pnode t, int l, int r) // [l,r]
{
	pnode L,mid,R;
	split(t,L,mid,l-1);
	split(mid,t,R,r-l); //note: r-l
	pnode ans = t;
	merge(mid,L,t);
	merge(t,mid,R);
	return ans;
}

void insert(pnode root, int key)
{
	pnode l,r;
	split(root, l, r, key);
	merge(root, l, init(key));
	merge(root, root, r);
}

void delete_treap(pnode root, int key)
{
	pnode l,m,r;
	split(root, l, m, key);
	split(m, m, r, key+1);
	delete m;
	merge(root, l, r);
}

pnode treap;
set<int> s;

int main()
{
	int q; cin >> q;
	while(q--)
	{
		char c; cin >> c;
		if(c == 'I')
		{
			int k; cin >> k;
			if(s.find(k) != s.end()) continue;
			s.insert(k);
			if(treap == NULL) treap = init(k);
			else insert(treap, k);
		}
		else if(c == 'D')
		{
			int k; cin >> k;
			if(s.find(k) == s.end()) continue;
			s.erase(k);
			if(treap)
				delete_treap(treap, k);
		}
		else if(c == 'N')
		{
			int i,j; cin >> i >> j;
			range_query(treap,i,j);
		}
		if(treap)
			printf("%d %d %d, size: %d\n",treap->min, treap->max, treap->diff,treap->size);
	}
	
	return 0;
}

