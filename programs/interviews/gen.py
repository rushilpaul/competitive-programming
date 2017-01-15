n = 100
k = 10
print n
from random import randint
ar = []
for i in range(n):
	s = []
	for j in range(n):
		if randint(0,7) == 0:
			s.append('#')
		else:
			s.append('.')
	ar.append(s)
si = randint(0,n-1)
sj = randint(0,n-1)
ei = randint(0,n-1)
ej = randint(0,n-1)
ar[si][sj] = 'S'
ar[ei][ej] = 'E'
for t in range(k):
	i,j = randint(0,n-1), randint(0,n-1)
	ar[i][j] = 'k'
for i in range(n):
	print ''.join(ar[i])

