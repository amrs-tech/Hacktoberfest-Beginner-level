#encryption 1
istr=input("enter string to be encrypted")
for i in range(len(istr)):
	istr[i]=chr(ord(istr[i])+i)
print("encrypted string",istr)
