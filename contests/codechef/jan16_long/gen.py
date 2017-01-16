#!/usr/bin/python
from random import randint

n = 100
ar = [0] * n
maxar = [20] * n
q = 10000
print n,q
time = 0
maxtime = 20
for i in range(q):
	T = randint(1,2)
	time = randint(time, maxtime)
	if T == 1:
		i = randint(0,n-1)
		speed = randint(ar[i], maxar[i])
		ar[i] = speed
		maxar[i] += 40
		print T,time,i+1,speed
	else:
		print T,time
	maxtime += 40
