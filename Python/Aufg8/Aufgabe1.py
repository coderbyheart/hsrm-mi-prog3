import sys

wc = {}

for arg in sys.argv:
    wc[arg] = wc.get(arg, 0) + 1

print wc
wc_sorted = sorted(wc, lambda x, y: cmp(wc[y], wc[x]))
wc_max = wc[wc_sorted[:1][0]]

for word in filter(lambda word: wc[word] == 2, wc_sorted):
    print "{0}: {1}".format(wc[word], word)
