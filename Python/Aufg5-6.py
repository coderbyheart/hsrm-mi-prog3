#!/usr/bin/python
# -*- coding: utf-8 -*-

r = range(0, 101)
# Die ersten 10 Zahlen
print r[0:10]
# Die letzten 10 Zahlen
print r[-10:len(r)]
# Jeder 10. Zahl
print r[::10]
# Mittlere Zahl
print r[len(r)/2]
# Jede 3. Zahl, außer von den erstem vier und den letzten 5
print r[::3][5:-5]
