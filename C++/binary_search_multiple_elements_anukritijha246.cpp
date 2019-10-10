#include <iostream>

using namespace std;
int binarySearch(int arr[],int l,int r,int x)
{


    //Sorting the array in ascending order in order to use binary search 
    for(int i=0;i<r;i++)
    {       
        for( int j=i+1;j<r;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp  =arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    if(r>=l)
    {

        int mid=l+(r-1)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x)
        {
            return binarySearch(arr,l,mid-1,x);
        }
        else{
            return binarySearch(arr,mid+1,r,x);
        }
    }
    return -1;
}
int main()
{

    int i,n1,n2,arr[100],ar[100];
    cout<<"enter size of array\n";
    cin>>n1;
     cout<<"enter elements of array\n";
    for(i=0;i<n1;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter size of search array\n";
    cin>>n2;
   cout<<"enter elements of search array\n";
    for(i=0;i<n2;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<n2;i++)
    {
int result=binarySearch(arr,0,n1-1,ar[i]);
        if(result==-1)
        {cout<<"Element  not present\n";}
        else{cout<<"Element present at\n";
        cout<<result;
        cout<<"\n";}
    }
    return 0;
}
