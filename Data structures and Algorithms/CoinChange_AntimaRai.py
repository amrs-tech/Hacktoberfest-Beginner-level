print("Enter the cents for which you want change")
n=int(input())
names=["pennies","nickels","dimes","quarters"]
values=[50,25,5,1]
for i in range(0,len(values)):
    count=n/values[i]
    n=n-count*values[i]
    print(names[i]),           
    print(count)
