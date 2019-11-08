import numpy as np
import math 

#1) PAULI GATES
p_x=np.array([[0,1],[1,0]]) #Pauli-X
p_y=np.array([[0,-1j],[-1j,0]])  #Pauli-Y
p_z=np.array([[1,0],[0,-1]]) #Pauli-Z

#2)HADAMARD GATE
hadamard=(1/math.sqrt(2))*np.array([[1,1],[1,-1]])

#3)CONTROLLED NOT
cnot=np.array([[1,0,0,0],[0,1,0,0],[0,0,0,1],[0,0,1,0]])

#4)DOUBLE CONTROLLED NOT (CCNOT) OR TOFFOLI 
tof=np.array([[1,0,0,0,0,0,0,0],[0,1,0,0,0,0,0,0],[0,0,1,0,0,0,0,0],[0,0,0,1,0,0,0,0],[0,0,0,0,1,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,0,0,1,0],[0,0,0,0,0,0,1]])

#5)SWAP GATE
s=np.array([[1,0,0,0],[0,0,1,0],[0,1,0,0],[0,0,0,1]])