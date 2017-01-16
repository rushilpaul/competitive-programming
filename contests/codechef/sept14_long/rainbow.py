from sys import *
n = input()
n -= 13
if n<0:
	print 0
	exit(0)
n /= 2
print pow(7,n,10**9+7)