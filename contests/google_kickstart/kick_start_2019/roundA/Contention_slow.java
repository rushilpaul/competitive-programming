// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e01/0000000000069881
// Complexity: T * (N + Q) * Q

import java.util.*;

class Node {
	int sum = 0;
	boolean lazy = false;
	Node left = null, right = null;
}

class SegmentTree {	// Range query / Range update
	Node root;

	SegmentTree(int n) {
		root = buildTree(1,n);
	}

	Node buildTree(int i, int j) {

		if(i == j)
			return new Node();

		int mid = (i + j) / 2;
		Node root = new Node();
		root.left = buildTree(i, mid);
		root.right = buildTree(mid+1, j);
		return root;
	}

	int query(Node node, int i, int j, int L, int R) { // L and R are query

		if(L > j || R < i || i > j)
			return 0;

		if(node.lazy) {
			node.sum = j-i+1;
			node.lazy = false;
			if(i != j)
				node.left.lazy = node.right.lazy = true;
		}

		if(L <= i && R >= j)
			return node.sum;

		int mid = (i + j) / 2;
		return query(node.left, i, mid, L, R) + query(node.right, mid+1, j, L, R);
	}

	void print(Node node, int i, int j) {
		if(i == j) {
			System.out.printf("(%d,%d) = %d\n", i,j,node.sum);
			return;
		}
		System.out.printf("(%d,%d) = %d\n", i, j, node.sum);
		print(node.left, i, (i+j)/2);
		print(node.right, (i+j)/2 + 1, j);
	}

	void update(Node node, int i, int j, int L, int R) {

// 		if(i > j) {
// 			Thread.sleep(40000);
// 		}
		if(node.lazy) {
			node.sum = j-i+1;
			node.lazy = false;
			if(i != j)
				node.left.lazy = node.right.lazy = true;
		}

		if(L > j || R < i || i > j)
			return;

		if(L <= i && R >= j) {
			if(i != j)
				node.left.lazy = node.right.lazy = true;
			node.sum = j-i+1;
			return;
		}

		int mid = (i + j) / 2;
		update(node.left, i, mid, L, R);
		update(node.right, mid+1, j, L, R);
		node.sum = node.left.sum + node.right.sum;
	}
}

class Interval {
	int x, y, pos;
	Interval(int x, int y, int pos) { this.x = x; this.y = y; this.pos = pos; }
}


class Solution {
    
    static int findAns(List<Interval> list, int n) {
        
        int ans = Integer.MAX_VALUE;
        SegmentTree tree = new SegmentTree(n);

		for(Interval p : list) {
			int range = p.y - p.x + 1;
			//System.out.println("query " + p + " " + tree.query(tree.root, 1, n, p.i, p.j));
			ans = Math.min(ans, range - tree.query(tree.root, 1, n, p.x, p.y));
			tree.update(tree.root, 1, n, p.x, p.y);
		}
		return ans;
    }
    
    static Interval solve(Set<Interval> intervals, int n) {
        
    	int q = intervals.size();
    	Map<Integer, List<Interval>> pairsByIndex = new HashMap(n);
    	Map<Interval, Integer> booked = new HashMap(300);
    	
    	for(Interval p : intervals) {
    	    pairsByIndex.putIfAbsent(p.x, new ArrayList());
    	    pairsByIndex.putIfAbsent(p.y, new ArrayList());
    		pairsByIndex.get(p.x).add(p);
    		pairsByIndex.get(p.y).add(p);
    		booked.put(p, 0);
    	}
    	
        Set<Interval> activeIntervals = new HashSet(300);
        
    	for(int i = 1; i <= n; i++) {
        
            if(pairsByIndex.get(i) != null)
    		for(Interval p : pairsByIndex.get(i))
                if(p.x == i) // starts
            	    activeIntervals.add(p);

    		if(activeIntervals.size() == 1)
		    	booked.merge(activeIntervals.iterator().next(), 1, Integer::sum);
        
            if(pairsByIndex.get(i) != null)
            for(Interval p : pairsByIndex.get(i))
                if(p.y == i) // ends
            	    activeIntervals.remove(p);
        }
          
        Interval bestInt = intervals.iterator().next();
        for(Interval interval : intervals)
        	if(booked.get(interval) > booked.get(bestInt))
        		bestInt = interval;
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
                intervals.add(new Interval(start, end, i));
            }
            
            LinkedList<Interval> orderedIntervals = new LinkedList();	// intervals stored in the reverse order
            
            for(int i = 0; i < q; i++) {
            	Interval interval = solve(intervals, n);
            	orderedIntervals.addFirst(interval);
            	intervals.remove(interval);
            }

			System.out.printf("Case #%d: %d\n", t, findAns(orderedIntervals, n));
		}

	}

}

