#include<iostream>
	#include<vector>
    #include<algorithm>
	using namespace std;
	int main()
	{
		vector<int> v1,maxi;
        vector<int> a(5,0);
		int i,n,x,j,k,max;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x;
			v1.push_back(x);	
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<n;j++)
			{
			if((i+1)==v1[j])
				{
				a[i]++;	
				}
			}
		}
		
		//sort(a.begin(),a.end(),greater<int>());
        max=a[0];
        for(i=0;i<5;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
            }
        }
       
        
		for(i=0;i<5;i++)
		{
				
			if(max==a[i])
            {
               maxi.push_back(i+1);
               
            }
		}
		
		cout<<maxi.front();
	return 0;	
	}
