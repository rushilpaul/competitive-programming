// query bit[1..index]
int query(int *bit, int n, int index)
{
	int sum = 0; 
	while(index > 0)
	{
		sum += bit[index];
		index -= (index & (-index));
    }
	return sum;
}

// update bit[index..n]
void update(int *bit, int n, int index, int val)
{
	if(index < 1) return;
	while (index <= n)
	{
		bit[index] += val;
		index += (index & (-index));
	}
}

