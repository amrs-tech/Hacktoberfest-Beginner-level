#Fibonacci Series
a=int(input("Enter no of values"))
i=0; sum1=0; sum2=1
while i<a:
    if(i<=1):
        sum3=i
    else:
        sum3=sum1+sum2
        sum1=sum2
        sum2=sum3
    print(sum3)
    i+=1
    
    