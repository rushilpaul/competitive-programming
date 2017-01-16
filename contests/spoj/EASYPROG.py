ar = [137, 1315, 73, 136, 255, 1384, 16385]

def f(n):
	s = ''
	n = bin(n)[2:]
	for b in range(len(n)):
		if n[b] == '1':
			i = len(n) - b - 1
			if i == 1:
				s += '2+'
			elif i == 0:
				s += '2(0)+'
			else: s += '2(' + f(i) + ')+'
	return s[0:len(s)-1]

for i in ar:
	print str(i)+'='+f(i)
