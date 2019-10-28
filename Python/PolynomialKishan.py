#Implement a Polynomial
n=int(input("Enter n"))
a=int(input("Enter coefficient"))
x=int(input("Enter x value"))
i=0; y=1
while i<n:
    y=y+a*(x**n+i)
    i+=1
print(y)