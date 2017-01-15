def gcd(a,b):
	return a+b if a==0 or b==0 else gcd(b,a%b)

n,a,b = map(int,raw_input().split())
L = a/gcd(a,b)*b
ans = (n/L) * min(a,b) - 1 + min(min(a,b),n-n/L*L+1)

g = gcd(ans,n)
ans /= g
n /= g
print '%d/%d' % (ans,n)
