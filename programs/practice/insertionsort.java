import java.util.*;
class insertionsort
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
int s = Integer.parseInt(args[0]);
int ar[] = new int[s];
for(int a=0;a<s;a++) ar[a] = sc.nextInt();
sort(ar);
for(int a=0;a<s;a++) System.out.print(ar[a] + " ");
}

static void sort(int ar[])
{
int m = ar.length,b,t;
for(int i=1; i<m ;i++)
{
	t = ar[i];
	b = i - t;
	while(b >= 0 && t < ar[b])
	{
	  ar[b+1] = ar[b];
	  b--;
	}
	ar[b+1] = t;
}
}

}
