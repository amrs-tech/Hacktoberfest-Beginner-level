if __name__=='__main__':
#The text
	txt=raw_input("Enter the text\n")
#the pattern to be searched
	ser=raw_input("Enter the pattern\n")
	l=len(ser)
	i=0
	num=0
	while i<l:
		t=ord(ser[i])
		print("t=",t)
		num=num*10+t
		i+=1
	print(num)
	l1=len(txt)
	i=0
	num1=0
	c=0
	while i<l:
		t=ord(txt[i])
		num1=num1*10+t
		i+=1
	if num==num1:
		print("index = ",0)
		c+=1
	i=0
	j=l
	k=0
	h=0
	mul=1
	while h<l-1:
		mul=mul*10
		h+=1
	while k<l1-l:
		tem=num1-ord(txt[i])*mul
		tem=tem*10+ord(txt[j])
		if tem==num:
			print("index = ",i+1)
			c+=1
		num1=tem
		i+=1
		j+=1
		k+=1
#the total occurences of the pattern
	print("total = ",c)
