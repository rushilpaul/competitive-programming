import java.util.*;

class Alarm
{
	static long mod = 1000000007;

	static long pow(int b, int p)
	{
		if(p == 0) return 1;
		long ans = pow(b, p / 2);
		ans = ans * ans % mod;
		if(p % 2 == 1)
			ans = ans * b % mod;
		return ans;
	}

	static long modInverse(int x)
	{
		return pow(x, (int) mod - 2);
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t = 1; t <= T; t++)
		{
			int n = sc.nextInt();
			int k = sc.nextInt();
			long x = (long) sc.nextInt();
			long y = (long) sc.nextInt();
			long C = (long) sc.nextInt();
			long D = (long) sc.nextInt();
			int E1 = sc.nextInt();
			int E2 = sc.nextInt();
			int F = sc.nextInt();
			int A[] = new int[n+1];

			// Build the array A

			for(int i = 1; i <= n; i++)
			{
				A[i] = (int) ((x + y) % F);
				long lastX = x, lastY = y;
				x = (C * lastX + D * lastY + E1) % F;
				y = (D * lastX + C * lastY + E2) % F;
			}

			long ans = 0;
			long innerResult = k;

			for(int j = 1; j <= n; j++)
			{
				if(j != 1)
					innerResult = ( innerResult + (long) j * (pow(j, k) - 1) % mod * modInverse(j-1) ) % mod;

				ans = ans + innerResult * A[j] * (n - j + 1);
				ans %= mod;
			}

			System.out.printf("Case #%d: %d\n", t, ans);
		}
	}
}
