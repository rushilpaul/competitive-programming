class bt
{
	public static void main(String args[])
	{
		BTNode root = new BTNode("55");
		root.left = new BTNode("50");
		root.right = new BTNode("65");
		root.right.left = new BTNode("60");
		root.right.right = new BTNode("70");
		StringBuilder sb = new StringBuilder();
		inOrder(root, 0, sb);
		System.out.println(sb);
	}

	static void inOrder(BTNode node, int depth, StringBuilder sb)
	{
		if(node == null) return;

		inOrder(node.left, depth+1, sb);

		for(int a=0;a<depth;a++) sb.append(".");
		sb.append(node.data + "\n");

		inOrder(node.right, depth+1, sb);
	}
}

class BTNode
{
	BTNode left, right;
	String data = "";
	
	public BTNode(String d)
	{
		data = d;
		left = right = null;
	}
}
