class ItemValue: 
    def __init__(self, wt, val, ind): 
        self.wt = wt 
        self.val = val 
        self.ind = ind 
        self.cost = val // wt 
  
    def __lt__(self, other): 
        return self.cost < other.cost 
  
 
      
    def getMaxValue(wt, val, capacity): 
          
        iVal = [] 
        for i in range(len(wt)): 
            iVal.append(ItemValue(wt[i], val[i], i)) 
  
        
        iVal.sort(reverse = True) 
  
        totalValue = 0
        for i in iVal: 
            curWt = int(i.wt) 
            curVal = int(i.val) 
            if capacity - curWt >= 0: 
		
                print(curWt)		
                capacity -= curWt 
                totalValue += curVal 
            else: 
		
		
                fraction = capacity / curWt 
                totalValue += curVal * fraction 
                capacity = int(capacity - (curWt * fraction)) 
                break
        return totalValue 
  

if __name__ == "__main__": 

    wt = [10, 40, 20, 30, 50, 90, 60, 50, 10, 80] 
    val = [60, 40, 100, 120, 30, 20, 50, 90, 80, 70] 
    capacity = 380
  
    maxValue = FractionalKnapSack.getMaxValue(wt, val, capacity) 
    print("Maximum value in Knapsack =", maxValue)
