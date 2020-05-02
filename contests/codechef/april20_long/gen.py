#!/usr/bin/python

from random import randint

t = 1
print(t)

while(t > 0):
	t -=1
	maxN = 20
	n = randint(maxN / 2, maxN)
	print n

	nodes = [i for i in range(n)]

	G = []
	for i in range(n-1):
		while True:
			pos = randint(0, len(nodes) - 1)
			if i != nodes[pos] and not (i, nodes[pos]) in G and not (nodes[pos], i) in G:
				G.append((i, nodes[pos]))
				break

	for i in G:
		print i[0] + 1, i[1] + 1

	for i in range(n):
		print randint(1, 10**6),
	
	Q = 10**2
	print Q
	for i in range(Q):
		print(str(randint(1,n)) + ' ' + str(randint(1,n)))
