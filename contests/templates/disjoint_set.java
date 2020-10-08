
class DisjointSet {

    private Subset[] subsets;

    public DisjointSet(int n) {
        subsets = new Subset[n];
        for(int i=0; i<n; i++) subsets[i] = new Subset(i, 0);
    }

    class Subset {
        int parent, rank;
        Subset(int p, int r) { parent = p; rank = r; }
    };

    int find(int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets[i].parent);
        return subsets[i].parent;
    }

    void union(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
}

