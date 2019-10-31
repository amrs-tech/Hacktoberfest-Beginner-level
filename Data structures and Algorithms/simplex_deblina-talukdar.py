#simplex method of lpp 
from __future__ import division
if __name__=='__main__':
	C=[5,3,0,0,0]
	Cb=[0,0,0]
	b=[2,10,12]
	mat=[[1,1,1,0,0],[5,2,0,1,0],[3,8,0,0,1]]
	minR=[0,0,0]
	Z=[0,0,0,0,0]
	diff=[0,0,0,0,0]
	r=3
	c=5
	z=0
	while 1:
		for i in range(0,c):
			s=0
			for j in range(0,r):
				s+=mat[j][i]*Cb[j]
			Z[i]=s
			diff[i]=C[i]-Z[i]
		ma=-100000000
		posC=-1
		for i in range(0,c):
			if diff[i]>ma:
				ma=diff[i]
				posC=i
		if ma<=0:
			break
		mi=1000000000
		posR=-1
		for i in range(0,r):
			if mat[i][posC]!=0:
				minR[i]=b[i]/mat[i][posC]
				if minR[i]<mi:
					mi=minR[i]
					posR=i
		Cb[posR]=C[posC]
		t=mat[posR][posC]
		for i in range(0,c):
			mat[posR][i]=mat[posR][i]/t

		b[posR]=b[posR]/t

		for i in range(0,r):
			if i!=posR:

				temp=mat[i][posC]
				for j in range(0,c):
					t1=mat[i][j]

					mat[i][j]=t1-temp*mat[posR][j]
				b[i]-=temp*b[posR]
		print("simplex matrix")
		for i in range(0,len(mat)):
			for j in range(0,len(mat[0])):
				print(mat[i][j]),
			print
		
		print
		print("b array = ",b)
		print
		print("Cj-Zj array = ",diff)
		print
		z+=1
	print("Z array = ",Z)
	print
	print("Cj-Zj array = ",diff)
	print
	print("Answer = ",b[0]*C[0]+0*C[1])
