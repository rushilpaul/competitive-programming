#!/usr/bin/python

from sys import exit

def printgrid(s):
	for i in s:
		print ''.join(i)

# file input
f = open('in', 'r')
f_out = open('out', 'r')
T = int(f.readline())
for t in range(T):
	n,m = map(int, f.readline().split())

	s = [''] * n
	for i in range(n):
		s[i] = list(f.readline()[:-1])

	#printgrid(s)
	#print 'becomes'

	X = int(f_out.readline())

	if X == -1:
		print -1
		continue

	for i in range(X):
		sx,sy,dx,dy = map(int, f_out.readline().split())
		sx -= 1
		sy -= 1
		dx -= 1
		dy -= 1
		#print sx,sy,dx,dy
		assert(sx >= 0 and sx < n and sy >= 0 and sy < m)
		assert(dx >= 0 and dx < n and dy >= 0 and dy < m)
		if s[sx][sy] != '*' or s[dx][dy] != '.':
			print 'Invalid state', sx + 1, sy + 1, dx + 1, dy + 1
			printgrid(s)
			exit(1)
		s[sx][sy] = '.'
		s[dx][dy] = '*'
		if sx == dx: # same row
			assert(abs(sy - dy) <= 2)
			if abs(sy - dy) == 2:
				assert(sx >= 0 and sx < n)
				assert( (sy + dy) / 2 >= 0 and (sy + dy) / 2 < m)
				assert( s[sx][ (sy + dy)/2 ] == '*')
				s[sx][(sy + dy) / 2] = '.'
		elif sy == dy:
			assert(abs(sx - dx) <= 2)
			if abs(sx - dx) == 2:
				assert( (sx + dx) / 2 < n and (sx + dx) / 2 >= 0)
				assert(sy >= 0 and sy < m)
				assert( s[ (sx + dx)/2 ][sy] == '*')
				s[(sx + dx) / 2][sy] = '.'
		else:
			print 'Bad values'
			assert(0)

	#printgrid(s)
	c = 0
	for i in s:
		for j in i:
			if j == '*': c += 1
	assert(c == 1)
	print 'Correct test #', t+1


