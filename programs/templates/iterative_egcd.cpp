inline LL egcd(LL a, LL b)
{
	LL prevx = 1, x = 0, prevy = 0, y = 1;
	while(b)
	{
		LL q = a/b;
		LL tmp = x;
		x = prevx - q*x;
		prevx = tmp;

		tmp = y;
		y = prevy - q*y;
		prevy = tmp;

		tmp = b;
		b = a%b;
		a = tmp;
	}
	return prevx;
}
