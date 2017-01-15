#!/usr/bin/python
from itertools import permutations as P

n,k = map(int,raw_input().split())
perm = [i+1 for i in range(n)]
ar = P(perm)
print perm
for i in ar:
	flag = 1
	q=1
	for j in i:
		if abs(j-q) < k: flag = 0
		q+=1
	if flag == 1:
		print i
		break

