import sys
import re
import Image
import ImageDraw

def objread(filename):
    punkte = []
    dreiecke = []

    p_pattern = re.compile('^v\s+([0-9]+\.[0-9]+)\s+([0-9]+\.[0-9]+)\s+([0-9]+\.[0-9]+)')
    d_pattern = re.compile('^f\s+([0-9]+)\s+([0-9]+)\s+([0-9]+)')
    for line in file(filename):
        p_match = p_pattern.match(line)
        d_match = d_pattern.match(line)
        if p_match != None:
            punkte.append((float(p_match.group(1)), float(p_match.group(2)), float(p_match.group(3))))
        if d_match != None:
            dreiecke.append((int(d_match.group(1)), int(d_match.group(2)), int(d_match.group(3))))
                
    return (punkte, dreiecke)

def _machebild(punkte, name = "bild", mode = "xy"):
    im = Image.new("1", (400, 400))
    draw = ImageDraw.Draw(im)

    if mode == "yz":
            x = 1
            y = 2
    elif mode == "xz":
            x = 0
            y = 2
    else:
            x = 0
            y = 1

    for v in punkte[1]:
        p1 = punkte[0][v[0]-1]
        p2 = punkte[0][v[1]-1]
        p3 = punkte[0][v[2]-1]
        draw.polygon([(p1[x], p1[y]), (p2[x], p2[y]), (p3[x], p3[y])], outline=128)
        
    im.save("{0}_{1}.png".format(name, mode))
    

def machebild(punkte, name = "bild", mode = "xy"):
    if mode == "all":
        _machebild(punkte, name, "xy")
        _machebild(punkte, name, "xz")
        _machebild(punkte, name, "yz")

punkte = objread(sys.argv[1])
machebild(punkte, "bild", "all")
