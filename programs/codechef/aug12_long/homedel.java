import java.io.*;
class drange
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		int ar[][] = new int[n][n];
		for(int a=0;a<n;a++)
		{
			String s[] = in.readLine().split(" ");
			for(int b=0;b<n;b++)
				ar[a][b] = Integer.parseInt(s[b]);
		}
	}
}
