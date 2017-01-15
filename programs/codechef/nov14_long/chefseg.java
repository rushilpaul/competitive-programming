import java.util.*;
class chefseg
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0)
		{
			long x = sc.nextLong(), k = sc.nextLong();
			int bits = 0;
			long tmp = k;
			while(tmp > 0)
			{
				bits++;
				tmp >>= 1;
			}
			long diff = k - (1L<<(bits-1));
			System.out.printf("%.6f\n",(double)x / (1L<<bits) * (2*diff+1));
		}
	}
}