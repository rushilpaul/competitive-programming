for i in range(int(input())):
	p = float(input())
	if p>0.5:
		print(10000*(3*p - 2*p*p))
	else:
		print(10000*(1 + p - 2*p*p))
