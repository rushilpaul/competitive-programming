import java.util.*;
class date
{
	static boolean checkleap(int y)
	{
		return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
	}

	static String printdate(int n, int y)
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
		String months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		String app = "th";
		if( days % 10 == 1) app = "st";
		else if(days % 10 == 2) app = "nd";
		else if(days % 10 == 3) app = "rd";
		return days + app + " " + months[month-2] + " " + year;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of days, year and additional number of days: ");
		int n = sc.nextInt(), y = sc.nextInt(), after = sc.nextInt();
		if(checkleap(y))
			if(n < 1 || n > 366) { System.err.println("Incorrect input."); System.exit(1); }
			else if(n < 1 || n > 365) { System.err.println("Incorrect input."); System.exit(1); }

		System.out.printf("Date is:\t\t%s\nDate after %d days:\t%s\n", printdate(n,y), after, printdate(n+after,y));
	}
}
