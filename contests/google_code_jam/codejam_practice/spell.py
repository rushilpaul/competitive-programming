#Program question at: http://code.google.com/codejam/contest/1277486/dashboard#s=p2

def count(s):
	n=0
	for i in range(len(s)):
		if 'aeiou'.count(s[i]) > 0:
			n+=1
			if i != len(s)-1:
				if 'aeiou'.count(s[i+1]) > 0: i+=1; n-=1
	return n

def there(s1,s):
	while len(s1) >= 3:
		if s.count(s1)>0 and count(s1) >= 2: return True
		s1 = s1[1:]
	return False

t = int(raw_input())
for tt in range(1,t+1):
	s = raw_input()
	l = len(s)
	if l < 7:
		print 'Case #%d: Nothing.' % tt
		continue
	l = len(s)
	done = False
	for mi in range(3,l-3):
		if done: break
		if count(s[0:mi]) < 2:
			continue
		for ei in range(mi+1,l-2):
			if count(s[mi:ei]) >= 1:
				if there(s[0:mi],s[ei:]):
					print 'Case #%d: Spell!' % tt
					done = True
					break
	if not done: print 'Case #%d: Nothing.' % tt

