import structs.BinaryTree;
import jline.*;
import java.util.*;
import java.io.IOException;

class binarytree
{
public static void main(String args[]) throws IOException
{
System.out.println("\t\t\t\t\t\033[1;31mBinary Tree Program.\n\t\t\t\t\tAuthor: Rushil Paul\033[0;31m(rushilpaul@gmail.com)\033[0m");
ConsoleReader reader = new ConsoleReader();
reader.setBellEnabled(false);
List commands = new LinkedList();
commands.add(new SimpleCompletor(new String[] { "addroot", "delete", "exists", "exit", "height", "help", "insert", "print", "quit", "search" , "total" } ));
reader.addCompletor(new ArgumentCompletor(commands));

String syntax = "Commands:\n\t\033[0;31maddroot <root_node>\t\t\tAdds a root node\n\tdelete <list of nodes> [-a]\t\tDeletes the listed nodes separated by one space. Deletes all nodes if -a option is given.\n\tsearch <node>\t\t\t\tSearches and displays the full path to the specified node\n\tinsert <parent_node> <node> [-L|-R]\tInserts the given node as a child of the specified parent node to the left or right\n\t\t\t\t\t\t  If -L or -R option is omitted, then children are filled from left to right.\n\tprint\t\t\t\t\tPrints the binary tree\n\theight\t\t\t\t\tPrints current height of the tree\n\texists <node>\t\t\t\tTells if a given node if present\n\ttotal\t\t\t\t\tDisplays total number of nodes in tree.\n\texit\t\t\t\t\tExit this program\033[0m";

BinaryTree tree = new BinaryTree();
String com = "";
while(true)
{
com = reader.readLine("\033[1;32m>\033[0m ");
if(com == null) continue;
if(com.length() == 0) continue;
if(com.startsWith("help")) { System.out.println(syntax); continue; }
else if(com.startsWith("exit") || com.startsWith("quit")) System.exit(0);
else if(com.startsWith("addroot"))
	{
		try { com = com.split(" ")[1]; }
		catch(Exception er) { err("No node name specified."); continue; }
		if(!tree.addroot(com)) err("Root node already present.");
	}
else if(com.startsWith("insert"))
	{
		String params[] = null;
		try { params = com.substring(7).split(" "); }
		catch(Exception er) { err("No parameters supplied."); }
		if(params.length < 2) { err("More parameters need to be given. Type \"help\" for command syntax."); continue; }
		if(params.length > 3) err("Too many parameters given. Looking at the first 3.");
        int error;
        if(params.length == 3)
        {
        if(params[2].equalsIgnoreCase("-L") || params[2].equalsIgnoreCase("-R"))
         {
            error = tree.insert(params[0], params[1], params[2].equalsIgnoreCase("-L"));
            if(error == 1) err("Parent node doesn't exist.");
            if(error == 3) System.out.println("A child was overwritten.");
         }
        else {      // 2 child nodes are given
            if(tree.insert(params[0], params[1], params[2]) == 1) err("Parent node doesn't exist."); }
        }
		else 
            { error = tree.insert(params[0], params[1]);
            if(error == 1) err("Parent node doesn't exist.");
            else if(error == 2) err("No more children can be added. Please specify -L or -R option to overwrite a child node.");
            }
	}
else if(com.startsWith("search"))
	{
		try { com = com.split(" ")[1]; }
		catch(Exception er) { err("No node to be searched entered."); continue; }
		String path = tree.search(com);
		if(path == null) err("Node not found.");
		else System.out.println(path);
	}
else if(com.startsWith("delete"))
	{
		String params[] = com.split(" ");
        if(params.length == 1) err("No parameter or option given.");

		for(int a=1;a<params.length;a++)
			{
			if(params[a].equalsIgnoreCase("-a")) {	System.out.println("All nodes deleted.");
								tree.delete(null,true); }
			else if(params[a].startsWith("-")) err("Unknown option specified.");
			else {
				if(!tree.delete(params[a],false)) err("Node not found."); }
			}
	}
else if(com.startsWith("height"))
	{
        try { com = com.split(" ")[1]; }
        catch(Exception er) { err("No node specified."); continue; }
		System.out.println("Height: " + tree.height(com));
	}
else if(com.startsWith("print"))
    {
        try { com = com.substring(5).split(" ")[1]; }
        catch(Exception er) { err("No order specified.\nUsage: print in|pre|post"); continue; }
        String path = "";
        if(com.equalsIgnoreCase("pre")) path = tree.print(1);
        else if(com.equalsIgnoreCase("in")) path = tree.print(2);
        else if(com.equalsIgnoreCase("post")) path = tree.print(3);
        System.out.println(path);
    }
else if(com.startsWith("total"))
    {
        System.out.println(tree.total);
    }
else err("Unrecognized Command. Type \"help\" for a list of commands.");
}	// end loop

}

static void err(String msg)
{ System.out.printf("\033[0;34mError: %s\033[0m\n", msg); }

}



