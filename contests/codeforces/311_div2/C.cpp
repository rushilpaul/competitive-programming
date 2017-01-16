#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 10

char buf[max_buf_size];
int _bytes_read_ = max_buf_size-1;
char *_s = buf + _bytes_read_;
inline char getc1() { if(_s >= buf + _bytes_read_) { _bytes_read_ = fread(buf,1,max_buf_size-1,stdin); buf[_bytes_read_] = 0;  _s = buf; } return *(_s++); }
inline int readint()
{
	char t=getc1(); int n=1,res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{ n=-1; t=getc1(); }
	while(isdigit(t))
	{ res = 10*res + (t&15); t=getc1(); }
	return res*n;
}

int freq[100001], lens[100001], sumcost[100001];

int main()
{
	int n = readint();
	pair<int,int> ar[n+1];
	for(int a=0;a<n;a++)
	{
		ar[a].first = readint();
		freq[ar[a].first]++;
		lens[a] = ar[a].first;
	}
	for(int a=0;a<n;a++)
		ar[a].second = readint();
	sort(lens,lens+n);
	sort(ar,ar+n);
	for(int a=0;a<n;a++)
		sumcost[a] = ar[a].second;
	for(int a=n-2;a>=0;a--)
		sumcost[a] += sumcost[a+1];

	int ans=INT_MAX, first = 0;
	vector<int> d(200,0), fd(200,0);
	for(int a=0;a<n;a++)
	{
		if(a == 0 or ar[a].first != ar[a-1].first)
		{
			int mincost;
			int next = upper_bound(lens,lens+n,ar[a].first) - lens;
			if(next == n)
				mincost = 0;
			else
				mincost = sumcost[next];
			int k = freq[ar[a].first]-1;
			int idx = 200 - (lower_bound(d.rbegin(), d.rend(), k) - d.rbegin()) - 1;
			int tot=0;
			for(int b=idx;b<200;b++)
					if(b == idx)
						tot += (b+1) * (k - (b < 199 ? d[b+1] : 0));
					else
						tot += (b+1)*fd[b];
			if(k == 0)
				tot = 0;
			tot = sumcost[0] - sumcost[a] - tot;
			if(k >= a)
				tot = 0;
			ans = min(ans, tot+mincost);
			first = a+1;
		}
		fd[ar[a].second-1]++;
		for(int b=0;b<ar[a].second;b++) d[b]++;
	}
	printf("%d\n",ans);
	return 0;
}

