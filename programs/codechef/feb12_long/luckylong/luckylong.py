import sys
t = int(raw_input())
while(t > 0):
	t -= 1	
	ans=0
	ch = ' '
	while (True):
		ch = sys.stdin.read(1)
		if (ch == '\n' or ch == ' '): break
		if(ch != '4' and ch != '7'): ans += 1
	sys.stdout.write(str(ans) + '\n')

