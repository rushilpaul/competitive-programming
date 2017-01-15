for t in range(input()):
	I = raw_input().split()
	m = int(I[0])
	I[1] = I[1].replace('**','-')
	s = I[1].split("*")
	ans = 1
	for p in s:
		p = map(int,p.split('-'))
		ans = (ans * pow(p[0],p[1],m)) % m
	print ans