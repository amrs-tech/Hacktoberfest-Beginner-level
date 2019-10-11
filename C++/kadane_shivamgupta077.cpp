/*
Problem Statement - Find the maximum sum contiguous subarray
Solution - Dynamic Programming
*/

#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    int maxSoFar = arr[0], curMax = arr[0];
    for(int i = 1;i<n;i++){
        curMax = max(curMax + arr[i], arr[i]);
        maxSoFar = max(maxSoFar,curMax);
    }
    return maxSoFar;
}

int main(){

    int n;   //Size of array
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];    //Array elements
    }

    cout<<kadane(arr,n)<<endl;

}
