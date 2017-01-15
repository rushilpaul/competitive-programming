import java.util.*;
class texting
{
	public static void main(String args[])
	{
		String ar[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-- != 0)
		{
			String str = sc.next(), tmp="";
			str += " ";
			int s=0, check=0;
			char prev = ' ';

		for(int i=0;i<str.length();i++)
		{
			char c = str.charAt(i);
			if(i!=0)
			for(int a=2;a<10;a++)
			{
				if(ar[a].indexOf(c) >= 0 && ar[a].indexOf(prev) >= 0) { check=0; break; }
				if(ar[a].indexOf(c) >= 0 || ar[a].indexOf(prev) >= 0) check++;
				if(check == 2) break;
			}
			if(check != 0) {
			s = s + tmp.length()-1; tmp = ""; }
			check = 0;

			if(i == str.length()-1) break;
			prev = c;
			outer: for(int a=2;a<10;a++)
			{
				inner: for(int b=0;b < ar[a].length(); b++)
					if( c == ar[a].charAt(b) )
					 {
					  for(int t=0;t<b+1;t++) tmp += "0"; break outer;
					 }
			}
		}
		System.out.println( (1 << s) % 100000007);
	}
	}
}
