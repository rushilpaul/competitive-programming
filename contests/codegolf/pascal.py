A=[1]
for i in range(input()):
	B=[sum(A[j:j+2])for j in range(i)]
	B[:0]=[1]
	B[i+1:]=[1]
	print A
	A=B
