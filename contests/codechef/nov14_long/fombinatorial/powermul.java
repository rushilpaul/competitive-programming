import java.io.*;

class powermul
{
	static long ar[][] = new long[501][500];
	static int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};
	
	static long pow(long b, long e, long mod)
	{
		if(e == 0) return 1;
		long ans = pow(b,e/2,mod);
		ans = (ans * ans) % mod;
		if((e&1) == 1) return (ans*b)%mod;
		else return ans;
	}

	static long f(int n, int p)
	{
		int t = 0;
		int num = n;
		while(num > 0)
		{
			t++;
			num /= p;
		}
		int ans = 0, p2 = p;
		for(int i=1;i<=t;i++)
		{
			int terms = n/p2;
			ans += terms * p2 * (1 + terms) / 2;
			p2 *= p;
		}
		return ans;
	}

	static void init()
	{
		int n = 500;
		for(int a=2;a<=n;a++)
			for(int p : primes)
				ar[a][p] = f(a,p);
	}

	static long final_ans[] = new long[501];

	static void init2(int n, int m)
	{
		for(int r=1;r<=n/2;r++)
		{
			long ans = 1;
			for(int p : primes)
			{
				long power = ar[n][p] - ar[r][p] - ar[n-r][p];
				if(power > 0)
					ans = (ans * pow(p,power,m)) % m;
			}
			final_ans[r] = final_ans[n-r] = ans;
		}
	}

	public static void main(String args[]) throws Exception
	{
		long time = System.currentTimeMillis();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		init();
		int t = Integer.parseInt(in.readLine().trim());
		while(t-- > 0)
		{
			String input[] = in.readLine().trim().split(" ");
			int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]), q = Integer.parseInt(input[2]);
			init2(n,m);
			while(q-- > 0)
			{
				int r = Integer.parseInt(in.readLine().trim());
				out.write("" + final_ans[r] + "\n");
			}
		}
		time = System.currentTimeMillis() - time;
		out.write("" + (double)time/1000.0);
		out.flush();
	}
}