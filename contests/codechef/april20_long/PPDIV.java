// Incomplete

import java.util.*;

class PPDIV {

	static final int mod = 1000000007;

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0) {
			long n = sc.nextInt();
			long ans = n;

			for(long i = 2; i * i <= n; i++) {

				long factor = i * i;
				while(factor <= n) {

					long count = n / factor;
					System.out.printf("Factor %d occurs %d times\n", factor, count);
					ans = (ans + factor * count % mod) % mod;
					factor *= i;
				}
			}

			System.out.println(ans);
		}
	}
}
