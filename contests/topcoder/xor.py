# SRM 543 - Round 1
def f(L,R):
	N=L-1
	ans1 = N & ( 0 if N%2 else ~0) | ( ((N&2)>>1)^(N&1))
	N=R
	ans2 = N & ( 0 if N%2 else ~0) | ( ((N&2)>>1)^(N&1))
	return ans1^ans2
