n = int(input())
"""
print('[',end='')
for i in range(n):
	if i%2 == 0: print('A',end=', ')
	else: print('B',end=', ')
print(']')
"""
ar = [i for i in range(n)]
ans = [0]*n
ar2 = []
def f(left,right,i):
	if left==right:
		ans[i] = ar[left]
		for j in range(0,n,2):
			ar2.append(ans[j])
		return
	ans[i] = ar[left]
	f(left+1,right,i+1)
	ans[i] = ar[right]
	f(left,right-1,i+1)
f(0,n-1,0)
for i in range(n):
	print(ar2.count(i),end=',')
print()
