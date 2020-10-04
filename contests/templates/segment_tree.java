
class SegmentTree {

    Node root;

    SegmentTree(int n) {
        root = build(0, n-1);
    }

    static class Node {
        Node left, right;
        int val;

        public Node(int val) {
            this.val = val;
        }
    }

    Node merge(Node left, Node right) {
        Node res = new Node(0); // TODO: give value
        res.left = left;
        res.right = right;
        // TODO: merge left and right
        return res;
    }

    Node build(int i, int j) {

        // initialize root
        if(i == j)
            return new Node(0); // TODO: give value

        int mid = (i + j) / 2;
        Node left = build(i, mid);
        Node right = build(mid+1, j);
        return merge(left, right);
    }

    Node pointQuery(Node root, int i, int j, int p) {

        if(p < i || p > j)
            return null;

        if(i == j)
            return root;    // p == i == j

        int mid = (i + j) / 2;
        Node left = pointQuery(root.left, i, mid, p);
        Node right = pointQuery(root.right, mid+1, j, p);
        return merge(left, right);
    }

    void rangeUpdate(Node root, int i, int j, int x, int y, int newVal) {

        if(y < i || x > j)
            return;

        if(x <= i && y >= j) {
//            TODO: update root
            return;
        }

        int mid = (i + j) / 2;
        rangeUpdate(root.left, i, mid, x, y, newVal);
        rangeUpdate(root.right, mid+1, j, x, y, newVal);
    }
}

