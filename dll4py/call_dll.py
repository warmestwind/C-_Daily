#http://wolfprojects.altervista.org/articles/dll-in-c-for-python/
from ctypes import cdll
mydll = cdll.LoadLibrary('dll.dll')
print(mydll)
print(mydll.sum(1,2))
