#include <iostream>
using namespace std;

int hcf(int a, int b)
{
	int t=0;
	while (1)
	{
		int r = a%b;
		a = b;
		b = r;
		if(a/b > 1) return t;
		t++;
		if(!r) return t;
	}
	return -1;
}

void swap(int *a, int *b)
{
	if(*a == *b) return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

bool check(int a, int b)
{
	if (a==b) return 0;
	if(a<b) swap(a,b);
	if (a/b > 1) return 1;
	return hcf(a,b) % 2 == 1;
}

int main()
{
	int t; cin >> t;
	for(int tt=1;tt<=t;tt++)
	{
		int a1,a2,b1,b2,ans=0;
		cin >> a1 >> a2 >> b1 >> b2;
		if(a1 < b1)
		{
			swap(a1,b1);
			swap(a2,b2);
		}
		for(int a=a1;a<=a2;a++)
		for(int b=b1;b<=b2;b++)
			if(check(a,b)) ans++;
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}
