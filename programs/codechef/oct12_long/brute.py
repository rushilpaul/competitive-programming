s = ['a','b','c','d']
n = 6
ar = [0]*n
count = 0
def f(i):
    global count
    if i == n:
        count += 1
        return
    for a in range(len(s)):
        if i == 0:
            ar[i] = s[a]
            f(i+1)
        elif i == n-1:
            if ar[i-1] == s[a] or ar[0] == s[a]:
                continue
            ar[i] = s[a]
            f(i+1)
        else:
            if ar[i-1] == s[a]:
                continue
            ar[i] = s[a]
            f(i+1)
f(0)
print(count)
