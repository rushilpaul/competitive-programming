#!/usr/bin/python
from random import randint

t = 1
print t
while t>0:
	t -= 1
	B = chr(randint(ord('1'),ord('6')))
	for i in range(10**4-1):
		B += chr(randint(ord('0'),ord('6')))
	B = int(B)
	A = B * (B - 10)
	print A
	print B
	print randint(100,10**4)
