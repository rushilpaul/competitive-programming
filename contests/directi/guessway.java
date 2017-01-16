import java.util.*;

class Main
{
	static long f(int h, char dir, long target, long ans)
	{
	if(h == 0)
	{
		if(dir == 'L' && target == 0) return ans;
		else if(dir == 'R' && target == 1) return ans;
		else return ans;
	}
	if(target > (1L<<(h-1)) && dir == 'R')
	{
		return f(h-1, 'R' , target-(1L<<(h-1)), ans + (1L<<h));
	}
	else if(target > (1L<<(h-1)) && dir == 'L')
	{
		return f(h-1, 'R', target-(1L<<(h-1)), ans+1);
	}
	else if(target <= (1L<<(h-1)) && dir == 'R')
	{
		return f(h-1, 'L', target, ans+1);
	}
	else if(target <= (1L<<(h-1)) && dir == 'L')
	{
		return f(h-1, 'L', target, ans + (1L<<h));
	}
	return -1;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0)
		{
			int h = sc.nextInt();
			long n = sc.nextLong();
			System.out.println(f(h,'R',n,0));
		}
	}
}
