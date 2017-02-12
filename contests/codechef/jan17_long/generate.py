#!/usr/bin/python
from random import randint
MAX = 2*10**5

n = randint(5,7)
max_edges = min(n*(n-1)/2, MAX)
e = randint(n-1,max_edges)
print n,e

edges = []
for i in range(n):
	for j in range(i+1,n):
		edges.append((i+1,j+1))

for i in range(e):
	# get an edge
	while True:
		j = randint(1,n)
		edge = None
		for k in edges:
			if k[0] == j:
				edge = k
				break
		if edge != None:
			break
	print edge[0], edge[1]
	edges.remove(edge)

