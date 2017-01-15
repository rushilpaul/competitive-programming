#include <iostream>
using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n < 0) break;
		cout << (n+8)/9 << endl;
	}
	return 0;
}
