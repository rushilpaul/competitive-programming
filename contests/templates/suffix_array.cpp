
#define MAX 2000002

class SuffixArray {

public:
    struct suffix {
        pair<int, int> rank;
        int index;

        suffix(int index, pair<int, int> rank) : index(index), rank(rank) {}

        suffix() {}
    };

    int n;
    char text[MAX];
    suffix *suffixes = new suffix[MAX];
    int *ranks = new int[MAX];

    void init() {
        for (int a = 0; a < n; a++)
            ranks[a] = text[a] - 'a';
    }

    void createSuffixArray() {

        init();
        for (int step = 1; step < 2 * n; step *= 2) {

            for (int a = 0; a < n; a++) {
                suffixes[a] = suffix(a, {ranks[a], (a + step < n ? ranks[a + step] : -1)});
            }

            sort(suffixes, suffixes + n, [](suffix &a, suffix &b) -> int { return a.rank < b.rank; });

            ranks[suffixes[0].index] = 0;
            int r = 0;
            for (int a = 1; a < n; a++) {
                if (suffixes[a].rank != suffixes[a - 1].rank)
                    r++;
                ranks[suffixes[a].index] = r;
            }
        }
        delete[] suffixes;
    }
};