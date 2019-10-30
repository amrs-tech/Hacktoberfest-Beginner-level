from operator import itemgetter

def findMedian(arr, n):
	arr.sort()
	return arr[(n-1)/2]

def partition(arr, l, r, x):
	i=0
	for i in range(l,r+1):
		if arr[i] == x:
			break
	arr[r],arr[i]=arr[i], arr[r]
	i = l;
	for j in range(l,r):
		if arr[j] <= x:
			arr[j],arr[i]=arr[i], arr[j]
			i+=1
	arr[r],arr[i]=arr[i], arr[r]
	return i

def getmedian(wells, l, r, k):
	if k > 0 and k <= r-l+1:
		n = r-l+1
		median = ((n+4)/5)*[0]
		i=0
		if n >= 5:
			for i in range(0,n/5):
				#print i,
				median[i] = findMedian(wells[l+i*5:l+i*5+5], 5)
			print i
			i += 1
			#print("yes")
			#print(i)
			if i*5 < n:
				#print i,
				#print "No"
				median[i] = findMedian(wells[l+i*5:], n%5)
				i+=1
		else:
			median[i] = findMedian(wells[l+i*5:], n%5)
			i+=1
		print(median)
		if i == 1:
			medOfMed = median[i-1]
		else:
			medOfMed = getmedian(median, 0, i-1, i/2)
		pos = partition(wells, l, r, medOfMed)
		if pos-l == k-1:
			return wells[pos]
		if pos-l > k-1:
			return getmedian(wells, l, pos-1, k)
		return getmedian(wells, pos+1, r, k-pos+l-1)

if __name__ == '__main__':
	n = int(input())
	wells = []
	for i in range(0,n):
		
		wells.append(int(input()))
	print(wells)
	median = getmedian(wells, 0, n-1, (n+1)/2)
	print(median)
