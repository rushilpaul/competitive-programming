#!/usr/bin/python
from random import randint

m = 3
n = 3
L = -3
R = 4

f = lambda x : [randint(L,R) for i in range(n)]

print 1
print n,m

for i in range(n):
	for j in f(m):
		print j,
	print ''

for i in [0]*9:
	print i,
