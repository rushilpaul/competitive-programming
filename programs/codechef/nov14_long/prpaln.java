import java.io.*;
class prpaln
{
	public static boolean check(String s)
	{
		int n = s.length();
		for(int a=0;a<n/2;a++) if(s.charAt(a) != s.charAt(n-a-1)) return false;
		return true;
	}
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(in.readLine());
		String s;
		while(t-- > 0)
		{
			s = in.readLine();
			int n = s.length(), flag=0;
			for(int a=0;a<n;a++)
				if(s.charAt(a) != s.charAt(n-1-a))
				{
					if(!check(s.substring(a,n-1-a)) && !check(s.substring(a+1,n-a)))
						out.write("NO\n");
					else
						out.write("YES\n");
					flag = 1;
					break;
				}
			if(flag == 0) out.write("YES\n");
		}
		out.flush();
	}
}