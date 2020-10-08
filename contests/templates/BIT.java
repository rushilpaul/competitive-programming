
class BIT {

    private int tree[], n;

    public BIT(int n) {
        this.n = n;
        tree = new int[n+1];
    }

    int getSum(int index) {
        if(index < 0 || index >= n)
            throw new ArrayIndexOutOfBoundsException();
        index = n - 1 - index;
        int sum = 0;
        index = index + 1;

        while(index > 0)
        {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

    // index is 0-based
    public int pointQuery(int index) { return getSum(index); }

    // Updates ar[0 .. index]
    // index is 0-based
    public void update(int index, int val) {

        if(index < 0 || index >= n)
            throw new ArrayIndexOutOfBoundsException();
        index = n - index;
        while(index <= n) {
            tree[index] += val;
            index += index & (-index);
        }
    }
    public void print() {
        for(int i = 0; i < n; i++)
            System.out.print(pointQuery(i) + " ");
        System.out.println();
    }
}

