package structs;
public class LinkedList
{
Node first;
public int size;

public LinkedList()
{ size = 0; }

public boolean add(Object ob)
{
if(this.first == null) { this.first = new Node(ob); size++; return true; }
Node cur = first;
while( cur.next != null)
  cur = cur.next;

try { cur.next = new Node(ob); size++; }
catch(Exception er) { System.err.println("Error: Out of Memory."); return false; }
return true;
}

public Object get(int i)	// get object at 0 based ith index
{
if(size == 0) { System.err.println("Error: List empty!"); return null; }
Node cur = first;
for(int a=0;a<i && cur != null;a++) cur = cur.next;
return cur.data;
}

public boolean delete(int i)	// delete object at 0 based ith index
{
if(size == 0) { System.err.println("Error: List empty!"); return false; }
if(i < 0 || i >= size) { System.err.println("Error: Wrong index."); return false; }
Node cur = first;
if(i == 0) { first = null; return true; }
for(int a=0;a<i-1;a++) cur = cur.next;
cur.next = cur.next.next;
size--;
return true;
}

public void delete()
{ delete(size-1); }

public boolean insert(Object ob, int i)	// insert object at 0 based ith index
{
if(i < 0 || i >= size) { System.err.println("Error: Wrong index."); return false; }
Node cur = first;
for(int a=0;a<i-1;a++)
  cur = cur.next;
Node newnode = null;
try { newnode = new Node(ob); } catch(Exception er) { System.err.println("Error: Out of memory."); return false; }
newnode.next = cur.next;
cur.next = newnode;
size++;
return true;
}

}

class Node
{
Node next;
Object data;

public Node(Object ob)
{ data = ob; next = null; }
}


