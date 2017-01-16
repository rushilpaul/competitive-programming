class DeciOct
{
public static void main(String args[])
{
System.out.println(convert(Integer.parseInt(args[0])) );
}

static String convert(int n)
{
if(n < 8) return n+"";
return convert(n/8) + convert(n%8);
}
}
