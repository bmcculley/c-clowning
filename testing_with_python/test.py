import cffi
import unittest
import importlib

class AddTest(unittest.TestCase):
    def test_addition(self):
        module = load('example')
        self.assertEqual(module.add(3,2), 3 + 2)

def load(filename):
    # load source code
    source = open(filename + '.c').read()
    includes = open(filename + '.h').read()
    
    # pass source code to CFFI
    ffibuilder = cffi.FFI()
    ffibuilder.cdef(includes)
    ffibuilder.set_source(filename + '_', source)
    ffibuilder.compile()
    
    # import and return resulting module
    module = importlib.import_module(filename + '_')
    return module.lib

if __name__ == '__main__':
	unittest.main()
