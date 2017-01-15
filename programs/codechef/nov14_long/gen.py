from itertools import permutations as perm
from math import factorial as f
from random import *

n = map(int,raw_input().split())
p = perm(map(lambda x:x+1,range(len(n))))
c=randint(1,f(len(n)))
r = []
for i in p:
	c-=1
	if c==0:
		r = i
		break
print r

for i in range(len(n)):
	p = [num for num in n]
	p.remove(r[i])
	for j in range(len(p)):
		if p[j] > r[i]:
			p[j] -= 1
	for j in p:
		print j,
	print ''