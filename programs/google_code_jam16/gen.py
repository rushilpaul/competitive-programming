#!/usr/bin/python
from random import randint

t = 100
print t
for i in range(t):
	n = randint(15,18)
	s1 = ''
	s2 = ''
	for j in range(n):
		if randint(0,2) == 0:
			s1 += '?'
		else:
			s1 += chr(randint(48,57))
	for j in range(n):
		if randint(0,2) == 0:
			s2 += '?'
		else:
			s2 += chr(randint(48,57))
	print s1 + ' ' + s2
