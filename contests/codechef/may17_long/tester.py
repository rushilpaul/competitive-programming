#!/usr/bin/python
n,k = map(int, raw_input().split())
ar = map(int, raw_input().split())

cache = {}

def f(i, prod):
	if i == n:
		return 1 if prod <= k else 0
	if (i,prod) in cache:
		return cache[(i,prod)]

	ans = f(i + 1, prod)
	if prod * ar[i] <= k:
		ans += f(i + 1, prod * ar[i])
	
	cache[(i,prod)] = ans
	return ans

print f(0,1) - 1
