#!/usr/bin/python
import sys

T = int(raw_input())
for t in range(T):
	s = map(int,raw_input().split())
	a = s[0]
	d = s[1]
	L = s[2]
	R = s[3]
	n = R-L+1
	a = a + (L-1) * d
	s = {}
	s[(a-1) % 9 + 1] = 0
	i = 1
	start = 0
	while True:
		a += d
		res = (a-1) % 9 + 1
		if res in s:
			start = s[res]
			break

		s[res] = i
		i += 1

	v = []
	for i in s:
		v.append([i,s[i]])
	v = sorted(v, key = lambda f : f[1])

	init = 0
	for i in range(start):
		init += v[i][0]

	if n <= start:
		print init
		continue

	total = 0
	for i in range(start, len(s)):
		total += v[i][0]
		
	size = len(v) - start
	ans = n / size * total + init

	for i in range(n % size):
		ans += v[i][0]
	print ans

sys.exit(0)
