#!/usr/bin/python
from math import factorial as fact
ncr = lambda n,r : fact(n) / (fact(r) * fact(n-r))

n,m = map(int,raw_input().split())
L = min(n,m)
ans = 0
for i in range(n-L,n):
	ans += ncr((n-1)*m,i) * (n-i) * (n-i) * ncr(m,n-i)
print ans
print 1.0 * ans / (n * ncr(m*n,n))

