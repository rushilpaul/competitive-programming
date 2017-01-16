#!/usr/bin/python -i
from math import factorial as fact

def f(i,j,n):
	if j == 0 or i < j: return 0
	if i == 1: return 1.0 * j/n
	if i == j:
		return 1.0 * fact(i) * pow(n,-i)
	return f(i-1,j,n) * 1.0 * j/n + f(i-1,j-1,n) * (1 - 1.0 * j/n)

