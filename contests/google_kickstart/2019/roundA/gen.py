#!/usr/bin/python

from random import randint

T = 100
print T
for t in range(T):
	#n = randint(20,1000000)
	n = 10**6
	#q = randint(10,13)
	q = 300
	print n,q

	for i in range(q):
		L = randint(1,n)
		s = randint(1, n-L+1)
		e = s + L - 1
		print s,e

