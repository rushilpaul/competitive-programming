#!/usr/bin/python
from random import randint

t = 100
m = randint(2,10)
n1 = randint(1,m-1)
k1 = randint(1,n1)
A = randint(0,m-1)
B = randint(0,m-1)
C = [ randint(0,m-1) for i in range(t-1) ]
D = [ randint(0,m-1) for i in range(t-1) ]

print t
print n1,k1
print A,B,m
for i in C: print i,
print ''
for i in D: print i,
	
