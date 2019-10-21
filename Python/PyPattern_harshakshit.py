# Python 3.x code to demonstrate star pattern 

# Function to demonstrate printing pattern of numbers 
def numpat(n): 
	
	# initialising starting number 
	num = 1

	# outer loop to handle number of rows 
	for i in range(0, n): 
	
		# re assigning num 
		num = 1
	
		# inner loop to handle number of columns 
			# values changing acc. to outer loop 
		for j in range(0, i+1): 
		
				# printing number 
			print(num, end=" ") 
		
			# incrementing number at each column 
			num = num + 1
	
		# ending line after each row 
		print("\r") 

# Driver code 
n = 5
numpat(n) 

rows = int(input("Enter the number of rows: "))
for i in range(1, rows+1):
    for j in range(1, i+1):
        print(j, end=" ")
        j+=1
    print("\r")    
    i+=1    
