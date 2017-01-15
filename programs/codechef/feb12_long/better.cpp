#include <iostream>
using namespace std;

int main()
{
    string a,b,c;
    int na, nb, r;
    cin >> a;
    na = a.size();
    cin >> b;
    nb = b.size();
    cin >> c;
    r = 0;
    for (int i = 0; i < nb; i++)
	{
        for (int j = 1; j < min(na+1, nb-i+1); j++)
		{
            bool f = true;
            int d = 0;
            for (int k = 0; k < j; k++)
			{
                if (a[k] != b[i+k])
				{
                    if (c[k] == '1') 
                        d += 1;
                    else
                        f = false;
                }
            }
            if (f && d <= 2)
                r = (r + j*j) % 1000000007;
        }
    }
    cout << r << endl;
    return 0;
}
