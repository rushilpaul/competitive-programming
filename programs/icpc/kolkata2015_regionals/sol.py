mod = 10**9 + 7

t = input()
n,k = map(int,raw_input().split())
ar = map(int,raw_input().split())
ans = 0
for i in range(n):
	for j in range(i+1,n):
		ans += pow(abs(ar[i]-ar[j]),mod)
		ans %= mod
ans *= 2
print ans
