#Program question at: http://www.codechef.com/MARCH12/problems/SPOON

t = int(raw_input())
while t>0:
	t-=1
	s = raw_input().split()
	m = int(s[0]); n = int(s[1])
	ar = []; f = True
	for i in range(m):
		s = raw_input().lower()
		if s.find('spoon') >=0:
			print 'There is a spoon!'
			f = False
		ar.append(s)
	if not f: continue
	for i in range(n):
		s = ''
		for j in range(m):
			s += ar[j][i]
		if s.find('spoon') >= 0:
			print 'There is a spoon!'
			f = False
			break
	if f: print 'There is indeed no spoon!'
