import java.util.*;
import java.math.*;
import java.text.DecimalFormat;
class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0)
		{
			t -= 1;
			int n = sc.nextInt(), m = sc.nextInt();
			BigDecimal ar[][] = new BigDecimal[n][m];
			for(int a=0;a<n;a++)
			{
				for(int b=0;b<m;b++)
					ar[a][b] = new BigDecimal(sc.nextDouble());
			}
			for(int a=0;a<n;a++)
			{
				int count=0;
				for(int b=1;b<m;b++)
				{
					ar[a][0] = ar[a][0].multiply(ar[a][b]);
					String s = ar[a][0].toPlainString();
					int i = s.indexOf(".")+1, len = s.length(), c=0;
					if(i-1 < 0)
						continue;
					while(i < len && s.charAt(i) == '0')
					{
						i++;
						c++;
					}
					ar[a][0] = ar[a][0].scaleByPowerOfTen(c).setScale(20,RoundingMode.DOWN);
					//System.out.println(ar[a][0].toPlainString());
					count += c;
				}
				ar[a][0] = ar[a][0].scaleByPowerOfTen(-count);
				//System.out.println();
			}
			BigDecimal sum = ar[0][0];
			for(int a=1;a<n;a++)
				sum = sum.add(ar[a][0]);
			if(sum.equals(BigDecimal.ZERO))
				sum = BigDecimal.ZERO;
			else
				sum = ar[0][0].divide(sum,10,RoundingMode.DOWN);
			String ans = new DecimalFormat("#.#######").format(sum);
			System.out.println(ans);
		}
	}
}
