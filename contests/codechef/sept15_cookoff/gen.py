#!/usr/bin/python
from random import randint
t = 10
print t
while t>0:
	t -= 1
	n = 5000
	print n
	for i in range(n):
		print randint(0,10**9),
	print ''
	for i in range(n):
		print randint(0,10**9),
	print ''

