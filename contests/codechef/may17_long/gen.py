#!/usr/bin/python

from random import randint

n = 100
print n

ops = ['-', '+']

for i in range(n):
	s = ""
	L = randint(10**3, 2*10**3)
	while L > 0:
		c = randint(ord('a'), ord('b'))
		s += chr(c)
		L -= 1
	print ops[randint(0,1)], s

