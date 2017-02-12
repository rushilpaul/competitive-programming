#!/usr/bin/python
import sys

inputf = open('in')
n,e = map(int, inputf.readline().strip().split())
inputf.close()

answer = raw_input()

if answer == 'NO':
	sys.exit(0)

in_deg = {}
out_deg = {}

for i in range(n):
	in_deg[i+1] = 0
	out_deg[i+1] = 0

for i in range(e):
	try:
		a,b = map(int, raw_input().split())
	except:
		print 'Number of edges not equal to', e
		sys.exit(1)
	out_deg[a] += 1
	in_deg[b] += 1

print in_deg, out_deg

for i in range(1,n+1):
	if in_deg[i] == 0 or out_deg[i] == 0 or (in_deg[i] + out_deg[i]) % 2 != 0 or in_deg[i] != out_deg[i]:
		print 'Wrong answer. Node ' + str(i) + ' not balanced'
		sys.exit(1)

sys.exit(0)
