'''
It's straightforeward to notice that the number of 
0-1 strings respecting problem's constraints is
fib(n+1) then we use dynamic progrmmin to compute 'em.
''' 
n=input()
tab={0:1, 1:1}
for i in xrange(2, n+2):
	tab[i]=tab[i-1]+tab[i-2];
print(tab[n+1])
