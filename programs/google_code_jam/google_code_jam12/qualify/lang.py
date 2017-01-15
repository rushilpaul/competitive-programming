# Question at: http://code.google.com/codejam/contest/1460488/dashboard

s = 'ourlangeismpbtdhwyxfckjvzq'
p = 'ejpmyslckdxvnribtahwfougqz'

import sys

t = int(raw_input())
cas = 0
while t>0:
	t-=1
	cas += 1
	s1 = raw_input()
	l = len(s1)
	sys.stdout.write("Case #" + str(cas) + ": ");
	for i in range(l):
		ch = s1[i]
		if ch == ' ': sys.stdout.write(' '); continue
		sys.stdout.write( s[p.index(ch)] )
	sys.stdout.write('\n')

