from math import factorial as f

def ncr(n,r):
	if n < r:
		return 1
	return f(n) / (f(r) * f(n-r))

for t in range(input()):
	s = map(int,raw_input().split())
	r = s[0]
	b = s[1]
	tr = s[2]
	tb = r + b - tr
	if r < b:
		r,b = b,r
		tr,tb = tb,tr

	ans = 0
	prob = f(r + b)
	for i in range(max(0,r - tb), min(r,tr) + 1):
		ans_i = i + b - (tr - i)
		ans = ans + 1.0 * ( f(tr) * f(tb) * ncr(r,i) * ncr(b,tr-i) * ans_i ) / prob
	print ans
