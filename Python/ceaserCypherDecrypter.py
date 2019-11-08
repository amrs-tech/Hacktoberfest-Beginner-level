txt = input("Enter the encrypted text: ")
for n in range(1,27):
	x=[]
	for i in range(len(txt)):
		c = ord(txt[i]) +n
		if c<=122:
			x+=[chr(c)]
		else:
			x+=[chr(c - 26)]

	for i in x:
		print(i, end='')
	print()

