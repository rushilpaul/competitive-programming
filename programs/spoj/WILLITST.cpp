#include <iostream>
using namespace std;
typedef unsigned long long LL;

int main()
{
	LL n; cin >> n;
	if(__builtin_popcountll(n) == 1)
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
