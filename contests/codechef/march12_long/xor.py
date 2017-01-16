import sys
s = raw_input().split()
n = int(s[0]); k = int(s[1])
s = raw_input().split()
s = map(int,s)
ar = []
for i in range(n):
	for j in range(i+1,n):
		ar.append(s[i] ^ s[j])
ar.sort()
for i in range(k):
	sys.stdout.write(str(ar[i]) + (' ' if i!=k-1 else '\n' ))
