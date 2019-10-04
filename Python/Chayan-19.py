# Python3 program to multiply two matrices. 
MAX = 100

# Function to print Matrix 
def printMatrix(M, rowSize, colSize) : 
	
	for i in range(rowSize) : 
		for j in range(colSize) : 
			print(M[i][j], end = " ") 

		print() 

# Function to multiply two matrices 
# A[][] and B[][] 
def multiplyMatrix(row1, col1, A, 
				row2, col2, B) : 
						
	# Matrix to store the result 
	C = [[0 for i in range(MAX)] 
			for j in range(MAX)] 

	# Check if multiplication is Possible 
	if (row2 != col1) : 
		print("Not Possible") 
		return
	
	# Multiply the two 
	for i in range(row1) : 
		for j in range(col2) : 
			C[i][j] = 0
			for k in range(row2) : 
				C[i][j] += A[i][k] * B[k][j]; 

	# Print the result 
	print("Resultant Matrix: ") 
	printMatrix(C, row1, col2) 

# Driver Code 
if __name__ == "__main__" : 

	A = [[0 for i in range(MAX)] 
			for j in range(MAX)] 
	B = [[0 for i in range(MAX)] 
			for j in range(MAX)] 

	# Read size of Matrix A from user 
	row1 = int(input("Enter the number of rows of First Matrix: ")) 
	col1 = int(input("Enter the number of columns of First Matrix: ")) 

	# Read the elements of Matrix A from user 
	print("Enter the elements of First Matrix: "); 
	for i in range(row1) : 
		for j in range(col1) : 
			A[i][j] = int(input("A[" + str(i) +
								"][" + str(j) + "]: ")) 

	# Read size of Matrix B from user 
	row2 = int(input("Enter the number of rows of Second Matrix: ")) 
	col2 = int(input("Enter the number of columns of Second Matrix: ")) 

	# Read the elements of Matrix B from user 
	print("Enter the elements of Second Matrix: "); 
	for i in range(row2) : 
		for j in range(col2) : 
			B[i][j] = int(input("B[" + str(i) +
								"][" + str(j) + "]: ")) 

	# Print the Matrix A 
	print("First Matrix: ") 
	printMatrix(A, row1, col1) 

	# Print the Matrix B 
	print("Second Matrix: ") 
	printMatrix(B, row2, col2) 

	# Find the product of the 2 matrices 
	multiplyMatrix(row1, col1, A, row2, col2, B) 

 
