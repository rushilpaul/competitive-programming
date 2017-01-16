import structs.*;
import java.util.*;
class test
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.println( hcf(sc.nextInt(), sc.nextInt()) );
if(sc != null) return;
System.out.println("Enter the size of array, then the array elements:");
int s = sc.nextInt();
structs.Queue q = new structs.Queue(s);

while ( q.push(sc.nextInt()) );
System.out.println("Printing ----------------\n");

for(int a=0;a<s;a++) System.out.print(q.pop() + " ");
System.out.println();
}

static int hcf(int a, int b)
{
int r=1;
while(a!=0)
  {
	r = b%a;
	b = a;
	a = r;
  }
return b;
}

}
