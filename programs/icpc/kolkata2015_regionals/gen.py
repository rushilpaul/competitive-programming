#!/usr/bin/python
from random import randint

t = 10
print t
while t>0:
	t -= 1
	n = 10**4
	print n, 100
	for i in range(n):
		print randint(100,10**9+6),
	print ''
