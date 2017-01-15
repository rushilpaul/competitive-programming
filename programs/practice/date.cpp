#include <iostream>
#include <sstream>
using namespace std;

bool checkleap(int y);
string printdate(int n, int y);

bool checkleap(int y)
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

string printdate(int n, int y)
{
	int year = y, month=1, days=n;
	y = checkleap(y) ? 1 : 0;
			
	while( n > 0)
	{
		if(month > 12)
		{
			y = checkleap(++year) ? 1 : 0;
			month = 1;
		}
		days = n;
		if(month == 2) if(y==1) n -= 29;
					   else n -= 28;
		else if(month <= 7) if(month % 2 == 1) n -= 31;
							else n -= 30;
		else
		{
			if(month % 2 == 0) n -= 31;
			else n -= 30;
		}
		month++;
	}
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string app = "th";
	if( days % 10 == 1) app = "st";
	else if(days % 10 == 2) app = "nd";
	else if(days % 10 == 3) app = "rd";
	stringstream val;
	val << days << app << " " << months[month-2] << " " << year;
	return val.str();
}

int main()
{
	int n,y,after;
	cout << "Enter the number of days, year and additional number of days: ";
	cin >> n >> y >> after;
	bool err = n < 1 || n > 366;
	if(!checkleap(y)) if( n > 365) err = true;
	if(err) { cout << "Incorrect input." << endl; return 1; }
	cout << "Current Date: \t" << printdate(n,y) << endl << "Date after " << after << " days: " << printdate(n+after,y) << endl;
	return 0;
}
