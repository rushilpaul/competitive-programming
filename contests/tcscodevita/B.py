from decimal import *
import math
context = Context(prec=11)
setcontext(context)
m = Decimal(raw_input())
t = Decimal(raw_input())
i = Decimal(raw_input())
i = i / Decimal(1200)
f = lambda A,n: A*((1+i)**n-1) / (i*(1+i)**n)
if i != 0:
	print f(m,t)
else:
	print m*t
