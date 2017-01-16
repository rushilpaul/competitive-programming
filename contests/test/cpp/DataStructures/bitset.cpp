#include <iostream>
#include <bitset>
using namespace std;

int main()
{	
	bitset <10> ar;
	ar[3].flip();
	if(ar.any()) cout << "not 0" << endl;
	return 0;
}
