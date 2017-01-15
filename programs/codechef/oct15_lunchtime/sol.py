for tt in range(input()):
	n,d = map(int,raw_input().split())
	f = str(d) * n
	f = int(f)
	f *= f
	f = str(f)
	ans = 0
	mod = 10**9+7
	p=1
	for i in range(len(f)):
		ans += p * (ord(f[i])-48)
		p *= 23
		p %= mod
		ans %= mod
	print ans

