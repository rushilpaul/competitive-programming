const int max_primes = 1000001;		// 1e6+1
int pdiv[max_primes];

void sieve()
{
	memset(pdiv,0,sizeof(pdiv));
	for(int a=2;a*a<max_primes;a++)
	{
		if(pdiv[a]) continue;
		pdiv[a] = a;
		for(int b=a*a;b<max_primes;b+=a)
			pdiv[b] = a;
	}
	for(int a=2;a<max_primes;a++)
		if(pdiv[a] == 0) pdiv[a] = a;
}

vector< pair<int,int> > getprimefactors(int n)
{
	vector< pair<int,int> > v;
	int L;
	while( (L=pdiv[n]) > 0)
	{
		int count = 0;
		while(n % L == 0)
		{
			n /= L; count++;
		}
		v.push_back({L,count});
	}
	return v;
}

int calcphi(int n)
{
	int L;
	LL p = n;
	while( (L=largestpdiv[n]) > 0)
	{
		p = p / L * (L-1);
		while(n % L == 0)
			n /= L;
	}
	return p;
}

