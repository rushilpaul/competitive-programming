import java.math.*;
import java.io.*;

class seadiv
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(reader.readLine());
		while(t-- > 0)
		{
			String s = reader.readLine();
			BigInteger A = new BigInteger(s,7);
			s = reader.readLine();
			BigInteger B = new BigInteger(s,7);
			int L = Integer.parseInt(reader.readLine());
			BigInteger C = A.divide(B);
			String div = C.toString(7);
			String ans = "";
			int i = div.length()-1;
			for(int a=0;a<L && i >= 0;a++,i--)
				ans = div.charAt(i) + ans;
			i = -1;
			for(int a=0;a<ans.length();a++)
				if(ans.charAt(a) != '0') { i = a; break; }
			if(i == -1) System.out.println("0");
			else System.out.println(ans.substring(i));
		}
	}
}
