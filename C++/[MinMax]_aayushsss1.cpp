
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    int Ar[50];
    int temp,max,min;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        min=0;
        for(int j=0;j<n;j++)
            cin>>Ar[j];
        for(int j=0;j<n;j++)
        {
            min=j;
            for(int k=j+1;k<n;k++)
            {
                if(Ar[k]<Ar[min])
                    min=k;
            }
            temp=Ar[j];
            Ar[j]=Ar[min];
            Ar[min]=temp;
        }
        min=0;
        max=0;
        for(int j=0;j<n;j++)
        {
            if(j!=0)
                max+=Ar[j];
            if(j!=n-1)
                min+=Ar[j];
        }
        cout<<min<<" "<<max;
    }
}