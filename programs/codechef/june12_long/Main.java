//Program question at: http://www.codechef.com/JUNE12/problems/CLOSEST
import java.util.*;
import java.math.*;
class Main
{
	static BigInteger sq(BigInteger n) { return n.multiply(n); }

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(),q,a;
		BigInteger ar[][] = new BigInteger[n][3];
		for(a=0;a<n;a++)
		{
			ar[a][0] = new BigInteger(sc.next());
			ar[a][1] = new BigInteger(sc.next());
			ar[a][2] = new BigInteger(sc.next());
		}
		q = sc.nextInt();
		BigInteger x = new BigInteger(sc.next()), y = new BigInteger(sc.next()), z = new BigInteger(sc.next());

		BigInteger min = new BigInteger("120000000000000000000"), t;
		int ans=0;
		for(a=1;a<q;a++) sc.nextLine();
		for(a=0;a<n;a++)
		{
			t = sq(x.subtract(ar[a][0])).add(sq(y.subtract(ar[a][1]))).add(sq(z.subtract(ar[a][2])));
			if(t.compareTo(min) < 0)
			{
				min = t;
				ans = a;
			}
		}
		for(a=0;a<q;a++) System.out.println(ans);
	}
}
		
