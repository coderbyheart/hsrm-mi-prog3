l = [1,2,3]
for e in l:
    print e

i = 0
while i < len(l):
    print l[i]
    i += 1

d = {1:"eins", 2:"zwei", 3:"drei"}
l = d.keys()
i = 0

while i < len(l):
    s = l[i]
    print s, d[s]
    i += 1

for k in l:
    print k, d[k]
