# for q2
from random import randint
s = ''
for i in range(3*10**3):
	if(i == 0):
		ch = randint(1,9)
	else:
		ch = randint(0,9)
	s += str(ch)
print s
s = ''
for i in range(7*10**3):
	if(i == 0):
		ch = randint(1,9)
	else:
		ch = randint(0,9)
	s += str(ch)
print s
