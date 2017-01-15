import sys
def p(n):
	for i in range(2,n):
		if n%i == 0: return 0
	return 1

for i in range(1000):
	if(p(i) == 1):
		sys.stdout.write( str(i) + ',')

