import sys

def comp_word(word):
    prevchar = None
    charc = 0
    comp_word = ""
    for char in word:
        if (prevchar != None and prevchar != char):
            comp_word = comp_word + prevchar
            if charc > 1:
                comp_word = comp_word + charc.__str__()
            charc = 0
        charc = charc + 1
        prevchar = char
    # Rest
    comp_word = comp_word + prevchar
    if charc > 1:
        comp_word = comp_word + charc.__str__()
    return comp_word

for arg in sys.argv:
    print comp_word(arg)
