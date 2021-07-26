import unittest
import myModule2
import random

class MyModuleTest(unittest.TestCase):
    def test_add(self):
        a = 5
        self.assertEqual(5, myModule2.c_add(2, 3))
        self.assertEqual(a, myModule2.c_add(2, 3))
    
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.makeSuite(MyModuleTest))
    return suite