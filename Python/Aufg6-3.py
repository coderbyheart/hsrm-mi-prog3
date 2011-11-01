def f(a, b, c=1):
    print a,b,c

def g(a,b,*c, **d):
    print a,b,c,d

def h(a,b,c=1,*d,**e):
    print a,b,c,d,e

print "f"
f(1,2,3)
# f(1) geht nicht
f(1,2)
# f(1,2,3,4) geht nicht

print "g"
g(1,2)
g(1,2,3,4)
g(1,2,3,4,bla="bla")

print "h"
# h(1,2,3,4,5,6,c=7)
h(1,2,3,4,5,6,x=7)

