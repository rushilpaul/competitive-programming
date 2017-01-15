package structs;

public class BinaryTree
{
BTreeNode root, cur;
String second;
boolean delete;
public int total;
boolean IN, PRE, POST;
boolean twochildren;

public BinaryTree()
{ root = cur = null; second = ""; twochildren = delete = false; total = 0; }

public boolean addroot(String node)
{
if(root != null) return false;
root = new BTreeNode(node); cur = root;
total = 1;
return true;
}

public int insert(String pnode, String cnode, boolean left)
{
int children = nChildren(pnode);
if(children == -1) return 1;		// pnode doesn't exist
cur = root;
if(insertf(pnode, cnode, left)) { total++; return children == 2 ? 3 : 0; }	// if any child is overwritten, returns 3, else 0
return -1;	// unknown error
}

public int insert(String pnode, String cnode)
{
int c = nChildren(pnode);
cur = root;
if(c == 0) return insert(pnode, cnode, true);	// left
if(c == 1) return insert(pnode, cnode, false);	// right
return 2;	// no more can be added
}

public int insert(String pnode, String c1, String c2)
{
if(nChildren(pnode) == -1) return 1;    // pnode doesn't exist
twochildren = true; second = c2; cur = root;
total += 2;
return insertf(pnode, c1, true) ? 0 : -1;   // never returns -1
}

private boolean insertf(String pnode, String cnode, boolean left)
{
if(cur == null) return false;
if(cur.data.equals(pnode))
	{
	if(twochildren) {
					cur.left = new BTreeNode(cnode);
					cur.right = new BTreeNode(second);
					twochildren = false;
					return true;
					}
	 if(left) cur.left = new BTreeNode(cnode);
	 else cur.right = new BTreeNode(cnode);
	 return true;
	}
BTreeNode temp = cur;
cur = cur.left;
if(insertf(pnode, cnode, left)) return true;
cur = temp.right;
if(insertf(pnode, cnode, left)) return true;
cur = temp;
return false;
}

public int nChildren(String node)	// returns -1 if node doesn't exist
{
if(cur == null) return -1;
if(cur.data.equals(node)) { if(delete) { cur = null; return 0; }
                			else return (cur.left==null ? 0:1) + (cur.right==null ? 0:1); }
int n=0;
BTreeNode temp = cur;
cur = temp.left;
n = nChildren(node);

if(n != -1) return n;
cur = temp.right;
n = nChildren(node);
cur = temp;

if(n != -1) return n;
return -1;
}

public String search(String node)
{
cur = root;
return searchf(node);
}

private String searchf(String node)
{
if(cur == null) return null;
if(cur.data.equals(node)) return cur.data;
BTreeNode temp = cur;
cur = cur.left;
String s = searchf(node);
if(s != null) return temp.data + " " + s;

cur = temp.right;
s = searchf(node);
if(s != null) return temp.data + " " + s;
cur = temp;
return null;
}

public boolean delete(String node, boolean all)
{
if(all || root.data.equals(node)) { total = 0; root = null; System.gc(); return true; }
cur = root;
delete = true;
int done = nChildren(node);
if(done != -1) total--;
delete = false;
return done != -1;
}

public int height(String node)
{
cur = root;
return cur == null ? 0 : heightf(node, 1);
}

public int heightf(String node, int h)
{
if(cur == null) return 1;
BTreeNode temp = cur;
if(cur.data.equals(node)) return h;
cur = temp.left;
int c = heightf(node, h+1);
if( c != 0) return c;

cur = temp.right;
c = heightf(node, h+1);
if(c != 0) return c;
cur = temp;

return 0;	// not found
}

public String print(int o)  // 1 for preorder, 2 for inorder, 3 for postorder
{
if(o == 1) PRE = true;
if(o == 2) IN = true;
if(o == 3) POST = true;
cur = root;
String p = order();
PRE = IN = POST = false;
return p;
}

String order()
{
if(cur == null) return "";
String path = "";
BTreeNode temp = cur;
if(IN)
	{
        cur = temp.left;
        path += order();

        path += temp.data + " ";

        cur = temp.right;
        path += order();
    }
if(PRE)
    {
        path += temp.data + " ";

        cur = temp.left;
        path += order();

        cur = temp.right;
        path += order();
    }
if(POST)
    {
        cur = temp.left;
        path += order();

        cur = temp.right;
        path += order();

        path += temp.data + " ";
    }
cur = temp;
return path;
}

}

class BTreeNode
{
String data;
BTreeNode left,right;
public BTreeNode(String d)
{
left = right = null;
data = d;
}
}

