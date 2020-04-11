// https://www.codechef.com/APRIL20A/problems/STRNO
import java.util.*;

class STRNO
{
	public static void main (String[] args)
	{
	    Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0) {
		    int n = sc.nextInt(), k = sc.nextInt();
			int exp = 0;
			for(int i = 2; i * i <= n; i++)
				while(n % i == 0) {
					n /= i;
					exp++;
				}
			if(n > 1)
				exp++;
		    System.out.println(exp >= k ? "1" : "0");
		}
	}
}

