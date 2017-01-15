def fact(num):
	if num<=1: return 1
	return num*fact(num-1)

def nCr(n,r):
	if(n < r): return 0
	return fact(n) / (fact(r) * fact(n-r))

s = raw_input().split()
x = int(s[0])
n = int(s[1])
ans = 0
while n>0:
	n -= 1
	aval = raw_input()
	i=0; j=53;
	while(i<33):
		t=0
		for b in range(i,i+4):
			if(aval[b] == '0'): t += 1
		if(aval[j] == '0'): t += 1
		if(aval[j-1] == '0'): t += 1
		ans += nCr(t,x)
		i += 4
		j -= 2
print ans

