# -*- coding: utf-8 -*-

print "Geradzahlige Kubikzahlen von 1 bis 10"
# List Comprehension
print [x**3 for x in range(1,11) if x**3 % 2 == 0]
# Funktionale Primitive
print filter(lambda x: x % 2 == 0, map(lambda x: x**3, range(1,11)));

print ""
print "Alle Teiler einer Zahl z außer 1 und z"
for z in (123, 12345, 123456):
    print "Alle Teiler von {0}".format(z)
    # List Comprehension
    print [x for x in range(2, z) if z % x == 0]
    # Funktionale Primitive
    print filter(lambda x: z % x == 0, range(2, z));

# Alle Primzahlen zwischen 10000 und 10100
print ""
print "Alle Primzahlen zwischen 10000 und 10100"
# List Comprehension
print [x for x in range(10000, 10101) if len([y for y in range(2,x) if x % y == 0]) == 0]
# Funktionale Primitive
print filter(lambda x: len(filter(lambda y: x % y == 0, range(2,x))) == 0, range(10000, 10101))
