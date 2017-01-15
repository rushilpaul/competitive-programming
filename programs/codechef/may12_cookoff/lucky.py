s = raw_input().split()
k = int(s[0])
n = int(s[1])
luck = []
for i in range(k):
	luck.append(raw_input())

for i in range(n):
	s = raw_input()
	done = 1
	if len(s) >= 47:
		print 'Good'
		continue
	for j in range(k):
		if s.count(luck[j]) > 0:
			print 'Good'
			done = 0
			break
	if done:
		print 'Bad'

