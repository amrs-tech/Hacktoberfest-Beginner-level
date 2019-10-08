/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h>  
using namespace std; 

int lis(vector<int> arr)  
{  
    int n=arr.size();
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    return *max_element(lis, lis+n); 
}  
    
int main()  
{  
    int n,k;
    cin>>n;
    vector<int> arr(n); 
    for(int i=0;i<n;i++)
    {
        cin>>k;
        arr[i]=k;
    }
    printf("Length of lis is %d\n", lis( arr) );  
    return 0;  
}