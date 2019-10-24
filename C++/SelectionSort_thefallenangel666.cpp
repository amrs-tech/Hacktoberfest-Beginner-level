#include <iostream>
using namespace std;

void Selection_Sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int iMin = i;
        //finding the min element
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[iMin])
            {
                //Updating the index of min element
                iMin = j;
            }
        }
        //swapping
        int temp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = temp;
    }
}

int main( )
{
    int n;
    cout<<"Enter numbber of Elements in the Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the Array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    Selection_Sort(arr,n);
    
    cout<<"The Sorted Array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    return 0;
}
