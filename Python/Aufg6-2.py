# -*- coding: utf-8 -*-
def ggTRecursive(a, b):
    "Berechnet den ggT rekursiv"
    if (a == b):
        return a
    if (a < b):
        a = ggTRecursive(a, b-a)
    if (b < a):
        a = ggTRecursive(a-b, b)
    return a

def ggTRecursiveFast(a, b):
    "Berechnet den ggT rekursiv, aber schnell"
    if (a == b):
        return a
    if (a < b):
        b = b % a
    elif (b < a):
        a = a % b
    if (a == 0):
        return b
    if (b == 0):
        return a
    return ggTRecursiveFast(b, a)

def ggTIterative(a, b):
    "Berechnet den ggT iterativ, schnell"
    while (a != b):
        if (a < b):
            # b = b - a
            b = b % a
        elif (b < a):
            # a = a - b
            a = a % b
        if (a == 0):
            return b
        if (b == 0):
            return a
    return a

print "Rekursiv"
print ggTRecursive(10,30)
print ggTRecursive(20,30)
print ggTRecursive(2,5)
print ggTRecursive(6,6)

print "Rekursiv, schnell"
print ggTRecursiveFast(10,30)
print ggTRecursiveFast(20,30)
print ggTRecursiveFast(2,5)
print ggTRecursiveFast(6,6)

print "Iterativ"
print ggTIterative(10,30)
print ggTIterative(20,30)
print ggTIterative(2,5)
print ggTIterative(6,6)

print ""
print "Aus Datei"
ggts = file("ggts.dat")
ggtsum = 0;
ggtcount = 0;
for line in ggts:
    ggt = ggTRecursiveFast(int(line), int(ggts.next()))
    ggtsum += ggt
    ggtcount += 1
print "Mittelwert von {0} ggTs: {1}".format(ggtcount, ggtsum / ggtcount);

def ggTMax(l):
    maxGgT = None
    for i in range(len(l)):
        for j in range(len(l)):
            if j == i:
                continue
            if len(l) < j + 2:
                continue
            ggT = ggTRecursiveFast(ggTRecursiveFast(l[i], l[j]), l[+1]);
            if (maxGgT == None or maxGgT > ggT):
                maxGgT = ggT;
    return maxGgT

l = [10, 80, 20, 75]
print ""
print "ggT für "
print l
print ggTMax(l)
