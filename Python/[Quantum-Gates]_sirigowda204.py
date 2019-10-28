from [Quantum-Module]_sirigowda204 import *
import numpy as np
import math

#To check the validity of the qubit

def check_validity1(x):
    if(np.linalg.norm(qubit1,ord=2)==1:
        print("Qubit1 is valid")
    else:
        print("Qubit1 is invalid")
		
def check_validity2(x):
    if(np.linalg.norm(qubit2,ord=2)==1:
        print("Qubit2 is valid")
    else:
        print("Qubit2 is invalid")
		
def check_validity3(x):
    if(np.linalg.norm(qubit3,ord=2)==1:
        print("Qubit3 is valid")
    else:
        print("Qubit3 is invalid")
		
#Pauli gate application:

def pauli_x(x):
	x_gate=np.matmul(p_x,qubit1)
	print("Application of Pauli X gate: ",x_gate)
	return x_gate
	
def pauli_y(y):
	y_gate=np.matmul(p_y,qubit1)
	print("Application of Pauli Y gate: ",y_gate)
	return y_gate
	
def pauli_z(z):
	z_gate=np.matmul(p_z,qubit1)
	print("Application of Pauli Z gate: ",z_gate)
	return z_gate


#Hadamard gate Application:

def hadamard(h):
	h=np.matmul(hadamard,qubit1)
	print("Application of Hadamard gate: ",h)
	return h
	
#CNOT Gate:

def controlled_not(qubit1,qubit2):
	matrix=np.kron(qubit1,qubit2)
	cnot_gate=np.matmul(cnot,matrix)
	print("Application of Controlled Not gate: ",cnot_gate)
	return cnot_gate
	
#CCNOT:

def ccnot_gate(qubit1,qubit2,qubit3):
	matrix=np.kron(qubit1,qubit2)
	matrix1=np.kron(matrix,qubit3)
	ccnot=np.matmul(tof,matrix1)
	print('Application of CCNOT Gate: ',ccnot)
	return ccnot
	
#SWAP:

def swap_gate(qubit1,qubit2):
	matrix=np.kron(qubit1,qubit2)
	swap=np.matmul(s,matrix)
	print("On swapping: ",swap)
	return swap
	
alpha1 = float(input("Enter the first value of qubit1: "))
beta1 = float(input("Enter the second value of qubit1: "))
alpha2 = float(input("Enter the first value of qubit2: "))
beta2 = float(input("Enter the second value of qubit2: "))
alpha3 = float(input("Enter the first value of qubit1: "))
beta3 = float(input("Enter the second value of qubit1: "))
qubit1=np.array([[alpha1],[beta1]])
qubit2=np.array([[alpha2],[beta2])
qubit3=np.array([[alpha3],[beta3]])
check_validity1(qubit1)
check_validity2(qubit2)
check_validity3(qubit3)
pauli_x(qubit1)
pauli_y(qubit1)
pauli_z(qubit1)
hadamard(qubit1)
controlled_not(qubit1,qubit)
ccnot_gate(qubit1,qubit,qubit3)
swap_gate(qubit1,qubit2)