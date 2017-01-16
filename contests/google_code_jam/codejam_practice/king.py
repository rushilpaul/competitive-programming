t = int(raw_input())
for tt in range(1,t+1):
	tmp = raw_input()
	c = tmp.lower()
	l = len(c)-1
	if c[l] == 'y':
		print 'Case #%d: %s is ruled by nobody.' % (tt,tmp)
	elif 'aeiou'.count(c[l]) > 0:
		print 'Case #%d: %s is ruled by a queen.' % (tt,tmp)
	else:
		print 'Case #%d: %s is ruled by a king.' % (tt,tmp)

