#include<iostream>
using namespace std;

int main()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int rem1, rem2, rem3, needed = 0;
	rem1 = max(a-x,0);
	rem2 = max(b-y,0);
	rem3 = max(c-z,0);

	needed += max(x-a,0);
	needed += max(y-b,0);
	needed += max(z-c,0);

    int can_aquire = rem1 / 2 + rem2 / 2 + rem3 / 2;

    if(can_aquire >= needed) cout << "Yes";
    else cout << "No";
    return 0;
}
