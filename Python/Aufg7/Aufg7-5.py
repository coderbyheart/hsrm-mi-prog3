# -*- coding: utf-8 -*-
from itertools import *

def isprim(x):
    "Gibt an, ob x eine Primzahl ist"
    return len([y for y in range(2,x) if x % y == 0]) == 0

def prim():
    "Generator für Primzahlen"
    n = 2
    while(True):
        if isprim(n):
            yield n
        n = n+1;

p = prim()
print list(islice(ifilter(lambda pair: pair[1] == pair[0] + 2 and isprim(pair[1]), ((x,y) for x in p for y in range(x, x+3))),100))
