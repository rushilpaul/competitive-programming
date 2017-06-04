n = input()
ar = map(int, raw_input().split())

total = 0
mod = 10**9 + 7

def f(i,n,op):
	global total
	if i == n:
		ans = 0
		p = ar[0]
		for j in range(n):
			if op[j] == 1:
				p *= ar[j+1]
			else:
				ans += p
				p = ar[j+1]
		ans += p
		total += ans
		return
	f(i+1,n, op + [0])
	f(i+1,n, op + [1])

f(0, n-1, [])
print total % mod
