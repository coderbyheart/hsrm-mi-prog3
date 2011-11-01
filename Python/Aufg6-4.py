#!/usr/bin/python

def myFortune():
    import os
    libs = []
    for f in os.listdir("/usr/share/games/fortunes/"):
        if (".u8" in f or ".dat" in f):
            continue
        libs += [f]
    print libs

myFortune()
