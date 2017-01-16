import java.io.*;
class ambi
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while(true)
		{
			int n = Integer.parseInt(in.readLine()),a;
			if(n==0) break;
			int ar[] = new int[n];
			String input[] = in.readLine().split(" ");
			for(a=0;a<n;a++) ar[a] = Integer.parseInt(input[a])-1;
			for(a=0;a<n;a++)
				if(ar[ar[a]] != a) break;
			if(a == n) System.out.println("ambiguous");
			else System.out.println("not ambiguous");
		}
	}
}
