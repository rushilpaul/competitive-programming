
// Complexity: T * (K * K + N log N)
import java.util.*;

class Interval {
	int x, y, cost;
	Interval(int x, int y) { this.x = x; this.y = y; }
}

class Event {
    Interval i;
    int pos;
    boolean opening;
    
    public static Event getOpening(Interval i, int pos) {
        Event e = new Event();
        e.i = i;
        e.pos = pos;
        e.opening = true;
        return e;
    }
    
    public static Event getClosing(Interval i, int pos) {
        Event e = new Event();
        e.i = i;
        e.pos = pos;
        e.opening = false;
        return e;
    }    

}


class Solution {
    
    static Interval solve(Set<Interval> intervals, int n) {
        
    	int q = intervals.size();
    	Map<Interval, Integer> booked = new HashMap(300);
    	List<Event> events = new ArrayList();
    	
    	for(Interval i : intervals) {
    	    events.add(Event.getOpening(i, i.x));
    	    events.add(Event.getClosing(i, i.y));
    	    booked.put(i, 0);
    	}
    	
    	Collections.sort(events, (e1,e2) -> {
    	    if(e1.pos != e2.pos)
    	        return e1.pos - e2.pos;
    	    else if(e1.opening != e2.opening)
    	        return e1.opening ? -1 : 1;
    	    else
    	        return e1.opening ? e1.i.y - e2.i.y : e1.i.x - e2.i.x;
    	});
    	
    	// sweep line algo
    	Set<Interval> activeSet = new HashSet();
    	Event lastEvent = null;
    	
    	for(Event event : events) {
    	    
    	    if(activeSet.size() == 1) {
    	        
				Interval activeInterval = activeSet.iterator().next();
    	        int seatsBooked = event.pos - lastEvent.pos;
    	        if(lastEvent.i == event.i && event.i == activeInterval)
    	            seatsBooked++;
				else if(lastEvent.i != event.i && event.i != activeInterval && lastEvent.i != activeInterval)
					seatsBooked--;
    	        
    	        booked.merge(activeInterval, seatsBooked, Integer::sum);
    	    }
    	    
    	    if(event.opening)
                activeSet.add(event.i);
    	    else
    	        activeSet.remove(event.i);
    	    lastEvent = event;
    	}
    	
    	Interval bestInt = intervals.iterator().next();
    	for(Interval i : intervals)
    	    if(booked.get(i) > booked.get(bestInt))
    	        bestInt = i;
    	bestInt.cost = booked.get(bestInt);
        return bestInt;
    }

	public static void main(String args[]) throws Exception {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int t = 1; t <= T; t++) {

			int n = sc.nextInt(), q = sc.nextInt();

			Set<Interval> intervals = new HashSet();
			
            for(int i = 0; i < q; i++) {
            	int start = sc.nextInt();
                int end = sc.nextInt();
                intervals.add(new Interval(start, end));
            }

            int ans = Integer.MAX_VALUE;
            
            for(int i = 0; i < q; i++) {
            	Interval bestInt = solve(intervals, n);
            	ans = Math.min(ans, bestInt.cost);
            	intervals.remove(bestInt);
            }
			System.out.printf("Case #%d: %d\n", t, ans);
		}

	}

}

