#!/usr/bin/python
input()
s = raw_input()
s = list(s)
n = len(s)
import sys
if n==1:
	print 1
	sys.exit(0)

def count(s):
	ans=1
	for i in range(1,len(s)):
		if s[i] != s[i-1]: ans+=1
	return ans

ans=0
best = []
for i in range(n):
	for j in range(i,n):
		p = [k for k in s]
		for k in range(i,j+1):
			if p[k] == '1': p[k] = '0'
			else: p[k] = '1'
		if count(p) > ans:
			ans = count(p)
			best = [k for k in p]
s = ''
for i in range(len(best)):
	s += best[i]
#print s
print ans
