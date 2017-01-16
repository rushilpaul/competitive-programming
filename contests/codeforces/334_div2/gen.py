#!/usr/bin/python
from random import randint
s = ''
n = randint(50,100)
print n
for i in range(n):
	s += chr(randint(48,49))
print s
