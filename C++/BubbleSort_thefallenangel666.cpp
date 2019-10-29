#include <iostream>
using namespace std;

void Bubble_Sort(int arr[],int n)
{
    for(int k=0;k<n-1;k++)
    {
        int j=0,flag = 0;
        while(flag==0)
        {//if array is already sorted
            if (arr[j]<arr[j+1])
            {
                flag=0;
            }
            else
            {
                flag=1;
            }
            j++;

        }
        if (flag==1)
            break;
        for(int i=0;i<n-k-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                //Swap
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1;
            }
        }
        if(flag==0)
            break;
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

    Bubble_Sort(arr,n);

    cout<<"The Sorted Array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
