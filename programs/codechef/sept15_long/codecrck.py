
def mul(A, B, C):
	for a in range(2):
		for b in range(2):
			C[a][b] = 0
			for c in range(2):
				C[a][b] += A[a][c] * B[c][b]

def invMAT(M, res):
	det = M[0][0] * M[1][1] - M[0][1] * M[1][0]
	res[0][0] = 1.0 * M[1][1]/det
	res[0][1] = -1.0 * M[0][1]/det
	res[1][0] = -1.0 * M[1][0]/det
	res[1][1] = 1.0 * M[0][0]/det

def f(n, s, M):
	cpy = n
	n = abs(n)
	k1 = 2**0.5 - 6**0.5
	k2 = 2**0.5 + 6**0.5
	base = [ [k1,k2], [k2,-k1] ]
	if n&1:
		for i in range(2):
			for j in range(2):
				M[i][j] = base[i][j]
		n -= 1
	exp = 2*n
	if cpy < 0:
		exp = -exp
	exp -= s
	return exp

inp = map(int,raw_input().split())
i = inp[0]
k = inp[1]
s = inp[2]
cpy = abs(s)
inp = map(float,raw_input().split())
ai = inp[0]
bi = inp[1]

M = [ [1.0,0.0], [0.0,1.0] ]
s = f(k-i,s,M)

if k-i < 0:
	tmp = [ [0,0],[0,0] ]
	invMAT(M,tmp)
	M = tmp

ans = ai * (M[0][0] + M[0][1]) + bi * (M[1][0] + M[1][1])

while s != 0:
	tmp = ans
	if s > 0:
		ans *= 2.0
		s -= 1
	else:
		ans /= 2.0
		s += 1
		if abs(ans-tmp) < 0.001:
			break
print ans

