import java.util.*;
class factors
{
static HashMap dp;

	static int m_fn(long number)
	{
		long n = number, t=0;
		int c=0;
		for(int i=2;i<=n;i++)
		{
			while(n % i == 0)
			{
				if(t==i) return 0;
				c++;
				t=i;
				n /= i;
			}
		}
		if(c % 2 == 0) return 1;
		return -1;
	}

	static long fox(long n)
	{
		if(dp.containsKey(n)) return (Long)dp.get(n);
		else
		{
			if(n==1) return 1;
			long i=0;
			for(i=n/2;i>0;i--)
			{
				if(n%i==0) break;
			}
			long temp = fox(i)+n*m_fn(n);
			dp.put(n,temp);
			return temp;
		}
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt(), x;
		while(tc-- != 0)
		{
			dp = new HashMap();
			x = sc.nextInt();
			for(long i=x<<1;;i++)
				if(Math.abs(fox(i)) > x)
				{
					System.out.println(i); break;
				}
		}
	}
}

		
