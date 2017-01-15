#Program question at: http://www.codechef.com/CDOL2012/problems/COOP5
t = int(raw_input())
while t>0:
	t-=1
	raw_input()
	k = int(raw_input().split()[1])
	s = map(int,raw_input().split())
	s.sort();
	l = len(s)
	print reduce(lambda x,y: x+y, s[l-k:l])
