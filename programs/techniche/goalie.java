import java.io.*;
class GOALIE
{
	public static void main(String args[])throws IOException
	{
		BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter y=new BufferedWriter(new OutputStreamWriter(System.out));
		int t=Integer.parseInt(x.readLine());
		outer:for(int i=0;i<t;i++)
		{
			int n=Integer.parseInt(x.readLine());
			if(n==1)
			{
				y.append("1\n");
				continue;
			}
			int a=1;
			while(a<=n)
			{
				a<<=1;
				if(a==n)
				{
					y.append("1\n");
					continue outer;
				}
			}
			a>>=1;
			y.append(Integer.toString(((n%a+1)<<1)-1)+"\n");
		}
		y.flush();
	}
}
