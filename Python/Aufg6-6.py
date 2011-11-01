# -*- coding: utf-8 -*-
print [((x1**3 + x2**3), (x1,x2), (y1,y2))
       for x1 in range(25)
       for x2 in range(25)
       # Eliminiert Duplikate
       if x1 < x2
       for y1 in range(25)
       for y2 in range(25)
       # Eliminiert Duplikate
       if y1 < y2
       # Summe der beiden soll gleich sein
       if x1**3 + x2**3 == y1**3 + y2**3
       # Die Zahlen müssen sich unterscheiden
       if (x1,x2) < (y1,y2)
       ][0]
