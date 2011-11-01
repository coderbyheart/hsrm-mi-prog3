import sys
import re
import Image

def objread(filename):
    l = []
    pattern = re.compile('^v\s+([0-9]+\.[0-9]+)\s+([0-9]+\.[0-9]+)\s+([0-9]+\.[0-9]+)')
    for line in file(filename):
        match = pattern.match(line)
        if match != None:
            l.append((float(match.group(1)), float(match.group(2)), float(match.group(3))))
    return l

def _machebild(punkte, name = "bild", mode = "xy"):
    im = Image.new("1", (400, 400))

    if mode == "yz":
            x = 1
            y = 2
    elif mode == "xz":
            x = 0
            y = 2
    else:
            x = 0
            y = 1

    for v in punkte:
        im.putpixel((v[x], v[y]), 1)
    im.save("{0}_{1}.png".format(name, mode))
    

def machebild(punkte, name = "bild", mode = "xy"):
    if mode == "all":
        _machebild(punkte, name, "xy")
        _machebild(punkte, name, "xz")
        _machebild(punkte, name, "yz")

punkte = objread(sys.argv[1])
machebild(punkte, "bild", "all")
