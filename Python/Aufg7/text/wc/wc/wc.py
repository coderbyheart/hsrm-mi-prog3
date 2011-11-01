# -*- coding: utf-8 -*-
# Module wc, wc.py

lang_de = "de"
lang_en = "en"
wclang = lang_de

from string import strip

def chars(filename):
    "Count the number of chars in a file"
    n = 0
    for line in map(strip, file(filename)):
        n = n + len(line)
    return n

def words(filename):
    n = 0
    for line in map(strip, file(filename)):
        n = n + len(line.split())
    return n

def lines(filename):
    return len(map(strip, file(filename)))

def wc_intern(filename):
    return (lines(filename), words(filename), chars(filename))

def set_lang(l):
    global wclang
    if l == lang_en:
        wclang = lang_en
    else:
        wclang = lang_de
        
def wc_show(filename):
    global wclang
    counts = wc_intern(filename)
    if(wclang == "en"):
        print """The file {0} has
{1} lines
{2} words
{3} chars""".format(filename, counts[0], counts[1], counts[2])
    else:
        print """Die Datei {0} hat
{1} Zeilen
{2} Wörter
{3} Zeichen""".format(filename, counts[0], counts[1], counts[2])

