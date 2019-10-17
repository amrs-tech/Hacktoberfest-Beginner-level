# Python example to check if a class is 
# subclass of another 

class Base(object): 
	pass # Empty Class 

class Derived(Base): 
	pass # Empty Class 

# Driver Code 
print(issubclass(Derived, Base)) 
print(issubclass(Base, Derived)) 

d = Derived() 
b = Base() 

# b is not an instance of Derived 
print(isinstance(b, Derived)) 

# But d is an instance of Base 
print(isinstance(d, Base)) 
