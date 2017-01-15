//Program question at: http://www.codechef.com/OCT12/problems/MAXCOMP
#include <stdio.h>
#define max(a,b) a>b?a:b
#define for(i,a,b) for(i=a;i<b;i++)
int maxio=16384;
char buf[16384], *s = buf + 16384;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc_(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }

typedef long long LL;
int n, size; LL *mem;
typedef struct event_
{
	int start, end, cost;
} event;

inline void swap(event **ar, int i, int j)
{
	event *tmp = ar[i];
	ar[i] = ar[j];
	ar[j] = tmp;
}

void quicksort(event **ar, int left, int right)
{
	int pivot = ar[(left+right)/2]->start, i=left, j=right;
	while(i <= j)
	{
		while(ar[i]->start < pivot) i++;
		while(ar[j]->start > pivot) j--;
		if(i <= j)
		{
			swap(ar,i,j);
			i++;
			j--;
		}
	}
	if(i < right) quicksort(ar,i,right);
	if(j > left) quicksort(ar,left,j);
}

LL solve(event **ar, int i)
{
	int a,end=ar[i]->end; LL w=0;
	for(a,i+1,n)
	{
		if(ar[a]->start >= end)
		{
			LL *tmp = &mem[a];
			if(*tmp != -1) w = max(w,*tmp);
			else w = max(w,solve(ar,a));
		}
	}
	w += ar[i]->cost;
	mem[i] = w;
	return w;
}

int main()
{
	int t=input(),a;
	size = 2000;
	mem = (LL*)malloc(size*sizeof(LL));
	while(t--)
	{
		for(a,0,size) mem[a] = -1;
		n = input();
		event ar[n], *E[n];
		for(a,0,n)
		{
			ar[a].start = input();
			ar[a].end = input();
			ar[a].cost = input();
			E[a] = &ar[a];
		}
		quicksort(E,0,n-1);
		LL ans=0;
		for(a,0,n) ans = max(ans,solve(E,a));
		printf("%lld\n",ans);
	}
	return 0;
}
