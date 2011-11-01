def unzip(l):
    n = 0
    r = []
    for i in l[0]:
        ni = []
        for e in l:
            ni += [e[n]]
        n += 1
        r += [tuple(ni)]
    return r

print unzip(zip((1,2,3,4), (5,6), (7,8))) ==[(1,2), (5,6), (7,8)]
t = [(1,2), (3,4), (5,6)]
print zip(t)
print unzip(zip(t))
print unzip(zip(t)) == t
