from random import *

def inp():
    n=int(input("Enter the no of random strings"))
    return(n)

def generate(n):
    for i in range(n):
        e1=randint(65,91)
        e2=randint(65,91)
        e3=randint(0,9)
        e4=randint(0,9)
        print(chr(e1),chr(e2),str(e3),str(e4))
l=inp()
generate(l)
