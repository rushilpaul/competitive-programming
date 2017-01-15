t = int(raw_input())
_3=0
_5=0
_8=0
ans=0

while t>0:
	t-=1
	s = raw_input().split()
	l = len(s)
	for ch in s[l-1]:
		if ch == '3': _3+=1
		elif ch == '5': _5+=1
		elif ch == '8': _8+=1
		else: _8=-1; break
	if (_8 >= _5 and _5 >= _3): ans+=1
print ans
