# -*- coding: utf-8 -*-
# Module Set, Set.py

class Set(object):
    "Set-Klasse mit Python-Listen"

    def __init__(self):
        self.list = []

    def add(self, elem):
        "Hinzufügen eines Elements, wenn es noch nicht vorhanden ist."
        self.list.append(elem)
        self.list = sorted(self.list, lambda x,y: cmp(x, y))

    def union_update(self, seq):
        "Fügt alle Elemente einer Sequenz seq zur Menge hinzu."
        return

    def union(self, seq):
        "Gibt eine neue Menge zurück, die aus den Elementen in der Menge und in der Sequenz seq besteht."
        return

    def remove(self, elem):
        "Löschen eines Elements, wenn vorhanden"
        return

    def difference_update(self, seq):
        "Löschen aller Elemente in der Menge, die auch in der Sequenz seq sind."
        return

    def difference(self, seq):
        "Gibt eine neue Menge zurück, die aus den Elementen besteht, die in der Menge aber nicht in seq sind."
        return

    def clear(self):
        "Setze Menge auf leere Menge."
        return

    def size(self):
        "Gibt Anzahl der Elemente in der Menge zurück."
        return len(self.list)

    def __iter__(self):
        "Gibt einen Iterator über die Werte der Sequenz zurück."
        return self.list.__iter__();
