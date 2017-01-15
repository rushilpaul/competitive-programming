#include <iostream>
using namespace std;

int main()
{
	int k=2,m=2,n=3;
	int ***A = new int**[k];
	for(int a=0;a<k;a++)
	{
		A[a] = new int*[m];
		for(int b=0;b<m;b++)
		{
			A[a][b] = new int[n];
			for(int c=0;c<n;c++) cin >> A[a][b][c];
		}
	}
	for(int a=0;a<k;a++,cout<<"\n")
		for(int b=0;b<m;b++,cout<<"\n")
			for(int c=0;c<n;c++) cout << A[a][b][c];
	return 0;
}
