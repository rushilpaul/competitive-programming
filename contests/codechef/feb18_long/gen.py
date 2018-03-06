#!/usr/bin/python

from random import randint

t = 100
print t
while t > 0:
	t -= 1
	n = 10
	print n
	for i in range(n):
		print randint(1,10**9),
	print ''
	print randint(2,2), randint(1,10**9), randint(1,10**9)

