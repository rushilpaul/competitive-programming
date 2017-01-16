def hcf(a,b):
	return a+b if (a==0 or b==0) else hcf(b,a%b)

def lcm(a,b):
	if a<b:
		a ^= b
		b ^= a
		a ^= b
	i=a
	while(a%b): a+=i
	return a

t = int(raw_input())
while(t>0):
	t-=1
	s = raw_input().split()
	a = int(s[0])
	b = int(s[1])
	c = int(s[2])
	d = int(s[3])
	k = int(s[4])
	print 1 + ((k / (lcm(hcf(a,b), hcf(c,d))) ) << 1)

