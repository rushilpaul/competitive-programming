from random import *
n = randint(15,20)
print n
for i in range(n):
	c = randint(0,1)
	b = randint(1,2)
	if c==0: print -b,
	else: print b,
