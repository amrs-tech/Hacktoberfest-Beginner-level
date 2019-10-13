#include <iostream>
using namespace std;

void Insertion_Sort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int value = arr[i];
        int hole = i;
        
        while(hole>0 && arr[hole-1]>value)
        {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
}

int main( )
{
    int n;
    cout<<"Enter number of Elements in the Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements of the Array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    Insertion_Sort(arr,n);
    
    cout<<"The Sorted Array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
