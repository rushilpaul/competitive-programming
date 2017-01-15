#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

template<class T>
T read(T &n) { cin >> n; return n; }
template<class T1,class T2>
void read(T1 &n1, T2 &n2) { cin >> n1 >> n2; }
template<class T1,class T2,class T3>
void read(T1 &n1, T2 &n2, T3 &n3) { cin >> n1 >> n2 >> n3; }
template<class T1,class T2,class T3,class T4>
void read(T1 &n1, T2 &n2, T3 &n3, T4 &n4) { cin >> n1 >> n2 >> n3 >> n4; }
template<class T>
void read(T *ar, int n)
{
	for(int a=0;a<n;a++) cin >> ar[a];
}
#define max_buf_size 4096
char _out_buf_[max_buf_size];

struct _init_
{
	_init_()
	{
		setvbuf(stdout,_out_buf_,_IOFBF,max_buf_size);
		ios_base::sync_with_stdio(0); cin.tie(0);
	}
} _init_ob_unused;

struct data
{
	LL good;
	vector<int> pos;
	data() {}
	data(LL g)
	{ good = g; }
	data(LL g, const vector<int> &v)
	{
		good = g;
		pos.assign(v.begin(),v.end());
	}
};
LL ar[37] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986 };

int n=37,k;
data *good;

int comp(const data &a, const data &b) { return a.good < b.good; }

void f(int i, LL p, vector<int> &idx)
{
	good[k++] = data(p,idx);
	for(int a=i;a<n;a++)
	{
		if(ar[a] == 8 || ar[a] == 144) continue;
		if(p * ar[a] > 100000000) return;
		idx.push_back(a);
		f(a,p*ar[a],idx);
		idx.pop_back();
	}
}

int search(LL n, int size, int i)
{
	int L = 0, R = size-1;
	while(L<=R)
	{
		int mid = (L+R)/2;
		if(n == good[mid].good) return mid;
		else if(n < good[mid].good) R = mid-1;
		else L = mid+1;
	}
	return i ? R : L;
}

int main()
{
	good = new data[33818];
	good[0] = data(0);
	k=1;
	vector<int> idx;
	f(0,1,idx);
	int size = k;
	sort(good,good+size,comp);
	int t; read(t);
	while(t--)
	{
		LL L,R; read(L); read(R);
		int n1; read(n1);
		int low = search(L,size,0), high = search(R,size,1);
		if(low + n1 - 1 <= high)
		{
			LL num = good[low+n1-1].good;
			printf("%lld ",num);
			if(num == 0) printf("##");
			else if(num == 1) printf(".");
			else
			{
				vector<int>::iterator it;
				int p = 1;
				for(it = good[low+n1-1].pos.begin(); it != good[low+n1-1].pos.end(); it++)
				{
					p *= ar[*it];
					for(int a=0;a<=(*it)+2;a++) printf(".");
					if(it < good[low+n1-1].pos.end()-1)
					printf("#");
				}
				assert(num == p);
			}
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
