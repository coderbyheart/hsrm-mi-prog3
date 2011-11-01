# -*- coding: utf-8 -*-
import menge
import unittest

reload(menge)

suite = unittest.TestLoader().loadTestsFromTestCase(SetTest)
unittest.TextTestRunner(verbosity=2).run(suite)

