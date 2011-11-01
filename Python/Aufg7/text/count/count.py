# -*- coding: utf-8 -*-
# Module count, count.py

def count_words(filename):
    hm = {}
    for lines in file(filename):
        for word in lines.split():
            hm[word] = hm.get(word,0) + 1
    return hm

def count_chars(filename):
    hm = {}
    for lines in file(filename):
        for word in lines.split():
            for char in range(0, len(word)):
                hm[word[char]] = hm.get(word[char],0) + 1
    return hm
