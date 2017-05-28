#!/usr/bin/python

from random import randint

t = randint(90,100)
print t
while t >= 0:
	t -= 1
	n = randint(1,10)
	m = randint(1,10)
	print n,m
	sx = randint(1,n)
	sy = randint(1,m)

	for i in range(n):
		if i+1 != sx:
			print '*' * m
		else:
			print '*' * (sy-1) + '.' + '*' * (m-sy)
