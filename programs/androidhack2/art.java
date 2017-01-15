import java.util.*;
class art
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t,len; String s;
		t = sc.nextInt();
		while(t-- != 0)
		{
			s = sc.next();
			len = s.length();
			for(int a=0;a<len;a++)
			 System.out.println(s.substring(0,a+1));
			for(int a=0;a<len;a++)
			 System.out.println(s.substring(a+1));
		}
	}
}
			
