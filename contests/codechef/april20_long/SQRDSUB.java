// https://www.codechef.com/APRIL20A/problems/SQRDSUB
import java.util.*;

class SQRDSUB
{
	
	static long solve(int A[]) {

		int n = A.length;
		int S[][] = new int[n][4];
		for(int i = 0; i < n; i++) {
			A[i] = Math.abs(A[i]) % 4;
			Arrays.fill(S[i], 0);
		}

		S[0][A[0]] = 1;

		for(int i = 1; i < n; i++) {

			S[i][A[i]] = 1;
			for(int R = 0; R < 4; R++) {
				
				int r = R * A[i] % 4;
				S[i][r] += S[i-1][R];
			}
		}

		long ans = (long) n * (n+1) / 2;
		for(int i = 0; i < n; i++)
			ans -= S[i][2];

		return ans;
	}

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0)
		{
			int n = sc.nextInt();
			int ar[] = new int[n];
			for(int i = 0; i < n; i++)
				ar[i] = sc.nextInt();

			System.out.println(solve(ar));
		}
	}
}
