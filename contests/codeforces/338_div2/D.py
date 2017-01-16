mod = 10**9 + 7
n = input()
ans = 1
m = {}
s = map(int,raw_input().split())

for i in range(n):
	f = s[i]
	try:
		m[f] = m[f] + 1
	except:
		m[f] = 1

C = 1
for p in m:
	e = m[p]
	ans = ans * pow(ans, e, mod) % mod
	for i in range(e):
		ans = ans * pow(p, C * (i+1), mod) % mod
	C = C * (e + 1)

print ans
