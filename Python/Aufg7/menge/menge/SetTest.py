# -*- coding: utf-8 -*-
# Module Set, Set.py

import unittest

class SetTest(unittest.TestCase):
    "Unit-Tests für die Set-Klasse"

    def setUp(self):
        self.set = set()
        self.Set = Set()

    def test_add(self):
        for el in ["a", "b", "c"]:
            self.assertTrue(self.set.add(el) == self.Set.add(el))
        self.assertEquals(self.Set.size(), 3)
        self.assertTrue(len(self.set) == self.Set.size())

    def test_iterator(self):
        for el in [100, 10, 1]:
            self.set.add(el)
            self.Set.add(el)
        n = 0
        for el in self.Set:            
            n += 1
        self.assertEquals(n, 3)
