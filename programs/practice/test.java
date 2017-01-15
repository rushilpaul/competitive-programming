import java.util.*;

class mu
{
	static int a=0;
	mu(int aa) { a=aa; }
	
	static void m() { System.out.println(a); }
}

class test extends mu
{
	public test()
	{
		super(2);
		System.out.println("Hey");
	}
	
	public static void main(String args[])
	{
		m();
	}

	public static String oct(int i)
	{
		return i<8 ? (""+i) : (oct(i/8) + "" + i%8);
	}

	static void msg(Object s)
	{ System.out.println(s); }
}
