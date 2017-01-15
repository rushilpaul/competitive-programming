package structs;
public class Queue
{
int ar[], s, front, rear;
public Queue(int s)
{
  rear = -1; front = 0;
  this.s = s;
  ar = new int[s];
}

public boolean push(int n)
{
  if(rear == s-1) return false;
  ar[++rear] = n;
  return true;
}

public int pop()
{
  if(rear == -1) { System.err.println("Error: Queue empty!"); return -99999; }
  int r = ar[front];
  for(int a = front; a < rear; a++) ar[a] = ar[a+1];
  rear--;
  return r;
}

public int peek()
{
  return ar[rear];
}
}

