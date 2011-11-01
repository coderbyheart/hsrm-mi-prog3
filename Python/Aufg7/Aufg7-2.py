# -*- coding: utf-8 -*-
import text
import io
import os
import urllib2

msdfilename = os.getcwd() + os.sep + 'msd.txt'
msdurl = "http://www.gutenberg.org/cache/epub/1113/pg1113.txt"

if not os.path.exists(msdfilename):
    print "Fetching ", msdurl
    remote = urllib2.urlopen(msdurl)

    print "Storing in ", msdfilename
    msdfile = io.open(msdfilename, 'w+')
    for line in remote:
       msdfile.write(unicode(line))
    msdfile.close()
    remote.close()

words = count_words(msdfilename);
sorted_words = sorted(words, lambda x,y: cmp(y,x), lambda wordcount: words[wordcount])
chars = count_chars(msdfilename);
sorted_chars = sorted(chars, lambda x,y: cmp(y,x), lambda charcount: chars[charcount])
print "Die 25 häufigsten Wörter:"
print sorted_words[:25]
print "Die 25 häufigsten Zeichen:"
print sorted_chars[:25]
print "Das 25 häufigste Wort ist: {0}".format(sorted_words[24])
