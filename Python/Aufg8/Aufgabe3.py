import sys
import re

def objread(filename):
    l = []
    pattern = re.compile('^v\s+([0-9]+\.[0-9]+)\s+([0-9]+\.[0-9]+)\s+([0-9]+\.[0-9]+)')
    for line in file(filename):
        match = pattern.match(line)
        if match != None:
            l.append((float(match.group(1)), float(match.group(2)), float(match.group(3))))
    return l

print objread(sys.argv[1])
