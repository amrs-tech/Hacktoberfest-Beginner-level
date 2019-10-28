Python 3.7.3 (v3.7.3:ef4ec6ed12, Mar 25 2019, 21:26:53) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> import numpy as np


#1) Intialising a qubit

def initialise_qubit(a, b):
    basis_0 = np.array([[a], [b]])
    print("Zero state qubit: \n", basis_0)
var = initialise_qubit(1, 0)


#2) Ket notation

def to_ket(x, y):
    ans = np.matrix([[alpha], [beta]])
    return ans
alpha = float(input("Enter the first value: "))
beta = float(input("Enter the second value: "))
psi = to_ket(alpha, beta)
print("Psi in ket form: \n", psi)


#3) Bra notation

def to_bra(x, y):
    ans = np.transpose(np.matrix([[alpha], [beta]]))
    return ans
alpha = float(input("Enter the first value: "))
beta = float(input("Enter the second value: "))
psi = to_bra([alpha], [beta])
print("Psi in bra form: \n", psi)


#4)To check the validity of the qubit

def check_validity(x, y):
    if (alpha ** 2) + (beta ** 2) == 1:
        print("Qubit is valid")
    else:
        print("Qubit is invalid")
alpha = float(input("Enter the first value: "))
beta = float(input("Enter the second value: "))
value = check_validity(alpha, beta)


#5)To find the inner product

def inner_product(alpha, beta):
    ans = alpha * alpha + beta * beta
    return ans


alpha = float(input("Enter the first value: "))
beta = float(input("Enter the second value: "))
result = inner_product(alpha, beta)
print("Inner product=", result)


#6)To construct a density matrix

def construct_density_matrix_single(state):
    if state == 1:
        ans = np.outer([1, 0], [1, 0])
        return ans
    else:
        ans = np.outer([0, 1], [0, 1])
        return ans
state = int(input('Enter the state of qubit(either 1 or 0): '))
result = construct_density_matrix_single(state)
print("Density matrix:\n", result)

#7)To contruct a standard basis
import numpy as np


def construct_standard_basis(no_qubits):
    print("Standard basis:")
    for i in range(0, (2 ** no_qubits) + 1):
        a = 1
        lst = []
        for j in range(0, ( no_qubits + 1)):
            if j == a:
                lst.append(1)
            else:
                lst.append(0)

        print(np.array(lst))


no_of_qubits = int(input("Enter the number of qubits: "))
construct_standard_basis(no_of_qubits)


#8) To combine multiple qubits

def combine_qubits(no_qubits):
    alpha1 = float(input("Enter the first value of qubit1: "))
    beta1 = float(input("Enter the second value of qubit1: "))
    alpha2 = float(input("Enter the first value of qubit2: "))
    beta2 = float(input("Enter the second value of qubit2: "))
    lst = list(np.outer([alpha1, beta1], [alpha2, beta2]))
    for i in range(0, no_qubits - 2):
        alpha = float(input("Enter the first value of qubit(x): "))
        beta = float(input("Enter the second value of qubit(x): "))
        lst = list(np.outer([lst], [alpha, beta]))
    print("result of combination: \n", np.array(lst))


no_of_qubits = int(input("Enter the no. of qubits: "))
combine_qubits(no_of_qubits)
