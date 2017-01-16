import sys

dp = [ [0]*101 for i in range(101) ]
done = [ [0]*101 for i in range(101) ]

def f(i, j):
	if i > n or j > n or j > i:
		dp[i][j] = 0
		return 0
	if n-i == 0 or n-j == 0:
		dp[i][j] = 1
		return 1
	if done[i][j]:
		return dp[i][j]
	done[i][j] = 1
	ans = f(i+1,j) + f(i,j+1);
	dp[i][j] = ans
	return ans

tt = input()
for t in range(1,tt+1):

	sys.stdout.write('Case #%d: ' % t)
	s = map(int,raw_input().split())
	n,k = s[0],s[1]
	for i in range(101):
		for j in range(101):
			dp[i][j] = 0
			done[i][j] = 0
	f(0,0)
	dp[n][n] = 1
	
	i=0; j=0
	if k > dp[1][0]:
		print "Doesn't Exist!"
		continue
	while(k>=0):
		if k == 1:
			for a in range(n-i):
				sys.stdout.write('(')
			for a in range(n-j):
				sys.stdout.write(')')
			break

		if k > dp[i+1][j]:
			k -= dp[i+1][j]
			j+=1
			sys.stdout.write(')')
		else:
			i+=1
			sys.stdout.write('(')
	print ''
	print dp[0][0]

