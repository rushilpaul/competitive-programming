#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

inline int pow(int b, int e)
{
	int ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow(LL b, LL e)
{
	LL ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow(LL b, LL e, LL mod)
{
	LL ans=1;
	while(e)
	{
		if(e & 1)
			ans = ans * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return ans;
}
 
int egcd(int a, int b, int &x, int &y)
{
	if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}
 
LL egcd(LL a, LL b, LL& x, LL& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}
 
LL inv(LL a, LL m)
{
	LL inv,y;
	assert(egcd(a,m,inv,y) == 1);
	if(inv < 0) inv += m;
	return inv;
}

inline LL gcd(LL a, LL b)
{
	while(b)
	{
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}

vector<string> split(string S, string D)
{
	vector<string> ar;
	int pos = 0, last = 0;
	while( (pos = S.find(D,last)) != string::npos)
	{
		ar.push_back(S.substr(last,pos-last));
		last = pos + D.length();
	}
	ar.push_back(S.substr(last));
	return ar;
}

int f(int *ar, int n)
{
	/*
	for(int a=0;a<n;a++)
		printf("%d ",ar[a]);
	printf("\n");
	*/
	int ans=0;
	int done[n];
	fill(done,done+n,0);
	for(int num=1;num<=n;num++)
	{
		int a;
		for(int i=0;i<n;i++)
			if(ar[i] == num) { a = i; break; }
		if(a == 0 or a == n-1) continue;

		int pos1=-1, pos2=-1;
		int min1 = INT_MAX, min2 = INT_MAX;
		for(int i=a-1;i>=0;i--)
			if(ar[i] > ar[a] and ar[i] < min1 and !done[i])
			{
				pos1 = i;
				min1 = ar[i];
			}
		for(int i=a+1;i<n;i++)
			if(ar[i] > ar[a] and ar[i] < min2 and !done[i])
			 {
				 pos2 = i;
				 min2 = ar[i];
			 }
		if(pos1 != -1)
			done[pos1] = 1;
		if(pos2 != -1)
			done[pos2] = 1;
		if(pos1 != -1 and pos2 != -1)
			ans += (pos2 - pos1);
	}
	//printf("score = %d\n",ans);
	return ans;
}

int main()
{
	int t; scanf("%d",&t);	
	while(t--)
	{
	int n; scanf("%d",&n);
	int ar[n];
	for(int a=0;a<n;a++) ar[a] = a+1;
	int ans=0;
	do
	{
		ans += f(ar,n);
	} while(next_permutation(ar,ar+n));
	cout << ans << " ";
	}
	
	return 0;
}
