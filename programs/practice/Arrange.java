import java.util.*;
class Arrange
{
public static void main(int n)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the numbers:");
Stack s = new Stack(n), buf = new Stack(n/2);
for(int a=0;a<n;a++) s.push(sc.nextInt());
int i = s.peek()%2 == 0 ? 1 : 0;
int a=1;
System.out.print(s.pop() + " ");
while(a < n)
{
while(true)
   {
      if(i%2 == 0) {
          if(s.peek() % 2 == 0) { System.out.print(s.pop()+ " "); break; }
                  }
      else {
          if(s.peek() % 2 == 1) { System.out.print(s.pop() + " "); break; }
           }
           buf.push(s.pop());
   }
while(!buf.isEmpty()) s.push(buf.pop());
i++; a++;
}
}
}