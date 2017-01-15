import java.util.*;
class sentence
{
	static LinkedList vowels;
	static String v = "aeiouAEIOU";

	static void lexi(String s)
	{
		LinkedList words = new LinkedList();
		String w = ""; int len = s.length();
		for(int a=0;a<len;a++)
		{
			if(Character.isLetter(s.charAt(a))) w += s.charAt(a);
			else
			{
				if(w.length() != 0)
				{
					words.add(w);
					if(v.indexOf(w.charAt(0)) != -1 && vowels.indexOf(w) == -1) vowels.add(w);
					w = "";
				}
			}
		}
		boolean done = true;
		String ar[] = new String[words.size()];
		for(int a=0;a<ar.length;a++) ar[a] = (String)words.get(a);

		for(int a=0;a<ar.length && done;a++)
		{
			done = false;
		for(int b=0;b<ar.length-1;b++)
			if(ar[b].toLowerCase().compareTo(ar[b+1].toLowerCase()) > 0)
			{
				w = ar[b]; ar[b] = ar[b+1]; ar[b+1] = w;
				done = true;
			}
		}
		for(int a=0;a<ar.length;a++) System.out.print(ar[a] + " ");
		System.out.print(s.charAt(len-1) + " ");
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		vowels = new LinkedList();
		System.out.println("Enter the sentence: ");
		String sent = sc.nextLine().trim();
		int start=0,end;
		while(true)
		{
			for(end=start;end<sent.length();end++) if(".,!?".indexOf(sent.charAt(end)) >= 0) break;
			if(end == sent.length()) break;
			end++;
			lexi(sent.substring(start,end));
			for(start=end;start<sent.length();start++)
				if(Character.isLetter(sent.charAt(start))) break;
			if(start >= sent.length()) break;	// all sentences enumerated
		}
		for(int a=0;a<vowels.size();a++) System.out.print( (a==0 ? "\n" : " ") + vowels.get(a));
		System.out.println();
	}
}
