import java.util.*;

class Parcels {

    static class Pair {
        int x,y;
        Pair(int x, int y) { this.x = x; this.y = y; }
		public String toString() {
			return "(" + x + "," + y + ")";
		}
    }

	static int ar[][], n, m;
	static int transitions[][] = { { 1,0 }, {-1,0}, {0,1}, {0,-1} };

	static boolean valid(Pair p) { return p.x >= 0 && p.y >=0 && p.x < n && p.y < m && ar[p.x][p.y] == 0; }

    static boolean solve(int k) {

        // BFS to find shortest distance to a '1' cell from every '0' cell
        LinkedList<Pair> queue = new LinkedList();

        int dist[][] = new int[n][m];	// dist[i][j] is the shortest distance of ar[i][j] to a '1' cell (only applicable for '0' cells)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
				dist[i][j] = -1;	// unvisited
                if(ar[i][j] == 1) {
                    queue.add(new Pair(i,j));
					dist[i][j] = 0;
				}
			}

		while(queue.size() > 0) {

			Pair p = queue.remove();

			for(int i = 0; i < 4; i++) {
				Pair neighbor = new Pair(p.x + transitions[i][0], p.y + transitions[i][1]);
				if(valid(neighbor) && dist[neighbor.x][neighbor.y] == -1) {
					dist[neighbor.x][neighbor.y] = dist[p.x][p.y] + 1;
					queue.add(neighbor);
				}
			}
		}
		List<Pair> list = new ArrayList();

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(ar[i][j] == 0 && dist[i][j] > k)
					list.add(new Pair(i + j, i - j));

		if(list.size() == 0)
			return true;

		int maxX = -1, minX = Integer.MAX_VALUE, maxY = Integer.MIN_VALUE, minY = Integer.MAX_VALUE;

		for(Pair p : list) {
			maxX = Math.max(maxX, p.x);
			maxY = Math.max(maxY, p.y);
			minX = Math.min(minX, p.x);
			minY = Math.min(minY, p.y);
		}

		for(Pair p : list) {
			if(!(p.x - minX > k || maxX - p.x > k || p.y - minY > k || maxY - p.y > k))
				return true;
		}
        return false;
    }

    public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int tc = 1; tc <= T; tc++) {
			n = sc.nextInt();
			m = sc.nextInt();
			ar = new int[n][m];
			for(int i = 0; i < n; i++) {
				String str = sc.next();
				for(int j = 0; j < m; j++)
					ar[i][j] = (int)str.charAt(j) - 48;
			}

			int low = 0, high = n * m;
			while(low <= high) {
				int mid = (low + high) / 2;
				if(solve(mid))
					high = mid - 1;
				else
					low = mid + 1;
			}
			System.out.printf("Case #%d: %d\n", tc, low);
		}
    }

}

