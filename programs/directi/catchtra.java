import java.util.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0)
		{
			int ve = sc.nextInt(), vy = sc.nextInt(), L = sc.nextInt(), T = sc.nextInt();
			double t1 = 1.0 * L / ve - 1.0 * L / (ve + vy);
			double ans = t1 / T;
			if(t1 > T) ans = 1;
			System.out.println(ans);
		}
	}
}
