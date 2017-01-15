def gcd(a,b):
	if a == 0 or b == 0: return a+b
	return gcd(b,a%b)

for t in range(input()):
	n = input()
	ar = [0] * n
	done = [0] * n
	s = map(int,raw_input().split())
	ar = [i-1 for i in s]
	lcm = 1
	for a in range(n):
		if done[a]: continue
		len = 1
		done[a] = 1
		orig = ar[a]
		while (orig!=a):
			len += 1
			done[orig] = 1
			orig = ar[orig]
		lcm = (lcm*len)/gcd(lcm,len);
	print(lcm%(10**9+7))
