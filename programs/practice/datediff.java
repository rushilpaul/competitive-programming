import java.util.*;
class datediff
{
	static int abs(String date)	// returns absolute date in days
	{
		int d = Integer.parseInt(date.substring(0,2)), m = Integer.parseInt(date.substring(2,4)), y = Integer.parseInt(date.substring(4));
		y--;
		int days = y*365 + (y/4 - y/100) + y/400;
		y++;
		boolean leap = y%400 == 0 || (y%4 == 0 && y%100 != 0);
		for(int i=1; i<m; i++)
		{
			if(i == 2)
			{
				if(leap) days += 29;
					else days += 28;
			}
			else if(i <= 7)
			{
				if(i%2 == 1) days += 31;
						else days += 30;
			}
			else
			{
				if(i%2 == 0) days += 31;
						else days += 30;
			}
		}
		days += d;
		return days;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the two dates in the format ddmmyyyy:");
		String date1 = sc.next(), date2 = sc.next();
		int s1 = abs(date1), s2 = abs(date2);
		System.out.println("Number of days in between = " + (int)Math.abs(s1-s2));
	}
}

		
