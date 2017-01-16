#!/usr/bin/python -i

def f(n):
	i=2
	while i*i <= n:
		if n % i == 0: return False
		i += 1
	return True

P = []
for i in range(2,10000):
	if f(i): P.append(i)

def gen(n):
	L = []
	for i in P:
		q = 1
		while n % i == 0:
			n /= i
			q *= i
		if q > 1:
			L.append(q)
	if n > 1:
		L.append(n)
	return L

