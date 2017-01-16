import structs.*;
import java.util.Scanner;
class linkedlist
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the records: ");
LinkedList list = new LinkedList();
String s = "";
while(true)
{
s = sc.nextLine();
if(s.length() == 0) break;
list.add(s);
}
list.insert("Insertion point", 1);
for(int a=0;a<list.size;a++)
  System.out.printf("Record %d: %s\n", a+1, list.get(a));
System.out.println();
}
}
