import java.io.*;
import java.util.*;
import java.math.*;

class pair
{
	public int x,y;
	public pair() {}
	public pair(int x, int y) { this.x = x; this.y = y; }
}

class smplsum
{
final static int max_primes = 10000001;		// 1e7+1
static int largestpdiv[] = new int[max_primes];
static long ans[] = new long[max_primes];

static void sieve()
{
	for(int a=0;a<max_primes;a++) largestpdiv[a] = 0;

	for(int a=2;a*a<max_primes;a++)
	{
		if(largestpdiv[a] != 0) continue;
		largestpdiv[a] = a;
		for(int b=a*a;b<max_primes;b+=a)
			largestpdiv[b] = a;
	}
	for(int a=2;a<max_primes;a++)
		if(largestpdiv[a] == 0)
			largestpdiv[a] = a;
}

public static void main(String args[]) throws Exception
{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	sieve();
	ans[1] = 1;

	int t = Integer.parseInt(in.readLine());
	while(t-- > 0)
	{
		int n = Integer.parseInt(in.readLine());
		if(ans[n] != 0)
		{
			out.write(Long.toString(ans[n]) + "\n");
			continue;
		}
		int backup = n, L=0;
		long val = 1;
		while( (L=largestpdiv[n]) > 0)
		{
			int count = 0;
			while(n % L == 0)
			{
				count++;
				n /= L;
			}
			pair p = new pair(L,count);
			BigInteger big = BigInteger.valueOf(p.x);
			big = big.pow(2*p.y + 1);
			big = big.add(BigInteger.ONE);
			big = big.divide(BigInteger.valueOf(p.x + 1));
			val = val * big.longValue();
		}
		n = backup;
		ans[n] = val;
		out.write(Long.toString(val) + "\n");
	}
	out.flush();
}
}
