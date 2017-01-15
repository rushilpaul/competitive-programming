import java.util.*;
class testdate
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter date in 6 digit format: ");
		String date = sc.next();
		int day=0, month=0, year=0;
		try
		{
			day = Integer.parseInt(date.substring(0,2));
			month = Integer.parseInt(date.substring(2,4));
			year = Integer.parseInt(date.substring(4));
		}
		catch(NumberFormatException nfe)
		{
			System.err.println("INVALID DATE"); System.exit(1);
		}

		String m[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" }, app = "th";		
		boolean leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 == 0);
		boolean err = false;
		if(month == 2)
		{
			if(leap)
			{
				if(day > 29) err = true;
			}
			else
			{
				if(day > 28) err = true;
			}
		}
		else if(month <= 7)
		{
			if(month % 2 == 0)
			{
				if(day > 30) err = true;
			}
			else
			{
				if(day > 31) err = true;
			}
		}
		else if(month > 7 && month <= 12)
		{
			if(month % 2 == 0)
			{
				if(day > 31) err = true;
			}
			else
			{
				if(day > 30) err = true;
			}
		}
		else if(month > 12)
			err = true;

		if(err)
		{
			System.out.println("INVALID DATE");
			System.exit(1);
		}
		else
		{
				 if(day % 10 == 1) app = "st";
			else if(day % 10 == 2) app = "nd";
			else if(day % 10 == 3) app = "rd";
			System.out.printf("%d%s %s, %d\n", day, app, m[month-1], year);
			System.err.println("VALID DATE");
		}
	}
}

	


