#include <cstdio>
#include <vector>
using namespace std;

int f(int n)
{
	vector<int> ar(n);
	for(int a=0;a<n;a++)
		ar[a] = a+1;
	int i=0;
	while(ar.size() > 1)
	{
		i = (i + 2) % n;
		ar.erase(ar.begin()+i);
		n--;
		i %= n;
	}
	return ar[0];
}

int main()
{
	printf("%d\n",f(100000));
}

