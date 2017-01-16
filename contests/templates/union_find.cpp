struct subset
{
    int parent, rank;
};
subset subs[1000];

int find(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
	{
        subsets[xroot].parent = yroot;
	}
    else if (subsets[xroot].rank > subsets[yroot].rank)
	{
        subsets[yroot].parent = xroot;
	}
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

