#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	for(int c=1;c<=t;c++)
	{
		int n, s, p, ans=0; cin >> n >> s >> p;
		int ar[n];
		for(int a=0;a<n;a++)
		{
			cin >> ar[a];
			if( (ar[a]+1)%3 == 0)
			{
				if( (ar[a]+1)/3 >= p) { ans++; continue; }
			}
			if( ar[a]%3 == 0)
			{
				if( ar[a]/3 >= p) { ans++; continue; }
			}
			if( (ar[a]-1)%3 == 0)
			{
				if( (ar[a]+2)/3 >= p) { ans++; continue; }
			}
			if( s <= 0) continue;
			
			if( ar[a]%3 == 0 && ar[a]) if(ar[a]/3 + 1 >= p) { ans++; s--; continue; } 	// surprising case
			if( (ar[a]+4)%3 == 0)	// surprising case
				if( (ar[a]+4)/3 >= p) { ans++; s--; }
		}
		cout << "Case #" << c << ": " << ans << endl;
	}
	return 0;
}
