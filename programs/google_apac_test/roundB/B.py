for t in range(1,int(raw_input())+1):
	raw_input()
	s = map(int,raw_input().split())
	np,ne,nt = s[0],s[1],s[2]
	A = map(int,raw_input().split())
	B = map(int,raw_input().split())
	C = map(int,raw_input().split())
	d = {}
	for i in range(ne):
		for j in range(nt):
			p = B[i] * C[j]
			if p in d:
				d[p] = d[p] + 1
			else:
				d[p] = 1

	m = int(raw_input())
	print 'Case #%d: ' % t
	for mm in range(m):
		p,q = map(int,raw_input().split())
		flag = 0
		for j in range(ne):
			p2 = B[j]
			L = {}
			for k in range(nt):
				prod = p2 * C[k]
				if prod in d:
					d[prod] = d[prod] - 1
					if d[prod] == 0:
						del d[prod]
					if prod in L:
						L[prod] = L[prod] + 1
					else:
						L[prod] = 1

			for i in range(np):
				p1 = A[i]
				p1 *= p2
				if (p1 * q) % p != 0:
					continue
				k = p1 * q / p
				flag = 0
				if k in d:
					#print A[i],p2,k
					flag = 1
					break
			for i in L:
				if i in d:
					d[i] = d[i] + L[i]
				else:
					d[i] = L[i]

			if flag == 1: break

		if flag == 1:
			print 'Yes'
		else:
			print 'No'

