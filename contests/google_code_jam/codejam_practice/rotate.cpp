#include <iostream>
using namespace std;

int main()
{
	int tt; cin >> tt;
	for(int t=1;t<=tt;t++)
	{
		int red,blue,n,k; cin >> n >> k; bool R=0,B=0;
		cout << "Case #" << t << ": ";
		char ar[n][n];
		for(int a=0;a<n;a++)
		{
			red = blue = 0;
			for(int b=0;b<n;b++)
			{
				char ch; cin >> ch;
				if(ch == 'B') blue++; else blue=0;
				if(ch == 'R') red++; else red=0;
				ar[a][b] = ch;
			}
			if(red >= k) R=1;
			if(blue >= k) B=1;
			if(R & B) break;
		}

		for(int a=0;a<n;a++)
		for(int i=1;i<n;i++)
		for(int b=n-1;b>0;b--)
			if(ar[a][b] != '.') continue;
			else { ar[a][b] = ar[a][b-1]; ar[a][b-1] = '.'; }
		// column checking

		for(int b=0;b<n;b++)
		{
			red = blue = 0;
			for(int a=0;a<n;a++)
			{
				if(ar[a][b] == 'R') red++; else red=0;
				if(ar[a][b] == 'B') blue++; else blue=0;
			}
			if(red >= k) R=1;
			if(blue >= k) B=1;
			if(R && B) goto end;
		}

		// diagonals
		for(int a=0;a<n;a++)
		{
			red = blue = 0;
			for(int a1=a,b=0;b<n;b++,a1++)
			{
				if(ar[a1][b] == 'R') red++; else red=0;
				if(ar[a1][b] == 'B') blue++; else blue=0;
			}
			if(red >= k) R=1;
			if(blue >= k) B=1;
			if(R && B) goto end;
		}
		for(int a=0;a<n;a++)
		{
			red = blue = 0;
			for(int a1=a,b=0;b<n;b++,a1++)
			{
				if(ar[b][a1] == 'R') red++; else red=0;
				if(ar[b][a1] == 'B') blue++; else blue=0;
			}
			if(red >= k) R=1;
			if(blue >= k) B=1;
			if(R && B) goto end;
		}
		for(int a=n-1;a>=0;a--)
		{
			red = blue = 0;
			for(int a1=a,b=0;a1>=0;b++,a1--)
			{
				if(ar[b][a1] == 'R') red++; else red=0;
				if(ar[b][a1] == 'B') blue++; else blue=0;
			}
			if(red >= k) R=1;
			if(blue >= k) B=1;
			if(R && B) goto end;
		}
		
		for(int a=0;a<n;a++)
		{
			red = blue = 0;
			for(int a1=a,b=n-1;a1<n;b--,a1++)
			{
				if(ar[a1][b] == 'R') red++; else red=0;
				if(ar[a1][b] == 'B') blue++; else blue=0;
			}
			if(red >= k) R=1;
			if(blue >= k) B=1;
			if(R && B) goto end;
		}
		end:
		if(R & B) cout << "Both";
		else if(R) cout << "Red";
		else if(B) cout << "Blue";
		else cout << "Neither";
		cout << endl;
	}
	return 0;
}
