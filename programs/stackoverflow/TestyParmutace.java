import java.util.*;
class TestyParmutace
{
	public static void main(String[] args)
	{

		List<Place> places = new ArrayList<Place>();

		Place place1 = new Place();
		place1.tokens.add(1);
		place1.tokens.add(2);
		place1.tokens.add(3);
		places.add(place1); //add place to the list

		Place place2 = new Place();
		place2.tokens.add(3);
		place2.tokens.add(4);
		place2.tokens.add(5);
		places.add(place2); //add place to the list

		Place place3 = new Place();
		place3.tokens.add(6);
		place3.tokens.add(7);
		place3.tokens.add(8);
		places.add(place3); //add place to the list

		List<Integer> tokens = new ArrayList<Integer>();
		Func(places,0,tokens);
	}

	public static boolean Func( List<Place> places, int index, List<Integer> tokens) 
	{

		if (index >= places.size())
		{
			String outputTokens = "";
			for (int i = 0; i< tokens.size(); i++)
			{
				outputTokens+= tokens.get(i) +",";
			}
			System.out.println("Tokens: " + outputTokens);

			if (tokens.get(0) == 4 && tokens.get(1) == 5 && tokens.get(2) == 10)
			{
				System.out.println("we passed the guard with 3,5,8");
				return true;
			}
			else
			{
				tokens.remove(tokens.get(tokens.size()-1));
				return false;
			}
		}

		Place p = places.get(index);

		for (int i = 0; i< p.tokens.size(); i++)
		{
			tokens.add(p.tokens.get(i));

			if ( Func( places, index+1, tokens ) ) return true;

		}
		if (tokens.size()>0)
			tokens.remove(tokens.get(tokens.size()-1));

		return false;
	}
}

