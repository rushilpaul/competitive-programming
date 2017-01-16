#!/usr/bin/python

max_n = 15
f = [ [0]*max_n for i in range(max_n) ]
L = [ [1]*max_n for i in range(max_n) ]

def gcd(a,b):
	if a == 0 or b == 0: return a+b
	return gcd(b,a%b)

for i in range(1,max_n):
	f[i][1] = i
	L[i][1] = i
for i in range(2,max_n):
	for j in range(2,i+1):
		f[i][j] = f[i][j-1] * f[i-1][j-1] / (f[i][j-1] - f[i-1][j-1])
		L[i][j] = f[i][j] / gcd(f[i][j],L[i][j-1]) * L[i][j-1]
		
t = int(raw_input())
n,k = map(int,raw_input().split())
A,B,M = map(int,raw_input().split())

if t > 1:
	C = map(int,raw_input().split())
	D = map(int,raw_input().split())

mod = 10**9 + 7

for i in range(t):
	ans = L[n][k] % mod
	print ans
	if i == t-1: break
	n = 1 + (A * ans + C[i]) % M
	k = 1 + (B * ans + D[i]) % n

exit(0)
