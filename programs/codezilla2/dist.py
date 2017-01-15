#Program question at: http://www.codechef.com/COZL2012/problems/RBX12R01
import math,sys
dir_ = 'UDLR'
left = 'LRDU'
right = 'RLUD'

t = int(raw_input())
while t>0:
	t -= 1
	x=0; y=0;
	dr = ''; cur='U';
	s = raw_input().split()
	l = len(s)
	for i in range(l):
		if i % 2 == 1:
			dr = s[i]
			if dr == 'L': cur = left[dir_.find(cur)]
			else: cur = right[dir_.find(cur)]
		else:
			steps = int(s[i])
			if cur == 'U': y += steps
			elif cur == 'D': y -= steps
			elif cur == 'L': x -= steps
			elif cur == 'R': x += steps

	dist = str(math.sqrt(x*x + y*y))
	i = dist.find('.')
	sys.stdout.write(dist[0:i+2])
	if x==0:
		sys.stdout.write( ('N' if y>0 else 'S') + '\n')
	elif y==0:
		sys.stdout.write( ('E' if x>0 else 'W') + '\n')
	elif x>0:
		sys.stdout.write( ('NE' if y>0 else 'SE') + '\n')
	elif x<0:
			sys.stdout.write( ('NW' if y>0 else 'SW') + '\n')

