ar = [129, 133, 6, 10, 141, 142, 15, 145, 146, 21, 22, 185, 26, 155, 158, 159, 33, 34, 35, 134, 38, 39, 46, 177, 178, 51, 183, 57, 58, 187, 62, 65, 194, 69, 161, 74, 55, 143, 77, 82, 14, 86, 87, 91, 93, 94, 95, 166, 106, 111, 115, 118, 119, 122, 123, 85]
s = set()
for i in ar:
	s.add(i)

t = int(raw_input())
while t>0:
	t -= 1
	n = int(raw_input())
	check = False
	for i in ar:
		if n-i in s:
			check = True
			break
	if(check): print 'YES'
	else: print 'NO'
