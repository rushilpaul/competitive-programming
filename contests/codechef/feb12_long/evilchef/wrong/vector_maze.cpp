void solve()
{
	VVI ar(m+n,VI());
	VVI::iterator a = ar.begin();
	VI::iterator b;
	int nr = check(sx-1,sy), s = check(sx+1,sy), e = check(sx,sy+1), w = check(sx,sy-1);

	if(n) { (*a).push_back( (sx-1)*n + sy ); }
	if(s) { (*a).push_back( (sx+1)*n + sy ); }
	if(e) { (*a).push_back( sx*n + sy+1 ); }
	if(w) { (*a).push_back( sx*n + sy-1 ); }
	//if(nr==2 || s==2 || e==2 || w==2) goto out;
	for(a = ar.begin(); a < ar.end()-1; a++)
		for(b = (*a).begin(); b < (*a).end(); b++)
		{
			int x = (*b)/n, y = (*b)%n;
			n = check(x-1,y); s = check(x+1,y); e = check(x,y+1); w = check(x,y-1);
			if(n) X.push_back( (x-1)*n + y );
			if(s) X.push_back( (x+1)*n + y );
			if(e) X.push_back( x*n + y+1 );
			if(w) X.push_back( x*n + y-1 );
		}
}
