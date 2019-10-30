import math
from operator import itemgetter
def dist(p1,p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)
def stripclosest(strip,d1):
    n=len(strip)
    d=d1
    min=float("inf")
    strip.sort(key=itemgetter(1))
    temp1=-1
    temp2=-1
    for i in range(0,n):
        for j in range(i+1,n):
            if(strip[j][1]-strip[i][1]>=d):
                break
            if(dist(strip[i],strip[j])<=d):
                temp1=strip[i]
                temp2=strip[j]
                d=dist(strip[i],strip[j])
    return temp1,temp2,d
    
def closest(points):
    n=len(points)
    if n<=3:
        min=float("inf")
        temp1=-1
        temp2=-1
        for i in range(0,n):
            for j in range(i+1,n):
                if dist(points[i],points[j])<min:
                    temp1=points[i]
                    temp2=points[j]
                    min=dist(points[i],points[j])
        return temp1,temp2,min
    mid=n/2
    midpoint=points[mid]
    temp11,temp12,d1=closest(points[:mid])
    temp21,temp22,d2=closest(points[mid:n])
    temp1=-1
    temp2=-1
    d=-1
    if d1<d2:
        temp1=temp11
        temp2=temp12
        d=d1
    else:
        temp1=temp21
        temp2=temp22
        d=d2
    strip=n*[[0,0]]
    j=0
    for i in range(0,n):
        if(abs(points[i][0]-midpoint[0]))<d:
            strip[j]=points[i]
            j=j+1
    temp31,temp32,d3=stripclosest(strip[:j],d)
    if d3<d:
        d=d3
        temp1=temp31
        temp2=temp32
    return temp1,temp2,d
n=int(input("Enter the no of points:\t"))
points=[]
for i in range(0,n):
    x=int(input("Enter the x coordinate of "+str(i+1)+" :\t"))
    y=int(input("Enter the y coordinate of "+str(i+1)+" :\t"))
    points.append([x,y])
points.sort(key=itemgetter(0))
p1,p2,d=closest(points)
print("The closest points are "+str(p1)+" and "+str(p2)+" .The distance between them is "+str(d)+" :\t")
